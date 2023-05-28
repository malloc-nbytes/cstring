# cstring
# Provides a string struct with helpful functions.
## Functions Overview

Create a new `Cstring`. When given NULL or "", no data will be added.
```
Cstring cstring_create(char *init);
```

Init a `Cstring` from file contents. File must be opened and closed from caller.
```
Cstring cstring_from_file(FILE *fp);
```

Changes the contents of a `Cstring`. If given "", it essentially acts as a clear() function.
```
void cstring_from(Cstring *cs, char *data);
```

Print the contents.
```
void cstring_print(const Cstring *cs);
```

Free memory.
```
void cstring_free(Cstring *cs);
```

Append a string.
```
void cstring_append(Cstring *cs, char *data);
```

Remove leading and trailing whitespace.
```
void cstring_trim(Cstring *cs);
```

Returns a new `Cstring` that is a direct copy of a given `Cstring`.
```
Cstring cstring_copy(Cstring *cs);
```

Reverse characters.
```
void cstring_reverse(Cstring *cs);
```

Push a character.
```
void cstring_push(Cstring *cs, char c);
```

Pop the front character.
```
char cstring_pop_front(Cstring *cs);
```

Pop the last character.
```
char cstring_pop(Cstring *cs);
```

Swap the character at `idx1` with `idx2`.
```
void cstring_swap_idx(Cstring *cs, int idx1, int idx2);
```

Remove all occurrences of `remove`. Nothing will happen when given an empty string.
```
void cstring_delall_str(Cstring *cs, char *remove);
```

Delete a character at a given idx.
```
void cstring_del_idx(Cstring *cs, int idx);
```

Filter the `Cstring` data by giving a function.
```
void cstring_filter(Cstring *cs, int (*func)(char));
```

Delete all characters matching `del`.
```
void cstring_delall_char(Cstring *cs, char del);
```

Delete the first character matching `del`.
```
void cstring_delfst_char(Cstring *cs, char del);
```

See if a character is present. 1 on success, 0 on failure.
```
int cstring_contains_char(Cstring *cs, char data);
```

Checks to see if a `Cstring` contains a given substring. 1 on success, 0 on failure.
```
int cstring_has_substr(Cstring *cs, char *substr);
```

Get a pointer to the start of a substring. This function will alter the value in `len` to give the substring's length.
```
char *cstring_substr(Cstring *cs, char *substr, size_t *len);
```

strcmp() on two `Cstring`'s.
```
int cstring_eq_cstring(const Cstring *cs, const Cstring *cs2);
```

strcmp() on a `Cstring` and a char *.
```
int cstring_eq_cstr(const Cstring *cs, const char *data);
```

Extract all numbers. Numbers that have more than 10 digits are not accepted.
```
void cstring_numerics(Cstring *cs, int *data, size_t *len);
```

Create a new array of integers that are the ascii equivalent in the `Cstring`.
```
int *cstring_to_atoi(Cstring *cs, size_t *len);
```

Get a character at a given index.
```
char cstring_at(Cstring *cs, int idx);
```

Convert a `Cstring` to char *.
```
char *cstring_to_cstr(Cstring *cs, size_t *len);
```

Return a pointer to the character `delim`. This function will alter the value in `len` to give the resulting pointer length.
```
char *cstring_slice_iter(const Cstring *cs, char delim, size_t *len);
```

Return an array of `Cstring`s split on `delim`. This function will alter the value in `len` to give the resulting pointer length.
```
Cstring *cstring_split(Cstring *cs, char delim, size_t *len);
```

Fill the `Cstring` with a character.
```
void cstring_fill(Cstring *cs, char repl);
```

Fill a range of the `Cstring`.
```
void cstring_fill_range(Cstring *cs, char repl, int start, int end);
```

Create a new `Cstring` from a range of characters in `cs` starting from `start` and ending at `end` - 1.
```
Cstring cstring_from_range(Cstring *cs, int start, int end);
```

Get the `Cstring` capacity.
```
size_t cstring_cap(const Cstring *cs);
```

Get the `Cstring` length.
```
size_t cstring_len(const Cstring *cs);
```

Check to see if a `Cstring` is empty.
```
int cstring_empty(const Cstring *cs);
```

## Example
```
#include <stdio.h>
#include <stdlib.h>
#include "cstring.h"

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
```
