/*
 * Copyright 2007-2009 Analog Devices Inc.
 *
 * Licensed under the GPL-2 or later.
 */

#ifndef _BF548_IRQ_H_
#define _BF548_IRQ_H_

#include <mach-common/irq.h>

#define NR_PERI_INTS		(3 * 32)

#define IRQ_PLL_WAKEUP		BFIN_IRQ(0)	/*                      */
#define IRQ_DMAC0_ERROR		BFIN_IRQ(1)	/*                        */
#define IRQ_EPPI0_ERROR		BFIN_IRQ(2)	/*                       */
#define IRQ_SPORT0_ERROR	BFIN_IRQ(3)	/*                        */
#define IRQ_SPORT1_ERROR	BFIN_IRQ(4)	/*                        */
#define IRQ_SPI0_ERROR		BFIN_IRQ(5)	/*                              */
#define IRQ_UART0_ERROR		BFIN_IRQ(6)	/*                               */
#define IRQ_RTC			BFIN_IRQ(7)	/*               */
#define IRQ_EPPI0		BFIN_IRQ(8)	/*                         */
#define IRQ_SPORT0_RX		BFIN_IRQ(9)	/*                            */
#define IRQ_SPORT0_TX		BFIN_IRQ(10)	/*                            */
#define IRQ_SPORT1_RX		BFIN_IRQ(11)	/*                            */
#define IRQ_SPORT1_TX		BFIN_IRQ(12)	/*                            */
#define IRQ_SPI0		BFIN_IRQ(13)	/*                       */
#define IRQ_UART0_RX		BFIN_IRQ(14)	/*                           */
#define IRQ_UART0_TX		BFIN_IRQ(15)	/*                           */
#define IRQ_TIMER8		BFIN_IRQ(16)	/*                   */
#define IRQ_TIMER9		BFIN_IRQ(17)	/*                   */
#define IRQ_TIMER10		BFIN_IRQ(18)	/*                    */
#define IRQ_PINT0		BFIN_IRQ(19)	/*                 */
#define IRQ_PINT1		BFIN_IRQ(20)	/*                 */
#define IRQ_MDMAS0		BFIN_IRQ(21)	/*                         */
#define IRQ_MDMAS1		BFIN_IRQ(22)	/*                         */
#define IRQ_WATCH		BFIN_IRQ(23)	/*                    */
#define IRQ_DMAC1_ERROR		BFIN_IRQ(24)	/*                                */
#define IRQ_SPORT2_ERROR	BFIN_IRQ(25)	/*                        */
#define IRQ_SPORT3_ERROR	BFIN_IRQ(26)	/*                        */
#define IRQ_MXVR_DATA		BFIN_IRQ(27)	/*                     */
#define IRQ_SPI1_ERROR		BFIN_IRQ(28)	/*                               */
#define IRQ_SPI2_ERROR		BFIN_IRQ(29)	/*                               */
#define IRQ_UART1_ERROR		BFIN_IRQ(30)	/*                                */
#define IRQ_UART2_ERROR		BFIN_IRQ(31)	/*                                */
#define IRQ_CAN0_ERROR		BFIN_IRQ(32)	/*                               */
#define IRQ_SPORT2_RX		BFIN_IRQ(33)	/*                             */
#define IRQ_SPORT2_TX		BFIN_IRQ(34)	/*                             */
#define IRQ_SPORT3_RX		BFIN_IRQ(35)	/*                             */
#define IRQ_SPORT3_TX		BFIN_IRQ(36)	/*                             */
#define IRQ_EPPI1		BFIN_IRQ(37)	/*                        */
#define IRQ_EPPI2		BFIN_IRQ(38)	/*                        */
#define IRQ_SPI1		BFIN_IRQ(39)	/*                       */
#define IRQ_SPI2		BFIN_IRQ(40)	/*                        */
#define IRQ_UART1_RX		BFIN_IRQ(41)	/*                           */
#define IRQ_UART1_TX		BFIN_IRQ(42)	/*                           */
#define IRQ_ATAPI_RX		BFIN_IRQ(43)	/*                            */
#define IRQ_ATAPI_TX		BFIN_IRQ(44)	/*                            */
#define IRQ_TWI0		BFIN_IRQ(45)	/*                */
#define IRQ_TWI1		BFIN_IRQ(46)	/*                */
#define IRQ_CAN0_RX		BFIN_IRQ(47)	/*                        */
#define IRQ_CAN0_TX		BFIN_IRQ(48)	/*                         */
#define IRQ_MDMAS2		BFIN_IRQ(49)	/*                         */
#define IRQ_MDMAS3		BFIN_IRQ(50)	/*                         */
#define IRQ_MXVR_ERROR		BFIN_IRQ(51)	/*                               */
#define IRQ_MXVR_MSG		BFIN_IRQ(52)	/*                        */
#define IRQ_MXVR_PKT		BFIN_IRQ(53)	/*                       */
#define IRQ_EPPI1_ERROR		BFIN_IRQ(54)	/*                       */
#define IRQ_EPPI2_ERROR		BFIN_IRQ(55)	/*                       */
#define IRQ_UART3_ERROR		BFIN_IRQ(56)	/*                                */
#define IRQ_HOST_ERROR		BFIN_IRQ(57)	/*                               */
#define IRQ_PIXC_ERROR		BFIN_IRQ(59)	/*                               */
#define IRQ_NFC_ERROR		BFIN_IRQ(60)	/*                     */
#define IRQ_ATAPI_ERROR		BFIN_IRQ(61)	/*                       */
#define IRQ_CAN1_ERROR		BFIN_IRQ(62)	/*                               */
#define IRQ_HS_DMA_ERROR	BFIN_IRQ(63)	/*                                */
#define IRQ_PIXC_IN0		BFIN_IRQ(64)	/*                            */
#define IRQ_PIXC_IN1		BFIN_IRQ(65)	/*                            */
#define IRQ_PIXC_OUT		BFIN_IRQ(66)	/*                            */
#define IRQ_SDH			BFIN_IRQ(67)	/*                           */
#define IRQ_CNT			BFIN_IRQ(68)	/*               */
#define IRQ_KEY			BFIN_IRQ(69)	/*               */
#define IRQ_CAN1_RX		BFIN_IRQ(70)	/*                   */
#define IRQ_CAN1_TX		BFIN_IRQ(71)	/*                   */
#define IRQ_SDH_MASK0		BFIN_IRQ(72)	/*                      */
#define IRQ_SDH_MASK1		BFIN_IRQ(73)	/*                      */
#define IRQ_USB_INT0		BFIN_IRQ(75)	/*                    */
#define IRQ_USB_INT1		BFIN_IRQ(76)	/*                    */
#define IRQ_USB_INT2		BFIN_IRQ(77)	/*                    */
#define IRQ_USB_DMA		BFIN_IRQ(78)	/*                   */
#define IRQ_OPTSEC		BFIN_IRQ(79)	/*                  */
#define IRQ_TIMER0		BFIN_IRQ(86)	/*                   */
#define IRQ_TIMER1		BFIN_IRQ(87)	/*                   */
#define IRQ_TIMER2		BFIN_IRQ(88)	/*                   */
#define IRQ_TIMER3		BFIN_IRQ(89)	/*                   */
#define IRQ_TIMER4		BFIN_IRQ(90)	/*                   */
#define IRQ_TIMER5		BFIN_IRQ(91)	/*                   */
#define IRQ_TIMER6		BFIN_IRQ(92)	/*                   */
#define IRQ_TIMER7		BFIN_IRQ(93)	/*                   */
#define IRQ_PINT2		BFIN_IRQ(94)	/*                 */
#define IRQ_PINT3		BFIN_IRQ(95)	/*                 */

