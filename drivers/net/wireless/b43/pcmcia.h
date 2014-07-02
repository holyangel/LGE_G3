#ifndef B43_PCMCIA_H_
#define B43_PCMCIA_H_

#ifdef CONFIG_B43_PCMCIA

int b43_pcmcia_init(void);
void b43_pcmcia_exit(void);

#else /*                   */

static inline int b43_pcmcia_init(void)
{
	return 0;
}
static inline void b43_pcmcia_exit(void)
{
}

#endif /*                   */
#endif /*               */
