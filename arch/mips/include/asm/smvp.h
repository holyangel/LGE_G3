#ifndef _ASM_SMVP_H
#define _ASM_SMVP_H

/*
                                                     
 */
struct task_struct;

extern void smvp_smp_setup(void);
extern void smvp_smp_finish(void);
extern void smvp_boot_secondary(int cpu, struct task_struct *t);
extern void smvp_init_secondary(void);
extern void smvp_smp_finish(void);
extern void smvp_cpus_done(void);
extern void smvp_prepare_cpus(unsigned int max_cpus);

/*                           */
extern void smvp_send_ipi(int cpu, unsigned int action);
#endif /*              */
