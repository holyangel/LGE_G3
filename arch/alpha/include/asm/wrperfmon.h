/*
                                                         
 */

#ifndef __ALPHA_WRPERFMON_H
#define __ALPHA_WRPERFMON_H

/*                                                */
#define PERFMON_CMD_DISABLE 0
#define PERFMON_CMD_ENABLE 1
#define PERFMON_CMD_DESIRED_EVENTS 2
#define PERFMON_CMD_LOGGING_OPTIONS 3
/*                                           */
#define PERFMON_CMD_INT_FREQ 4
#define PERFMON_CMD_ENABLE_CLEAR 7
/*                                               */
#define PERFMON_CMD_READ 5
#define PERFMON_CMD_WRITE 6
/*                                              */
#define PERFMON_CMD_ENABLE_WRITE 7
/*                                               */
#define PERFMON_CMD_I_STAT 8
#define PERFMON_CMD_PMPC 9


/*                         */
#define EV5_PCTR_0 (1UL<<0)
#define EV5_PCTR_1 (1UL<<1)
#define EV5_PCTR_2 (1UL<<2)

#define EV5_PCTR_0_COUNT_SHIFT 48
#define EV5_PCTR_1_COUNT_SHIFT 32
#define EV5_PCTR_2_COUNT_SHIFT 16

#define EV5_PCTR_0_COUNT_MASK 0xffffUL
#define EV5_PCTR_1_COUNT_MASK 0xffffUL
#define EV5_PCTR_2_COUNT_MASK 0x3fffUL

/*              */
#define EV6_PCTR_0 (1UL<<0)
#define EV6_PCTR_1 (1UL<<1)

#define EV6_PCTR_0_COUNT_SHIFT 28
#define EV6_PCTR_1_COUNT_SHIFT 6

#define EV6_PCTR_0_COUNT_MASK 0xfffffUL
#define EV6_PCTR_1_COUNT_MASK 0xfffffUL

/*                                */
#define EV67_PCTR_0 (1UL<<0)
#define EV67_PCTR_1 (1UL<<1)

#define EV67_PCTR_0_COUNT_SHIFT 28
#define EV67_PCTR_1_COUNT_SHIFT 6

#define EV67_PCTR_0_COUNT_MASK 0xfffffUL
#define EV67_PCTR_1_COUNT_MASK 0xfffffUL


/*
                                                                            
                                                                      
                                           
 */
#define EV6_PCTR_0_EVENT_MASK 0x10UL
#define EV6_PCTR_1_EVENT_MASK 0x0fUL

/*            */
#define EV6_PCTR_0_CYCLES (0UL << 4)
#define EV6_PCTR_0_INSTRUCTIONS (1UL << 4)

#define EV6_PCTR_1_CYCLES 0
#define EV6_PCTR_1_BRANCHES 1
#define EV6_PCTR_1_BRANCH_MISPREDICTS 2
#define EV6_PCTR_1_DTB_SINGLE_MISSES 3
#define EV6_PCTR_1_DTB_DOUBLE_MISSES 4
#define EV6_PCTR_1_ITB_MISSES 5
#define EV6_PCTR_1_UNALIGNED_TRAPS 6
#define EV6_PCTR_1_REPLY_TRAPS 7

/*                                                              */
#define EV67_PCTR_MODE_MASK 0x10UL
#define EV67_PCTR_EVENT_MASK 0x0CUL

#define EV67_PCTR_MODE_PROFILEME (1UL<<4)
#define EV67_PCTR_MODE_AGGREGATE (0UL<<4)

#define EV67_PCTR_INSTR_CYCLES (0UL<<2)
#define EV67_PCTR_CYCLES_UNDEF (1UL<<2)
#define EV67_PCTR_INSTR_BCACHEMISS (2UL<<2)
#define EV67_PCTR_CYCLES_MBOX (3UL<<2)

#endif
