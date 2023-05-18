#include <stdio.h>
#include "cstring.h"

int main(void) {
  Cstring cs = cstring_alloc("t");
  cstring_print(&cs);

  /* for (int i = 0; i < 1000; i++) { */
  /*   cstring_push(&cs, 'a'); */
  /* } */

  cstring_from(&cs, "Hello world!");
  cstring_print(&cs);

  cstring_free(&cs);
  return 0;
}
