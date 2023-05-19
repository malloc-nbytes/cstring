#include <stdio.h>
#include <stdlib.h>
#include "cstring.h"

int main(void) {
  Cstring cs = cstring_alloc("t");
  cstring_from(&cs, "uuuuck");

  cstring_free(&cs);
  return 0;
}
