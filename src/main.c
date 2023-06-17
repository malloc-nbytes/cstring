#include "cstring.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Cstring cs = cstring_create("Hello world!");

  char c = cstring_getchar(&cs, 0);

  printf("%c\n", c);

  cstring_free(&cs);
  return 0;
}
