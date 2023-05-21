#include <stdio.h>
#include <stdlib.h>
#include "cstring.h"

int main(void) {

  Cstring cs = cstring_create("Hello World!");

  cstring_free(&cs);

  return 0;
}
