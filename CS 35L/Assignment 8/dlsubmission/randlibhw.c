#include "randlib.h"
#include <immintrin.h>


/* Initialize the hardware rand64 implementation.  */
__attribute__ ((__constructor__)) 
extern void
hardware_rand64_init (void)
{
}

/* Return a random value, using hardware operations.  */
static unsigned long long
hardware_rand64 (void)
{
  unsigned long long int x;
  while (! _rdrand64_step (&x))
    continue;
  return x;
}

extern unsigned long long
rand64(void)
{
  return hardware_rand64();
}

/* Finalize the hardware rand64 implementation.  */
__attribute__ ((__destructor__))
extern void
hardware_rand64_fini (void)
{
}