#define SYS_IRQS		IRQ_PINT3

#define BFIN_PA_IRQ(x)		((x) + SYS_IRQS + 1)
#define IRQ_PA0			BFIN_PA_IRQ(0)
#define IRQ_PA1			BFIN_PA_IRQ(1)
#define IRQ_PA2			BFIN_PA_IRQ(2)
#define IRQ_PA3			BFIN_PA_IRQ(3)
#define IRQ_PA4			BFIN_PA_IRQ(4)
#define IRQ_PA5			BFIN_PA_IRQ(5)
#define IRQ_PA6			BFIN_PA_IRQ(6)
#define IRQ_PA7			BFIN_PA_IRQ(7)
#define IRQ_PA8			BFIN_PA_IRQ(8)
#define IRQ_PA9			BFIN_PA_IRQ(9)
#define IRQ_PA10		BFIN_PA_IRQ(10)
#define IRQ_PA11		BFIN_PA_IRQ(11)
#define IRQ_PA12		BFIN_PA_IRQ(12)
#define IRQ_PA13		BFIN_PA_IRQ(13)
#define IRQ_PA14		BFIN_PA_IRQ(14)
#define IRQ_PA15		BFIN_PA_IRQ(15)

#define BFIN_PB_IRQ(x)		((x) + IRQ_PA15 + 1)
#define IRQ_PB0			BFIN_PB_IRQ(0)
#define IRQ_PB1			BFIN_PB_IRQ(1)
#define IRQ_PB2			BFIN_PB_IRQ(2)
#define IRQ_PB3			BFIN_PB_IRQ(3)
#define IRQ_PB4			BFIN_PB_IRQ(4)
#define IRQ_PB5			BFIN_PB_IRQ(5)
#define IRQ_PB6			BFIN_PB_IRQ(6)
#define IRQ_PB7			BFIN_PB_IRQ(7)
#define IRQ_PB8			BFIN_PB_IRQ(8)
#define IRQ_PB9			BFIN_PB_IRQ(9)
#define IRQ_PB10		BFIN_PB_IRQ(10)
#define IRQ_PB11		BFIN_PB_IRQ(11)
#define IRQ_PB12		BFIN_PB_IRQ(12)
#define IRQ_PB13		BFIN_PB_IRQ(13)
#define IRQ_PB14		BFIN_PB_IRQ(14)
#define IRQ_PB15		BFIN_PB_IRQ(15)		/*     */

