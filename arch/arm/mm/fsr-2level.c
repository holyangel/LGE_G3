static struct fsr_info fsr_info[] = {
	/*
                                                                 
                                         
  */
	{ do_bad,		SIGSEGV, 0,		"vector exception"		   },
	{ do_bad,		SIGBUS,	 BUS_ADRALN,	"alignment exception"		   },
	{ do_bad,		SIGKILL, 0,		"terminal exception"		   },
	{ do_bad,		SIGBUS,	 BUS_ADRALN,	"alignment exception"		   },
	{ do_bad,		SIGBUS,	 0,		"external abort on linefetch"	   },
	{ do_translation_fault,	SIGSEGV, SEGV_MAPERR,	"section translation fault"	   },
	{ do_bad,		SIGBUS,	 0,		"external abort on linefetch"	   },
	{ do_page_fault,	SIGSEGV, SEGV_MAPERR,	"page translation fault"	   },
	{ do_bad,		SIGBUS,	 0,		"external abort on non-linefetch"  },
	{ do_bad,		SIGSEGV, SEGV_ACCERR,	"section domain fault"		   },
	{ do_bad,		SIGBUS,	 0,		"external abort on non-linefetch"  },
	{ do_bad,		SIGSEGV, SEGV_ACCERR,	"page domain fault"		   },
	{ do_bad,		SIGBUS,	 0,		"external abort on translation"	   },
	{ do_sect_fault,	SIGSEGV, SEGV_ACCERR,	"section permission fault"	   },
	{ do_bad,		SIGBUS,	 0,		"external abort on translation"	   },
	{ do_page_fault,	SIGSEGV, SEGV_ACCERR,	"page permission fault"		   },
	/*
                                                                    
                                                              
                                                       
  */
	{ do_bad,		SIGBUS,  0,		"unknown 16"			   },
	{ do_bad,		SIGBUS,  0,		"unknown 17"			   },
	{ do_bad,		SIGBUS,  0,		"unknown 18"			   },
	{ do_bad,		SIGBUS,  0,		"unknown 19"			   },
	{ do_bad,		SIGBUS,  0,		"lock abort"			   }, /*        */
	{ do_bad,		SIGBUS,  0,		"unknown 21"			   },
	{ do_imprecise_ext,	SIGBUS,  BUS_OBJERR,	"imprecise external abort"	   }, /*        */
	{ do_bad,		SIGBUS,  0,		"unknown 23"			   },
	{ do_bad,		SIGBUS,  0,		"dcache parity error"		   }, /*        */
	{ do_bad,		SIGBUS,  0,		"unknown 25"			   },
	{ do_bad,		SIGBUS,  0,		"unknown 26"			   },
	{ do_bad,		SIGBUS,  0,		"unknown 27"			   },
	{ do_bad,		SIGBUS,  0,		"unknown 28"			   },
	{ do_bad,		SIGBUS,  0,		"unknown 29"			   },
	{ do_bad,		SIGBUS,  0,		"unknown 30"			   },
	{ do_bad,		SIGBUS,  0,		"unknown 31"			   },
};

static struct fsr_info ifsr_info[] = {
	{ do_bad,		SIGBUS,  0,		"unknown 0"			   },
	{ do_bad,		SIGBUS,  0,		"unknown 1"			   },
	{ do_bad,		SIGBUS,  0,		"debug event"			   },
	{ do_bad,		SIGSEGV, SEGV_ACCERR,	"section access flag fault"	   },
	{ do_bad,		SIGBUS,  0,		"unknown 4"			   },
	{ do_translation_fault,	SIGSEGV, SEGV_MAPERR,	"section translation fault"	   },
	{ do_bad,		SIGSEGV, SEGV_ACCERR,	"page access flag fault"	   },
	{ do_page_fault,	SIGSEGV, SEGV_MAPERR,	"page translation fault"	   },
	{ do_bad,		SIGBUS,	 0,		"external abort on non-linefetch"  },
	{ do_bad,		SIGSEGV, SEGV_ACCERR,	"section domain fault"		   },
	{ do_bad,		SIGBUS,  0,		"unknown 10"			   },
	{ do_bad,		SIGSEGV, SEGV_ACCERR,	"page domain fault"		   },
	{ do_bad,		SIGBUS,	 0,		"external abort on translation"	   },
	{ do_sect_fault,	SIGSEGV, SEGV_ACCERR,	"section permission fault"	   },
	{ do_bad,		SIGBUS,	 0,		"external abort on translation"	   },
	{ do_page_fault,	SIGSEGV, SEGV_ACCERR,	"page permission fault"		   },
	{ do_bad,		SIGBUS,  0,		"unknown 16"			   },
	{ do_bad,		SIGBUS,  0,		"unknown 17"			   },
	{ do_bad,		SIGBUS,  0,		"unknown 18"			   },
	{ do_bad,		SIGBUS,  0,		"unknown 19"			   },
	{ do_bad,		SIGBUS,  0,		"unknown 20"			   },
	{ do_bad,		SIGBUS,  0,		"unknown 21"			   },
	{ do_bad,		SIGBUS,  0,		"unknown 22"			   },
	{ do_bad,		SIGBUS,  0,		"unknown 23"			   },
	{ do_bad,		SIGBUS,  0,		"unknown 24"			   },
	{ do_bad,		SIGBUS,  0,		"unknown 25"			   },
	{ do_bad,		SIGBUS,  0,		"unknown 26"			   },
	{ do_bad,		SIGBUS,  0,		"unknown 27"			   },
	{ do_bad,		SIGBUS,  0,		"unknown 28"			   },
	{ do_bad,		SIGBUS,  0,		"unknown 29"			   },
	{ do_bad,		SIGBUS,  0,		"unknown 30"			   },
	{ do_bad,		SIGBUS,  0,		"unknown 31"			   },
};
