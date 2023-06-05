#include "cstring.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Cstring cs = cstring_create("Hello world!");

  cstring_print(&cs);

  cstring_repl_idx(&cs, 'x', 1);

  cstring_print(&cs);

  cstring_free(&cs);
  return 0;
}
