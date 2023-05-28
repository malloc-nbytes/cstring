#include "cstring.h"
#include <stdio.h>
#include <stdlib.h>

void cstring_example() {
  Cstring cs = cstring_create("Hello");

  // --- Append --- //

  cstring_append(&cs, " world!");
  cstring_print(&cs); // Prints "Hello world!"

  // --- Delete All Strings --- //

  cstring_from(&cs, "hello world hello world");
  cstring_delall_str(&cs, " world");
  cstring_print(&cs); // Prints "hello hello"

  // --- Push --- //

  cstring_push(&cs, '!');
  cstring_print(&cs); // Prints "hello hello!"

  // --- Trim --- //

  cstring_from(&cs, "    Hello world!    ");
  cstring_trim(&cs);
  cstring_print(&cs); // Prints "Hello world!"

  // --- Reverse --- //

  cstring_reverse(&cs);
  cstring_print(&cs); // Prints "!dlrow olleH"
  cstring_reverse(&cs);

  // --- Delete All Chars --- //

  cstring_delall_char(&cs, 'l');
  cstring_print(&cs); // Prints "Heo word!"

  // --- Clear --- //

  cstring_from(&cs, ""); // Clears `cs`.
  cstring_append(&cs, "Hello World!");

  // --- Pop --- //

  for (int i = 0; i < 4; i++)
    (void)cstring_pop_front(&cs);
  cstring_print(&cs); // Prints "o World!"

  // --- Substring --- //

  cstring_from(&cs, "Hello world!");

  size_t len;
  char *substr_ptr = cstring_substr(&cs, "or", &len);

  // Prints "or"
  for (size_t i = 0; i < len; i++)
    putchar(substr_ptr[i]);
  putchar('\n');

  // --- Slicing --- //

  char *slice = cstring_slice_iter(&cs, ' ', &len);

  // Prints " world!"
  for (size_t i = 0; i < len; i++)
    putchar(slice[i]);
  putchar('\n');

  // --- Split --- //

  cstring_from(&cs, "This is a test string for splitting.");
  Cstring *splits = cstring_split(&cs, ' ', &len);
  for (size_t i = 0; i < len; i++) {
    cstring_print(&splits[i]);
    cstring_free(&splits[i]);
  }
  // Prints:
  /* This
     is
     a
     test
     string
     for
     slicing. */

  free(splits);
  cstring_free(&cs);
}

int main(void) {
  cstring_example();
  return 0;
}
