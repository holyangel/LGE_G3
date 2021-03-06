/* sections.h: linkage layout variables
 *
 * Copyright (C) 2004 Red Hat, Inc. All Rights Reserved.
 * Written by David Howells (dhowells@redhat.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version
 * 2 of the License, or (at your option) any later version.
 */

#ifndef _ASM_SECTIONS_H
#define _ASM_SECTIONS_H

#ifndef __ASSEMBLY__

#include <linux/types.h>
#include <asm-generic/sections.h>

#ifdef __KERNEL__

/*
                                                                                                  
                                                             
 */
#define __nongpreldata	__attribute__((section(".data")))
#define __nongprelbss	__attribute__((section(".bss")))

/*
                 
 */
extern const void __kernel_image_start, __kernel_image_end, __page_offset;

extern unsigned long __nongprelbss memory_start;
extern unsigned long __nongprelbss memory_end;
extern unsigned long __nongprelbss rom_length;

/*                                     */
static inline int is_in_rom(unsigned long addr)
{
	return 0; /*                          */
}

#endif
#endif
#endif /*                 */