#define BFIN_PC_IRQ(x)		((x) + IRQ_PB15 + 1)
#define IRQ_PC0			BFIN_PC_IRQ(0)
#define IRQ_PC1			BFIN_PC_IRQ(1)
#define IRQ_PC2			BFIN_PC_IRQ(2)
#define IRQ_PC3			BFIN_PC_IRQ(3)
#define IRQ_PC4			BFIN_PC_IRQ(4)
#define IRQ_PC5			BFIN_PC_IRQ(5)
#define IRQ_PC6			BFIN_PC_IRQ(6)
#define IRQ_PC7			BFIN_PC_IRQ(7)
#define IRQ_PC8			BFIN_PC_IRQ(8)
#define IRQ_PC9			BFIN_PC_IRQ(9)
#define IRQ_PC10		BFIN_PC_IRQ(10)
#define IRQ_PC11		BFIN_PC_IRQ(11)
#define IRQ_PC12		BFIN_PC_IRQ(12)
#define IRQ_PC13		BFIN_PC_IRQ(13)
#define IRQ_PC14		BFIN_PC_IRQ(14)		/*     */
#define IRQ_PC15		BFIN_PC_IRQ(15)		/*     */

#define BFIN_PD_IRQ(x)		((x) + IRQ_PC15 + 1)
#define IRQ_PD0			BFIN_PD_IRQ(0)
#define IRQ_PD1			BFIN_PD_IRQ(1)
#define IRQ_PD2			BFIN_PD_IRQ(2)
#define IRQ_PD3			BFIN_PD_IRQ(3)
#define IRQ_PD4			BFIN_PD_IRQ(4)
#define IRQ_PD5			BFIN_PD_IRQ(5)
#define IRQ_PD6			BFIN_PD_IRQ(6)
#define IRQ_PD7			BFIN_PD_IRQ(7)
#define IRQ_PD8			BFIN_PD_IRQ(8)
#define IRQ_PD9			BFIN_PD_IRQ(9)
#define IRQ_PD10		BFIN_PD_IRQ(10)
#define IRQ_PD11		BFIN_PD_IRQ(11)
#define IRQ_PD12		BFIN_PD_IRQ(12)
#define IRQ_PD13		BFIN_PD_IRQ(13)
#define IRQ_PD14		BFIN_PD_IRQ(14)
#define IRQ_PD15		BFIN_PD_IRQ(15)

#define BFIN_PE_IRQ(x)		((x) + IRQ_PD15 + 1)
#define IRQ_PE0			BFIN_PE_IRQ(0)
#define IRQ_PE1			BFIN_PE_IRQ(1)
#define IRQ_PE2			BFIN_PE_IRQ(2)
#define IRQ_PE3			BFIN_PE_IRQ(3)
#define IRQ_PE4			BFIN_PE_IRQ(4)
#define IRQ_PE5			BFIN_PE_IRQ(5)
#define IRQ_PE6			BFIN_PE_IRQ(6)
#define IRQ_PE7			BFIN_PE_IRQ(7)
#define IRQ_PE8			BFIN_PE_IRQ(8)
#define IRQ_PE9			BFIN_PE_IRQ(9)
#define IRQ_PE10		BFIN_PE_IRQ(10)
#define IRQ_PE11		BFIN_PE_IRQ(11)
#define IRQ_PE12		BFIN_PE_IRQ(12)
#define IRQ_PE13		BFIN_PE_IRQ(13)
#define IRQ_PE14		BFIN_PE_IRQ(14)
#define IRQ_PE15		BFIN_PE_IRQ(15)

