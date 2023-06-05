#include "cstring.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void alter_func(char *data) {
  for (int i = 0; data[i] != '\0'; i++) {
    data[i] = 'x';
  }
}

int main(void) {
  Cstring cs = cstring_create("Hello world!");

  cstring_print(&cs);

  cstring_alter(&cs, alter_func);

  cstring_print(&cs);

  cstring_free(&cs);
  return 0;
}
