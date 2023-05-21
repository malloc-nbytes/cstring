#include <stdio.h>
#include <stdlib.h>
#include "cstring.h"

int main(void) {

  FILE *fp = fopen("input.txt", "r");
  Cstring cs = cstring_from_file(fp);
  fclose(fp);

  cstring_print(&cs);

  cstring_free(&cs);
  return 0;
}
