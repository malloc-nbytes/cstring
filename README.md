# cstring

Provides a string struct with helpful functions.

## Functions Overview

### `cstring_create`
`Cstring cstring_create(char *init);`

Create a new `Cstring`. When given NULL or "", no data will be added.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("hello world");
  return 0;
}
```

### `cstring_from_file`
`Cstring cstring_from_file(FILE *fp);`

Init a `Cstring` from file contents. File must be opened and closed from caller.

```c
#define FILEPATH "./input.txt"

int main(void) {
  FILE *fp = fopen(FILEPATH, "r");

  Cstring cs = cstring_from_file(fp);

  fclose(fp);
  return 0;
}
```

### `cstring_from`
`void cstring_from(Cstring *cs, char *data);`

Changes the contents of a `Cstring`. If given "", it essentially acts as a clear() function.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world");

  cstring_print(&cs);

  cstring_from(&cs, "new text");

  cstring_print(&cs);

  cstring_free(&cs);

  return 0;
}
```
Output:
```
Hello world
new text
```

### `cstring_print`
`void cstring_print(const Cstring *cs);`

Print the contents.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world");
  cstring_print(&cs);
  cstring_free(&cs);
  return 0;
}
```
Output;
```
Hello world
```

### `cstring_free`
`void cstring_free(Cstring *cs);`

Free memory.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world");
  cstring_free(&cs);
  return 0;
}
```

### `cstring_append`
`void cstring_append(Cstring *cs, char *data);`

Append a string.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world");
  cstring_append(&cs, ", foo bar");
  cstring_print(&cs);
  cstring_free(&cs);
  return 0;
}
```
Output:
```
Hello world, foo bar
```

### `cstring_trim`
`void cstring_trim(Cstring *cs);`

Remove leading and trailing whitespace.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("    Hello world    ");
  cstring_print(&cs);

  cstring_trim(&cs);
  cstring_print(&cs);

  cstring_free(&cs);
  return 0;
}
```
Output:
```
    Hello world    
Hello world
```

### `cstring_copy`
`Cstring cstring_copy(Cstring *cs);`

Returns a new `Cstring` that is a direct copy of a given `Cstring`.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world");
  Cstring copy = cstring_copy(&cs);

  cstring_print(&copy);

  cstring_free(&cs);
  cstring_free(&copy);
  return 0;
}
```
Output:
```
Hello world
```

### `cstring_reverse`
`void cstring_reverse(Cstring *cs);`

Reverse characters.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world");
  cstring_reverse(&cs);
  cstring_print(&cs);
  cstring_free(&cs);
  return 0;
}
```
Output:
```
dlrow olleH
```

### `cstring_push`
`void cstring_push(Cstring *cs, char c);`

Push a character.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world");
  cstring_push(&cs, 'a');
  cstring_print(&cs);
  cstring_free(&cs);
  return 0;
}
```
Output:
```
Hello worlda
```

### `cstring_pop_front`
`char cstring_pop_front(Cstring *cs);`

Pop the front character.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world");
  cstring_pop_front(&cs);
  cstring_print(&cs);
  cstring_free(&cs);
  return 0;
}
```
Output:
```
ello world
```

### `cstring_pop`
`char cstring_pop(Cstring *cs);`

Pop the last character.

Example:
```
int main(void) {
  Cstring cs = cstring_create("Hello world");
  cstring_pop(&cs);
  cstring_print(&cs);
  cstring_free(&cs);
  return 0;
}
```
Output:
```
Hello worl
```

### `cstring_swap_idx`
`void cstring_swap_idx(Cstring *cs, int idx1, int idx2);`

Swap the character at `idx1` with `idx2`.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world");
  cstring_swap_idx(&cs, 0, cstring_len(&cs) - 1);
  cstring_print(&cs);
  cstring_free(&cs);
  return 0;
}
```
Output:
```
dello worlH
```

### `cstring_delall_str`
`void cstring_delall_str(Cstring *cs, char *remove);`

Remove all occurrences of `remove`. Nothing will happen when given an empty string.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world world");
  cstring_delall_str(&cs, " world");
  cstring_print(&cs);
  cstring_free(&cs);
  return 0;
}
```
Output:
```
Hello
```

### `cstring_del_idx`
`void cstring_del_idx(Cstring *cs, int idx);`

Delete a character at a given idx.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world");
  cstring_del_idx(&cs, 1);
  cstring_print(&cs);
  cstring_free(&cs);
  return 0;
}
```
Output:
```
Hllo world
```

### `cstring_filter`
`void cstring_filter(Cstring *cs, int (*func)(char));`

Filter the `Cstring` data by giving a function.

Example:
```c
int filter_char(char c) {
  return isalpha(c) || c == ' ';
}

int main(void) {
  Cstring cs = cstring_create("Hello world! This, is some text...");
  cstring_filter(&cs, filter_char);
  cstring_print(&cs);
  cstring_free(&cs);
  return 0;
}
```
Output:
```
Hello world This is some text
```

### `cstring_delall_char`
`void cstring_delall_char(Cstring *cs, char del);`

Delete all characters matching `del`.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world!");
  cstring_delall_char(&cs, 'l');
  cstring_print(&cs);
  cstring_free(&cs);
  return 0;
}
```
Output:
```
Heo word!
```

### `cstring_delfst_char`
`void cstring_delfst_char(Cstring *cs, char del);`

Delete the first character matching `del`.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world!");
  cstring_delfst_char(&cs, 'l');
  cstring_print(&cs);
  cstring_free(&cs);
  return 0;
}
```
Output:
```
Helo world!
```

### `cstring_contains_char`
`int cstring_contains_char(Cstring *cs, char data);`

See if a character is present. 1 on success, 0 on failure.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world!");

  printf("%s\n", cstring_contains_char(&cs, 'o')
         ? "true" : "false");

  printf("%s\n", cstring_contains_char(&cs, 'x')
         ? "true" : "false");

  cstring_free(&cs);
  return 0;
}
```
Output:
```
true
false
```

### `cstring_has_substr`
`int cstring_has_substr(Cstring *cs, char *substr);`

Checks to see if a `Cstring` contains a given substring. 1 on success, 0 on failure.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world!");

  printf("%s\n", cstring_has_substr(&cs, "world!")
         ? "true" : "false");

  printf("%s\n", cstring_has_substr(&cs, "test")
         ? "true" : "false");

  cstring_free(&cs);
  return 0;
}
```
Output:
```
true
false
```

### `cstring_substr`
`char *cstring_substr(Cstring *cs, char *substr, size_t *len);`

Get a pointer to the start of a substring. This function will alter the value in `len` to give the substring's length.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world!");

  size_t len;
  char *substr = cstring_substr(&cs, "wor", &len);

  for (size_t i = 0; i < len; i++) {
    putchar(substr[i]);
  }
  putchar('\n');

  cstring_free(&cs);
  return 0;
}
```
Output:
```
wor
```