#define BFIN_PF_IRQ(x)		((x) + IRQ_PE15 + 1)
#define IRQ_PF0			BFIN_PF_IRQ(0)
#define IRQ_PF1			BFIN_PF_IRQ(1)
#define IRQ_PF2			BFIN_PF_IRQ(2)
#define IRQ_PF3			BFIN_PF_IRQ(3)
#define IRQ_PF4			BFIN_PF_IRQ(4)
#define IRQ_PF5			BFIN_PF_IRQ(5)
#define IRQ_PF6			BFIN_PF_IRQ(6)
#define IRQ_PF7			BFIN_PF_IRQ(7)
#define IRQ_PF8			BFIN_PF_IRQ(8)
#define IRQ_PF9			BFIN_PF_IRQ(9)
#define IRQ_PF10		BFIN_PF_IRQ(10)
#define IRQ_PF11		BFIN_PF_IRQ(11)
#define IRQ_PF12		BFIN_PF_IRQ(12)
#define IRQ_PF13		BFIN_PF_IRQ(13)
#define IRQ_PF14		BFIN_PF_IRQ(14)
#define IRQ_PF15		BFIN_PF_IRQ(15)

#define BFIN_PG_IRQ(x)		((x) + IRQ_PF15 + 1)
#define IRQ_PG0			BFIN_PG_IRQ(0)
#define IRQ_PG1			BFIN_PG_IRQ(1)
#define IRQ_PG2			BFIN_PG_IRQ(2)
#define IRQ_PG3			BFIN_PG_IRQ(3)
#define IRQ_PG4			BFIN_PG_IRQ(4)
#define IRQ_PG5			BFIN_PG_IRQ(5)
#define IRQ_PG6			BFIN_PG_IRQ(6)
#define IRQ_PG7			BFIN_PG_IRQ(7)
#define IRQ_PG8			BFIN_PG_IRQ(8)
#define IRQ_PG9			BFIN_PG_IRQ(9)
#define IRQ_PG10		BFIN_PG_IRQ(10)
#define IRQ_PG11		BFIN_PG_IRQ(11)
#define IRQ_PG12		BFIN_PG_IRQ(12)
#define IRQ_PG13		BFIN_PG_IRQ(13)
#define IRQ_PG14		BFIN_PG_IRQ(14)
#define IRQ_PG15		BFIN_PG_IRQ(15)

#define BFIN_PH_IRQ(x)		((x) + IRQ_PG15 + 1)
#define IRQ_PH0			BFIN_PH_IRQ(0)
#define IRQ_PH1			BFIN_PH_IRQ(1)
#define IRQ_PH2			BFIN_PH_IRQ(2)
#define IRQ_PH3			BFIN_PH_IRQ(3)
#define IRQ_PH4			BFIN_PH_IRQ(4)
#define IRQ_PH5			BFIN_PH_IRQ(5)
#define IRQ_PH6			BFIN_PH_IRQ(6)
#define IRQ_PH7			BFIN_PH_IRQ(7)
#define IRQ_PH8			BFIN_PH_IRQ(8)
#define IRQ_PH9			BFIN_PH_IRQ(9)
#define IRQ_PH10		BFIN_PH_IRQ(10)
#define IRQ_PH11		BFIN_PH_IRQ(11)
#define IRQ_PH12		BFIN_PH_IRQ(12)
#define IRQ_PH13		BFIN_PH_IRQ(13)
#define IRQ_PH14		BFIN_PH_IRQ(14)		/*     */
#define IRQ_PH15		BFIN_PH_IRQ(15)		/*     */

#define BFIN_PI_IRQ(x)		((x) + IRQ_PH15 + 1)
#define IRQ_PI0			BFIN_PI_IRQ(0)
#define IRQ_PI1			BFIN_PI_IRQ(1)
#define IRQ_PI2			BFIN_PI_IRQ(2)
#define IRQ_PI3			BFIN_PI_IRQ(3)
#define IRQ_PI4			BFIN_PI_IRQ(4)
#define IRQ_PI5			BFIN_PI_IRQ(5)
#define IRQ_PI6			BFIN_PI_IRQ(6)
#define IRQ_PI7			BFIN_PI_IRQ(7)
#define IRQ_PI8			BFIN_PI_IRQ(8)
#define IRQ_PI9			BFIN_PI_IRQ(9)
#define IRQ_PI10		BFIN_PI_IRQ(10)
#define IRQ_PI11		BFIN_PI_IRQ(11)
#define IRQ_PI12		BFIN_PI_IRQ(12)
#define IRQ_PI13		BFIN_PI_IRQ(13)
#define IRQ_PI14		BFIN_PI_IRQ(14)
#define IRQ_PI15		BFIN_PI_IRQ(15)

