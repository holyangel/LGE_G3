/*
 * linux/arch/unicore32/mm/mmu.c
 *
 * Code specific to PKUnity SoC and UniCore ISA
 *
 * Copyright (C) 2001-2010 GUAN Xue-tao
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/init.h>
#include <linux/mman.h>
#include <linux/nodemask.h>
#include <linux/memblock.h>
#include <linux/fs.h>
#include <linux/bootmem.h>
#include <linux/io.h>

#include <asm/cputype.h>
#include <asm/sections.h>
#include <asm/setup.h>
#include <asm/sizes.h>
#include <asm/tlb.h>
#include <asm/memblock.h>

#include <mach/map.h>

#include "mm.h"

/*
                                                     
                                 
 */
struct page *empty_zero_page;
EXPORT_SYMBOL(empty_zero_page);

/*
                                                 
 */
pmd_t *top_pmd;

pgprot_t pgprot_user;
EXPORT_SYMBOL(pgprot_user);

pgprot_t pgprot_kernel;
EXPORT_SYMBOL(pgprot_kernel);

static int __init noalign_setup(char *__unused)
{
	cr_alignment &= ~CR_A;
	cr_no_alignment &= ~CR_A;
	set_cr(cr_alignment);
	return 1;
}
__setup("noalign", noalign_setup);

void adjust_cr(unsigned long mask, unsigned long set)
{
	unsigned long flags;

	mask &= ~CR_A;

	set &= mask;

	local_irq_save(flags);

	cr_no_alignment = (cr_no_alignment & ~mask) | set;
	cr_alignment = (cr_alignment & ~mask) | set;

	set_cr((get_cr() & ~mask) | set);

	local_irq_restore(flags);
}

struct map_desc {
	unsigned long virtual;
	unsigned long pfn;
	unsigned long length;
	unsigned int type;
};

#define PROT_PTE_DEVICE		(PTE_PRESENT | PTE_YOUNG |	\
				PTE_DIRTY | PTE_READ | PTE_WRITE)
#define PROT_SECT_DEVICE	(PMD_TYPE_SECT | PMD_PRESENT |	\
				PMD_SECT_READ | PMD_SECT_WRITE)

static struct mem_type mem_types[] = {
	[MT_DEVICE] = {		  /*                  */
		.prot_pte	= PROT_PTE_DEVICE,
		.prot_l1	= PMD_TYPE_TABLE | PMD_PRESENT,
		.prot_sect	= PROT_SECT_DEVICE,
	},
	/*
                                           
                                                  
  */
	[MT_KUSER] = {
		.prot_pte  = PTE_PRESENT | PTE_YOUNG | PTE_DIRTY |
				PTE_CACHEABLE | PTE_READ | PTE_EXEC,
		.prot_l1   = PMD_TYPE_TABLE | PMD_PRESENT,
		.prot_sect = PROT_SECT_DEVICE,
	},
	[MT_HIGH_VECTORS] = {
		.prot_pte  = PTE_PRESENT | PTE_YOUNG | PTE_DIRTY |
				PTE_CACHEABLE | PTE_READ | PTE_WRITE |
				PTE_EXEC,
		.prot_l1   = PMD_TYPE_TABLE | PMD_PRESENT,
	},
	[MT_MEMORY] = {
		.prot_pte  = PTE_PRESENT | PTE_YOUNG | PTE_DIRTY |
				PTE_WRITE | PTE_EXEC,
		.prot_l1   = PMD_TYPE_TABLE | PMD_PRESENT,
		.prot_sect = PMD_TYPE_SECT | PMD_PRESENT | PMD_SECT_CACHEABLE |
				PMD_SECT_READ | PMD_SECT_WRITE | PMD_SECT_EXEC,
	},
	[MT_ROM] = {
		.prot_sect = PMD_TYPE_SECT | PMD_PRESENT | PMD_SECT_CACHEABLE |
				PMD_SECT_READ,
	},
};

const struct mem_type *get_mem_type(unsigned int type)
{
	return type < ARRAY_SIZE(mem_types) ? &mem_types[type] : NULL;
}
EXPORT_SYMBOL(get_mem_type);

/*
                                                              
 */
static void __init build_mem_type_table(void)
{
	pgprot_user   = __pgprot(PTE_PRESENT | PTE_YOUNG | PTE_CACHEABLE);
	pgprot_kernel = __pgprot(PTE_PRESENT | PTE_YOUNG |
				 PTE_DIRTY | PTE_READ | PTE_WRITE |
				 PTE_EXEC | PTE_CACHEABLE);
}

#define vectors_base()	(vectors_high() ? 0xffff0000 : 0)

static void __init *early_alloc(unsigned long sz)
{
	void *ptr = __va(memblock_alloc(sz, sz));
	memset(ptr, 0, sz);
	return ptr;
}

