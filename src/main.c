#include "cstring.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Cstring cs = cstring_create("Hello world!");
  cstring_fprint(&cs, stdout);
  cstring_free(&cs);
  return 0;
}
