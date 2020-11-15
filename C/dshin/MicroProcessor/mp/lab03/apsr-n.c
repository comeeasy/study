// ======================================================================

#include "frdm_k64f.h"		// include for FRDM-K64F board

// ======================================================================

unsigned getNthBit(unsigned int apsr, int n) {
  int mask = 1 << n;
  return apsr & mask ? 1 : 0;
}

void apsr_print(unsigned int apsr) {
  printf("N=%d ", getNthBit(apsr, 31));
  printf("Z=%d ", getNthBit(apsr, 30));
  printf("C=%d ", getNthBit(apsr, 29));
  printf("V=%d ", getNthBit(apsr, 28));
  printf("Q=%d ", getNthBit(apsr, 27));
  printf("GE[3:0]=");
  for(int i=16; i<20; ++i) printf("%d", apsr, i);
  printf("\n");

  __asm("mov  r0, %0": :"r"(apsr));
  __asm("msr  apsr_nzcvq, r0");
}

// ======================================================================

int main(void)
{
  soc_init();			// initialize FRDM-K64F board

  printf("========================================\n");
  printf("setting APSR=0x00000000...\n");
  __asm("	ldr	r0, =#0x00000000");
  __asm("	msr	apsr_nzcvqg, r0");
  apsr_print(__get_APSR());	// print twice to check apsr is preserved
  apsr_print(__get_APSR());

  printf("========================================\n");
  printf("setting N=1 of APSR...\n");
  __asm("ldr  r1, =#0x00000000");
  __asm("ldr  r2, =#0x00000001");
  __asm("subs r0, r1, r2");

  apsr_print(__get_APSR());	// print twice to check apsr is preserved
  apsr_print(__get_APSR());
  printf("========================================\n");

  for (;;)			// waiting in an infinite loop
    ;

  return 0;
}

// ======================================================================
