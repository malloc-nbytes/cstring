#include "cstring.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Cstring cs = cstring_create("Hello world!");

  size_t len;
  char *substr = cstring_substr(&cs, "wor", &len);

  for (size_t i = 0; i < len; i++) {
    putchar(substr[i]);
  }
  putchar('\n');

  cstring_free(&cs);
  return 0;
}
