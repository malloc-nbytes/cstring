#include <stdio.h>
#include <stdlib.h>
#include "cstring.h"

int main(void) {

  Cstring cs = cstring_create("!!!!!");
  cstring_delall_str(&cs, "");

  cstring_print(&cs);

  cstring_free(&cs);
  return 0;
}
