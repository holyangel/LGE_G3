#ifndef _SH_CACHECTL_H
#define _SH_CACHECTL_H

/*                                              */

#define CACHEFLUSH_D_INVAL	0x1	/*                                 */
#define CACHEFLUSH_D_WB		0x2	/*                                 */
#define CACHEFLUSH_D_PURGE	0x3	/*                          */

#define CACHEFLUSH_I		0x4

/*
                                     
 */
#define ICACHE	CACHEFLUSH_I		/*                         */
#define DCACHE	CACHEFLUSH_D_PURGE	/*                                */
#define BCACHE	(ICACHE|DCACHE)		/*                   */

#endif /*                */
