/*                                                                          */

/*
 * m52xxacr.h -- ColdFire version 2 core cache support
 *
 * (C) Copyright 2010, Greg Ungerer <gerg@snapgear.com>
 */

/*                                                                          */
#ifndef m52xxacr_h
#define m52xxacr_h
/*                                                                          */

/*
                                                                    
                                                                    
                                                                    
                                                                     
                                                                         
                                                                           
                                                   
 */

/*
                                           
 */
#define CACR_CENB	0x80000000	/*              */
#define CACR_CDPI	0x10000000	/*                                */
#define CACR_CFRZ	0x08000000	/*                   */
#define CACR_CINV	0x01000000	/*                  */
#define CACR_DISI	0x00800000	/*                           */
#define CACR_DISD	0x00400000	/*                    */
#define CACR_INVI	0x00200000	/*                              */
#define CACR_INVD	0x00100000	/*                       */
#define CACR_CEIB	0x00000400	/*                                */
#define CACR_DCM	0x00000200	/*                    */
#define CACR_DBWE	0x00000100	/*                       */
#define CACR_DWP	0x00000020	/*                  */
#define CACR_EUSP	0x00000010	/*                         */

/*
                                            
 */
#define ACR_BASE_POS	24		/*                             */
#define ACR_MASK_POS	16		/*                            */
#define ACR_ENABLE	0x00008000	/*                 */
#define ACR_USER	0x00000000	/*                          */
#define ACR_SUPER	0x00002000	/*                              */
#define ACR_ANY		0x00004000	/*                       */
#define ACR_CENB	0x00000000	/*                           */
#define ACR_CDIS	0x00000040	/*                            */
#define ACR_BWE		0x00000020	/*                      */
#define ACR_WPROTECT	0x00000004	/*                      */

/*
                                                                           
                                                                       
                                                                        
              
 */
#if defined(CONFIG_CACHE_I)
#define CACHE_TYPE	(CACR_DISD + CACR_EUSP)
#define CACHE_INVTYPEI	0
#elif defined(CONFIG_CACHE_D)
#define CACHE_TYPE	(CACR_DISI + CACR_EUSP)
#define CACHE_INVTYPED	0
#elif defined(CONFIG_CACHE_BOTH)
#define CACHE_TYPE	CACR_EUSP
#define CACHE_INVTYPEI	CACR_INVI
#define CACHE_INVTYPED	CACR_INVD
#else
/*                                                                      */
#define CACHE_TYPE	0
#define CACHE_INVTYPEI	0
#endif

#define CACHE_INIT	(CACR_CINV + CACHE_TYPE)
#define CACHE_MODE	(CACR_CENB + CACHE_TYPE + CACR_DCM)

#define CACHE_INVALIDATE  (CACHE_MODE + CACR_CINV)
#if defined(CACHE_INVTYPEI)
#define CACHE_INVALIDATEI (CACHE_MODE + CACR_CINV + CACHE_INVTYPEI)
#endif
#if defined(CACHE_INVTYPED)
#define CACHE_INVALIDATED (CACHE_MODE + CACR_CINV + CACHE_INVTYPED)
#endif

#define ACR0_MODE	((CONFIG_RAMBASE & 0xff000000) + \
			 (0x000f0000) + \
			 (ACR_ENABLE + ACR_ANY + ACR_CENB + ACR_BWE))
#define ACR1_MODE	0

/*                                                                          */
#endif  /*            */
