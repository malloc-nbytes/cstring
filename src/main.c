#include "cstring.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Cstring cs = cstring_create("Hello world");
  Cstring copy = cstring_copy(&cs);

  cstring_print(&copy);

  cstring_free(&cs);
  cstring_free(&copy);
  return 0;
}
