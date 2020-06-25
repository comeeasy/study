// ======================================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

// ======================================================================

void sort(void);

// ======================================================================

int main(void)
{
  int r1, r2;
  clock_t start, stop;
  float cpu;

  // Remove the file DICT_OUT if exists.
  r1 = system("rm -f " DICT_OUT);
  r1 = r1;			// to remove compiler warning when -Wall

  // Measure CPU time for executing sort().
  start = clock();
  sort();
  stop = clock();
  cpu = (float) (stop - start) / CLOCKS_PER_SEC;

  // Check if the file DICT_OUT is really sorted.
  r2 = system("diff " DICT_OUT " " DICT_SORT " > /dev/null");
  if (r2 == 0) {
    printf("Sort success!\n");
    printf("CPU time=%.3f secs\n", cpu);
    printf("Points=%d\n", (20 - (int) (cpu)) > 0 ? (20 - (int) (cpu)) : 0);
  } else {
    printf("Sort fail!\n");
    printf("CPU time=%.3f secs\n", cpu);
    printf("Points=0\n");
  }

  return EXIT_SUCCESS;
}

// ======================================================================
