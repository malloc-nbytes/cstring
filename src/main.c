#include <stdio.h>
#include <stdlib.h>
#include "cstring.h"

int main(void) {
  Cstring cs = cstring_alloc("t");
  cstring_from(&cs, "Hello wo32rld56!");

  int nums[100];
  int sz = 0;

  cstring_numerics(&cs, nums, &sz);

  for (int i = 0; i < sz; i++) {
    printf("%d\n", nums[i]);
  }

  cstring_free(&cs);

  return 0;
}