#define BFIN_PJ_IRQ(x)		((x) + IRQ_PI15 + 1)
#define IRQ_PJ0			BFIN_PJ_IRQ(0)
#define IRQ_PJ1			BFIN_PJ_IRQ(1)
#define IRQ_PJ2			BFIN_PJ_IRQ(2)
#define IRQ_PJ3			BFIN_PJ_IRQ(3)
#define IRQ_PJ4			BFIN_PJ_IRQ(4)
#define IRQ_PJ5			BFIN_PJ_IRQ(5)
#define IRQ_PJ6			BFIN_PJ_IRQ(6)
#define IRQ_PJ7			BFIN_PJ_IRQ(7)
#define IRQ_PJ8			BFIN_PJ_IRQ(8)
#define IRQ_PJ9			BFIN_PJ_IRQ(9)
#define IRQ_PJ10		BFIN_PJ_IRQ(10)
#define IRQ_PJ11		BFIN_PJ_IRQ(11)
#define IRQ_PJ12		BFIN_PJ_IRQ(12)
#define IRQ_PJ13		BFIN_PJ_IRQ(13)
#define IRQ_PJ14		BFIN_PJ_IRQ(14)		/*     */
#define IRQ_PJ15		BFIN_PJ_IRQ(15)		/*     */

#define GPIO_IRQ_BASE		IRQ_PA0

#define NR_MACH_IRQS		(IRQ_PJ15 + 1)

/*                                              */

#define IRQ_DMAC0_ERR		IRQ_DMAC0_ERROR
#define IRQ_EPPI0_ERR		IRQ_EPPI0_ERROR
#define IRQ_SPORT0_ERR		IRQ_SPORT0_ERROR
#define IRQ_SPORT1_ERR		IRQ_SPORT1_ERROR
#define IRQ_SPI0_ERR		IRQ_SPI0_ERROR
#define IRQ_UART0_ERR		IRQ_UART0_ERROR
#define IRQ_DMAC1_ERR		IRQ_DMAC1_ERROR
#define IRQ_SPORT2_ERR		IRQ_SPORT2_ERROR
#define IRQ_SPORT3_ERR		IRQ_SPORT3_ERROR
#define IRQ_SPI1_ERR		IRQ_SPI1_ERROR
#define IRQ_SPI2_ERR		IRQ_SPI2_ERROR
#define IRQ_UART1_ERR		IRQ_UART1_ERROR
#define IRQ_UART2_ERR		IRQ_UART2_ERROR
#define IRQ_CAN0_ERR		IRQ_CAN0_ERROR
#define IRQ_MXVR_ERR		IRQ_MXVR_ERROR
#define IRQ_EPPI1_ERR		IRQ_EPPI1_ERROR
#define IRQ_EPPI2_ERR		IRQ_EPPI2_ERROR
#define IRQ_UART3_ERR		IRQ_UART3_ERROR
#define IRQ_HOST_ERR		IRQ_HOST_ERROR
#define IRQ_PIXC_ERR		IRQ_PIXC_ERROR
#define IRQ_NFC_ERR		IRQ_NFC_ERROR
#define IRQ_ATAPI_ERR		IRQ_ATAPI_ERROR
#define IRQ_CAN1_ERR		IRQ_CAN1_ERROR
#define IRQ_HS_DMA_ERR		IRQ_HS_DMA_ERROR

/*                 */
#define IRQ_PLL_WAKEUP_POS	0
#define IRQ_DMAC0_ERR_POS	4
#define IRQ_EPPI0_ERR_POS	8
#define IRQ_SPORT0_ERR_POS	12
#define IRQ_SPORT1_ERR_POS	16
#define IRQ_SPI0_ERR_POS	20
#define IRQ_UART0_ERR_POS	24
#define IRQ_RTC_POS		28

