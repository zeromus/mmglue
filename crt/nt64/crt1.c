#ifdef LIBC_STATIC
#define __external_routine
#else
#define __external_routine __attribute__((dllimport))
#endif

#include "psxglue.h"

/**
 * options: posix session, fallback terminal emulator
 * x86_64-nt64-midipix-gcc --target-help | grep -A2 posix
**/

static const int __disabled = 0;
extern const int __crtopt_posix  __attribute((weak,alias("__disabled")));
extern const int __crtopt_ttydbg __attribute((weak,alias("__disabled")));

int main();

__external_routine
__psx_init_routine __psx_init;

__external_routine
void __libc_entry_routine(void *,void *,int);

void _start(void)
{
	__libc_entry_routine(
		main,
		__psx_init,
		__crtopt_posix | __crtopt_ttydbg);
}

