/*
 * Copyright (C) 2005 Paolo 'Blaisorblade' Giarrusso <blaisorblade@yahoo.it>
 * Licensed under the GPL
 */

#ifndef __UM_MALLOC_H__
#define __UM_MALLOC_H__

#include <generated/asm-offsets.h>

extern void *uml_kmalloc(int size, int flags);
extern void kfree(const void *ptr);

extern void *vmalloc(unsigned long size);
extern void vfree(void *ptr);

#endif /*                 */