static pte_t * __init early_pte_alloc(pmd_t *pmd, unsigned long addr,
		unsigned long prot)
{
	if (pmd_none(*pmd)) {
		pte_t *pte = early_alloc(PTRS_PER_PTE * sizeof(pte_t));
		__pmd_populate(pmd, __pa(pte) | prot);
	}
	BUG_ON(pmd_bad(*pmd));
	return pte_offset_kernel(pmd, addr);
}

static void __init alloc_init_pte(pmd_t *pmd, unsigned long addr,
				  unsigned long end, unsigned long pfn,
				  const struct mem_type *type)
{
	pte_t *pte = early_pte_alloc(pmd, addr, type->prot_l1);
	do {
		set_pte(pte, pfn_pte(pfn, __pgprot(type->prot_pte)));
		pfn++;
	} while (pte++, addr += PAGE_SIZE, addr != end);
}

static void __init alloc_init_section(pgd_t *pgd, unsigned long addr,
				      unsigned long end, unsigned long phys,
				      const struct mem_type *type)
{
	pmd_t *pmd = pmd_offset((pud_t *)pgd, addr);

	/*
                                                                  
                          
  */
	if (((addr | end | phys) & ~SECTION_MASK) == 0) {
		pmd_t *p = pmd;

		do {
			set_pmd(pmd, __pmd(phys | type->prot_sect));
			phys += SECTION_SIZE;
		} while (pmd++, addr += SECTION_SIZE, addr != end);

		flush_pmd_entry(p);
	} else {
		/*
                                                    
                           
   */
		alloc_init_pte(pmd, addr, end, __phys_to_pfn(phys), type);
	}
}

/*
                                                      
                                                     
                                                       
                                                   
 */
static void __init create_mapping(struct map_desc *md)
{
	unsigned long phys, addr, length, end;
	const struct mem_type *type;
	pgd_t *pgd;

	if (md->virtual != vectors_base() && md->virtual < TASK_SIZE) {
		printk(KERN_WARNING "BUG: not creating mapping for "
		       "0x%08llx at 0x%08lx in user region\n",
		       __pfn_to_phys((u64)md->pfn), md->virtual);
		return;
	}

	if ((md->type == MT_DEVICE || md->type == MT_ROM) &&
	    md->virtual >= PAGE_OFFSET && md->virtual < VMALLOC_END) {
		printk(KERN_WARNING "BUG: mapping for 0x%08llx at 0x%08lx "
		       "overlaps vmalloc space\n",
		       __pfn_to_phys((u64)md->pfn), md->virtual);
	}

	type = &mem_types[md->type];

	addr = md->virtual & PAGE_MASK;
	phys = (unsigned long)__pfn_to_phys(md->pfn);
	length = PAGE_ALIGN(md->length + (md->virtual & ~PAGE_MASK));

	if (type->prot_l1 == 0 && ((addr | phys | length) & ~SECTION_MASK)) {
		printk(KERN_WARNING "BUG: map for 0x%08lx at 0x%08lx can not "
		       "be mapped using pages, ignoring.\n",
		       __pfn_to_phys(md->pfn), addr);
		return;
	}

	pgd = pgd_offset_k(addr);
	end = addr + length;
	do {
		unsigned long next = pgd_addr_end(addr, end);

		alloc_init_section(pgd, addr, next, phys, type);

		phys += next - addr;
		addr = next;
	} while (pgd++, addr != end);
}

static void * __initdata vmalloc_min = (void *)(VMALLOC_END - SZ_128M);

/*
                                                            
                                                                
                              
 */
static int __init early_vmalloc(char *arg)
{
	unsigned long vmalloc_reserve = memparse(arg, NULL);

	if (vmalloc_reserve < SZ_16M) {
		vmalloc_reserve = SZ_16M;
		printk(KERN_WARNING
			"vmalloc area too small, limiting to %luMB\n",
			vmalloc_reserve >> 20);
	}

	if (vmalloc_reserve > VMALLOC_END - (PAGE_OFFSET + SZ_32M)) {
		vmalloc_reserve = VMALLOC_END - (PAGE_OFFSET + SZ_32M);
		printk(KERN_WARNING
			"vmalloc area is too big, limiting to %luMB\n",
			vmalloc_reserve >> 20);
	}

	vmalloc_min = (void *)(VMALLOC_END - vmalloc_reserve);
	return 0;
}
early_param("vmalloc", early_vmalloc);

static phys_addr_t lowmem_limit __initdata = SZ_1G;

static void __init sanity_check_meminfo(void)
{
	int i, j;

	lowmem_limit = __pa(vmalloc_min - 1) + 1;
	memblock_set_current_limit(lowmem_limit);

	for (i = 0, j = 0; i < meminfo.nr_banks; i++) {
		struct membank *bank = &meminfo.bank[j];
		*bank = meminfo.bank[i];
		j++;
	}
	meminfo.nr_banks = j;
}

