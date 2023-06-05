#include "cstring.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Cstring cs = cstring_create("HELLO WORLD!");

  cstring_print(&cs);

  cstring_tolower(&cs);

  cstring_print(&cs);

  cstring_free(&cs);
  return 0;
}
