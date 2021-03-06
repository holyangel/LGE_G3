/* MN10300 Atomic counter operations
 *
 * Copyright (C) 2007 Red Hat, Inc. All Rights Reserved.
 * Written by David Howells (dhowells@redhat.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public Licence
 * as published by the Free Software Foundation; either version
 * 2 of the Licence, or (at your option) any later version.
 */
#ifndef _ASM_ATOMIC_H
#define _ASM_ATOMIC_H

#include <asm/irqflags.h>
#include <asm/cmpxchg.h>

#ifndef CONFIG_SMP
#include <asm-generic/atomic.h>
#else

/*
                                                           
                          
 */

#define ATOMIC_INIT(i)	{ (i) }

#ifdef __KERNEL__

/* 
                                     
                               
  
                                                              
                                               
 */
#define atomic_read(v)	(ACCESS_ONCE((v)->counter))

/* 
                                   
                               
                     
  
                                                                   
                                               
 */
#define atomic_set(v, i) (((v)->counter) = (i))

/* 
                                                     
                           
                               
  
                                                  
                                                                        
 */
static inline int atomic_add_return(int i, atomic_t *v)
{
	int retval;
#ifdef CONFIG_SMP
	int status;

	asm volatile(
		"1:	mov	%4,(_AAR,%3)	\n"
		"	mov	(_ADR,%3),%1	\n"
		"	add	%5,%1		\n"
		"	mov	%1,(_ADR,%3)	\n"
		"	mov	(_ADR,%3),%0	\n"	/*       */
		"	mov	(_ASR,%3),%0	\n"
		"	or	%0,%0		\n"
		"	bne	1b		\n"
		: "=&r"(status), "=&r"(retval), "=m"(v->counter)
		: "a"(ATOMIC_OPS_BASE_ADDR), "r"(&v->counter), "r"(i)
		: "memory", "cc");

#else
	unsigned long flags;

	flags = arch_local_cli_save();
	retval = v->counter;
	retval += i;
	v->counter = retval;
	arch_local_irq_restore(flags);
#endif
	return retval;
}

/* 
                                                            
                                
                               
  
                                                         
                                                                        
 */
static inline int atomic_sub_return(int i, atomic_t *v)
{
	int retval;
#ifdef CONFIG_SMP
	int status;

	asm volatile(
		"1:	mov	%4,(_AAR,%3)	\n"
		"	mov	(_ADR,%3),%1	\n"
		"	sub	%5,%1		\n"
		"	mov	%1,(_ADR,%3)	\n"
		"	mov	(_ADR,%3),%0	\n"	/*       */
		"	mov	(_ASR,%3),%0	\n"
		"	or	%0,%0		\n"
		"	bne	1b		\n"
		: "=&r"(status), "=&r"(retval), "=m"(v->counter)
		: "a"(ATOMIC_OPS_BASE_ADDR), "r"(&v->counter), "r"(i)
		: "memory", "cc");

#else
	unsigned long flags;
	flags = arch_local_cli_save();
	retval = v->counter;
	retval -= i;
	v->counter = retval;
	arch_local_irq_restore(flags);
#endif
	return retval;
}

static inline int atomic_add_negative(int i, atomic_t *v)
{
	return atomic_add_return(i, v) < 0;
}

static inline void atomic_add(int i, atomic_t *v)
{
	atomic_add_return(i, v);
}

static inline void atomic_sub(int i, atomic_t *v)
{
	atomic_sub_return(i, v);
}

static inline void atomic_inc(atomic_t *v)
{
	atomic_add_return(1, v);
}

static inline void atomic_dec(atomic_t *v)
{
	atomic_sub_return(1, v);
}

#define atomic_dec_return(v)		atomic_sub_return(1, (v))
#define atomic_inc_return(v)		atomic_add_return(1, (v))

#define atomic_sub_and_test(i, v)	(atomic_sub_return((i), (v)) == 0)
#define atomic_dec_and_test(v)		(atomic_sub_return(1, (v)) == 0)
#define atomic_inc_and_test(v)		(atomic_add_return(1, (v)) == 0)

#define __atomic_add_unless(v, a, u)				\
({								\
	int c, old;						\
	c = atomic_read(v);					\
	while (c != (u) && (old = atomic_cmpxchg((v), c, c + (a))) != c) \
		c = old;					\
	c;							\
})

#define atomic_xchg(ptr, v)		(xchg(&(ptr)->counter, (v)))
#define atomic_cmpxchg(v, old, new)	(cmpxchg(&((v)->counter), (old), (new)))

/* 
                                                      
                                        
                                
  
                                                                         
 */
static inline void atomic_clear_mask(unsigned long mask, unsigned long *addr)
{
#ifdef CONFIG_SMP
	int status;

	asm volatile(
		"1:	mov	%3,(_AAR,%2)	\n"
		"	mov	(_ADR,%2),%0	\n"
		"	and	%4,%0		\n"
		"	mov	%0,(_ADR,%2)	\n"
		"	mov	(_ADR,%2),%0	\n"	/*       */
		"	mov	(_ASR,%2),%0	\n"
		"	or	%0,%0		\n"
		"	bne	1b		\n"
		: "=&r"(status), "=m"(*addr)
		: "a"(ATOMIC_OPS_BASE_ADDR), "r"(addr), "r"(~mask)
		: "memory", "cc");
#else
	unsigned long flags;

	mask = ~mask;
	flags = arch_local_cli_save();
	*addr &= mask;
	arch_local_irq_restore(flags);
#endif
}

/* 
                                                  
                                    
                                
  
                                                                       
 */
static inline void atomic_set_mask(unsigned long mask, unsigned long *addr)
{
#ifdef CONFIG_SMP
	int status;

	asm volatile(
		"1:	mov	%3,(_AAR,%2)	\n"
		"	mov	(_ADR,%2),%0	\n"
		"	or	%4,%0		\n"
		"	mov	%0,(_ADR,%2)	\n"
		"	mov	(_ADR,%2),%0	\n"	/*       */
		"	mov	(_ASR,%2),%0	\n"
		"	or	%0,%0		\n"
		"	bne	1b		\n"
		: "=&r"(status), "=m"(*addr)
		: "a"(ATOMIC_OPS_BASE_ADDR), "r"(addr), "r"(mask)
		: "memory", "cc");
#else
	unsigned long flags;

	flags = arch_local_cli_save();
	*addr |= mask;
	arch_local_irq_restore(flags);
#endif
}

/*                                                         */
#define smp_mb__before_atomic_dec()	barrier()
#define smp_mb__after_atomic_dec()	barrier()
#define smp_mb__before_atomic_inc()	barrier()
#define smp_mb__after_atomic_inc()	barrier()

#endif /*            */
#endif /*            */
#endif /*               */