static inline void prepare_page_table(void)
{
	unsigned long addr;
	phys_addr_t end;

	/*
                                                      
  */
	for (addr = 0; addr < MODULES_VADDR; addr += PGDIR_SIZE)
		pmd_clear(pmd_off_k(addr));

	for ( ; addr < PAGE_OFFSET; addr += PGDIR_SIZE)
		pmd_clear(pmd_off_k(addr));

	/*
                                              
  */
	end = memblock.memory.regions[0].base + memblock.memory.regions[0].size;
	if (end >= lowmem_limit)
		end = lowmem_limit;

	/*
                                                                 
                                                     
  */
	for (addr = __phys_to_virt(end);
	     addr < VMALLOC_END; addr += PGDIR_SIZE)
		pmd_clear(pmd_off_k(addr));
}

/*
                                        
 */
void __init uc32_mm_memblock_reserve(void)
{
	/*
                                                       
                              
  */
	memblock_reserve(__pa(swapper_pg_dir), PTRS_PER_PGD * sizeof(pgd_t));
}

/*
                                                                          
                                                                        
                                                                        
                                                                       
                                                                        
 */
static void __init devicemaps_init(void)
{
	struct map_desc map;
	unsigned long addr;
	void *vectors;

	/*
                                   
  */
	vectors = early_alloc(PAGE_SIZE);

	for (addr = VMALLOC_END; addr; addr += PGDIR_SIZE)
		pmd_clear(pmd_off_k(addr));

	/*
                                                                
                                                                 
                                                        
  */
	map.pfn = __phys_to_pfn(virt_to_phys(vectors));
	map.virtual = VECTORS_BASE;
	map.length = PAGE_SIZE;
	map.type = MT_HIGH_VECTORS;
	create_mapping(&map);

	/*
                                                      
                                                       
  */
	map.pfn = __phys_to_pfn(virt_to_phys(vectors));
	map.virtual = KUSER_VECPAGE_BASE;
	map.length = PAGE_SIZE;
	map.type = MT_KUSER;
	create_mapping(&map);

	/*
                                                              
                                                                 
                                                                  
                                                                 
  */
	local_flush_tlb_all();
	flush_cache_all();
}

static void __init map_lowmem(void)
{
	struct memblock_region *reg;

	/*                                  */
	for_each_memblock(memory, reg) {
		phys_addr_t start = reg->base;
		phys_addr_t end = start + reg->size;
		struct map_desc map;

		if (end > lowmem_limit)
			end = lowmem_limit;
		if (start >= end)
			break;

		map.pfn = __phys_to_pfn(start);
		map.virtual = __phys_to_virt(start);
		map.length = end - start;
		map.type = MT_MEMORY;

		create_mapping(&map);
	}
}

/*
                                                                     
                                                                 
 */
void __init paging_init(void)
{
	void *zero_page;

	build_mem_type_table();
	sanity_check_meminfo();
	prepare_page_table();
	map_lowmem();
	devicemaps_init();

	top_pmd = pmd_off_k(0xffff0000);

	/*                         */
	zero_page = early_alloc(PAGE_SIZE);

	bootmem_init();

	empty_zero_page = virt_to_page(zero_page);
	__flush_dcache_page(NULL, empty_zero_page);
}

/*
                                                                     
                                                                       
                                   
 */
void setup_mm_for_reboot(char mode)
{
	unsigned long base_pmdval;
	pgd_t *pgd;
	int i;

	/*
                                                                       
                                                                      
               
  */
	pgd = current->active_mm->pgd;

	base_pmdval = PMD_SECT_WRITE | PMD_SECT_READ | PMD_TYPE_SECT;

	for (i = 0; i < FIRST_USER_PGD_NR + USER_PTRS_PER_PGD; i++, pgd++) {
		unsigned long pmdval = (i << PGDIR_SHIFT) | base_pmdval;
		pmd_t *pmd;

		pmd = pmd_off(pgd, i << PGDIR_SHIFT);
		set_pmd(pmd, __pmd(pmdval));
		flush_pmd_entry(pmd);
	}

	local_flush_tlb_all();
}

/*
                                                                        
                                                                       
                                       
  
                                                                    
                                                            
                                          
                                                               
                                                                 
  
                                       
 */
void update_mmu_cache(struct vm_area_struct *vma, unsigned long addr,
	pte_t *ptep)
{
	unsigned long pfn = pte_pfn(*ptep);
	struct address_space *mapping;
	struct page *page;

	if (!pfn_valid(pfn))
		return;

	/*
                                                             
                                                         
  */
	page = pfn_to_page(pfn);
	if (page == ZERO_PAGE(0))
		return;

	mapping = page_mapping(page);
	if (!test_and_set_bit(PG_dcache_clean, &page->flags))
		__flush_dcache_page(mapping, page);
	if (mapping)
		if (vma->vm_flags & VM_EXEC)
			__flush_icache_all();
}
