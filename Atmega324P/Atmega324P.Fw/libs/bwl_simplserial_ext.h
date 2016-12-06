
//legacy for old bootloader
#if defined(__AVR_ATmega88PA__)
#define GOTO_PROG 	{boot_rww_enable_safe(); asm("ldi r30,0"); asm("ldi r31,0"); asm("ijmp");};
#define GOTO_BOOT 	asm volatile("rjmp 0x1800"::);
#endif

//legacy for old bootloader
#if  defined(__AVR_ATmega168PA__)
#define GOTO_PROG 	asm volatile("jmp 0x0000"::);
#define GOTO_BOOT 	asm volatile("jmp 0x3800"::);
#endif

#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega328__)
#define GOTO_PROG 	asm volatile("jmp 0x0000"::);
#define GOTO_BOOT 	asm volatile("jmp 0x7000"::);
#endif

#if defined(__AVR_ATmega324PA__) || defined(__AVR_ATmega324P__) || defined(__AVR_ATmega324A__)
#define GOTO_PROG 	asm volatile("jmp 0x0000"::);
#define GOTO_BOOT 	asm volatile("jmp 0x7000"::);
#endif

#if defined(__AVR_ATmega2560__)
#define GOTO_PROG 	asm volatile("jmp 0x00000"::);
#define GOTO_BOOT 	asm volatile("jmp 0x3F000"::);
#endif