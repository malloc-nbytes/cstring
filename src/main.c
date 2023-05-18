#include <stdio.h>
#include "cstring.h"

int main(void) {
  Cstring cs = cstring_alloc("t");
  cstring_from(&cs, "Hello world!");

  printf("%c\n", cstring_pop_front(&cs));

  cstring_free(&cs);
  return 0;
}