/*                 */
#define IRQ_EPPI0_POS		0
#define IRQ_SPORT0_RX_POS	4
#define IRQ_SPORT0_TX_POS	8
#define IRQ_SPORT1_RX_POS	12
#define IRQ_SPORT1_TX_POS	16
#define IRQ_SPI0_POS		20
#define IRQ_UART0_RX_POS	24
#define IRQ_UART0_TX_POS	28

/*                 */
#define IRQ_TIMER8_POS		0
#define IRQ_TIMER9_POS		4
#define IRQ_TIMER10_POS		8
#define IRQ_PINT0_POS		12
#define IRQ_PINT1_POS		16
#define IRQ_MDMAS0_POS		20
#define IRQ_MDMAS1_POS		24
#define IRQ_WATCH_POS		28

/*                 */
#define IRQ_DMAC1_ERR_POS	0
#define IRQ_SPORT2_ERR_POS	4
#define IRQ_SPORT3_ERR_POS	8
#define IRQ_MXVR_DATA_POS	12
#define IRQ_SPI1_ERR_POS	16
#define IRQ_SPI2_ERR_POS	20
#define IRQ_UART1_ERR_POS	24
#define IRQ_UART2_ERR_POS	28

/*                 */
#define IRQ_CAN0_ERR_POS	0
#define IRQ_SPORT2_RX_POS	4
#define IRQ_UART2_RX_POS	4
#define IRQ_SPORT2_TX_POS	8
#define IRQ_UART2_TX_POS	8
#define IRQ_SPORT3_RX_POS	12
#define IRQ_UART3_RX_POS	12
#define IRQ_SPORT3_TX_POS	16
#define IRQ_UART3_TX_POS	16
#define IRQ_EPPI1_POS		20
#define IRQ_EPPI2_POS		24
#define IRQ_SPI1_POS		28

/*                 */
#define IRQ_SPI2_POS		0
#define IRQ_UART1_RX_POS	4
#define IRQ_UART1_TX_POS	8
#define IRQ_ATAPI_RX_POS	12
#define IRQ_ATAPI_TX_POS	16
#define IRQ_TWI0_POS		20
#define IRQ_TWI1_POS		24
#define IRQ_CAN0_RX_POS		28

/*                 */
#define IRQ_CAN0_TX_POS		0
#define IRQ_MDMAS2_POS		4
#define IRQ_MDMAS3_POS		8
#define IRQ_MXVR_ERR_POS	12
#define IRQ_MXVR_MSG_POS	16
#define IRQ_MXVR_PKT_POS	20
#define IRQ_EPPI1_ERR_POS	24
#define IRQ_EPPI2_ERR_POS	28

/*                 */
#define IRQ_UART3_ERR_POS	0
#define IRQ_HOST_ERR_POS	4
#define IRQ_PIXC_ERR_POS	12
#define IRQ_NFC_ERR_POS		16
#define IRQ_ATAPI_ERR_POS	20
#define IRQ_CAN1_ERR_POS	24
#define IRQ_HS_DMA_ERR_POS	28

/*                 */
#define IRQ_PIXC_IN0_POS	0
#define IRQ_PIXC_IN1_POS	4
#define IRQ_PIXC_OUT_POS	8
#define IRQ_SDH_POS		12
#define IRQ_CNT_POS		16
#define IRQ_KEY_POS		20
#define IRQ_CAN1_RX_POS		24
#define IRQ_CAN1_TX_POS		28

/*                 */
#define IRQ_SDH_MASK0_POS	0
#define IRQ_SDH_MASK1_POS	4
#define IRQ_USB_INT0_POS	12
#define IRQ_USB_INT1_POS	16
#define IRQ_USB_INT2_POS	20
#define IRQ_USB_DMA_POS		24
#define IRQ_OTPSEC_POS		28

/*                  */
#define IRQ_TIMER0_POS		24
#define IRQ_TIMER1_POS		28

/*                  */
#define IRQ_TIMER2_POS		0
#define IRQ_TIMER3_POS		4
#define IRQ_TIMER4_POS		8
#define IRQ_TIMER5_POS		12
#define IRQ_TIMER6_POS		16
#define IRQ_TIMER7_POS		20
#define IRQ_PINT2_POS		24
#define IRQ_PINT3_POS		28

#ifndef __ASSEMBLY__
#include <linux/types.h>

/*
                             
 */
struct bfin_pint_regs {
	u32 mask_set;
	u32 mask_clear;
	u32 request;
	u32 assign;
	u32 edge_set;
	u32 edge_clear;
	u32 invert_set;
	u32 invert_clear;
	u32 pinstate;
	u32 latch;
	u32 __pad0[2];
};

#endif

#endif
