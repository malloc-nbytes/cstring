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

### `cstring_rev`
`void cstring_rev(Cstring *cs);`

Reverse characters.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world");
  cstring_rev(&cs);
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

### 'cstring_eq_cstring'
`int cstring_eq_cstring(const Cstring *cs, const Cstring *cs2);`

`strcmp()` on two `Cstring`'s.

Example:
```c
int main(void) {
  Cstring cs1 = cstring_create("Hello world!");
  Cstring cs2 = cstring_create("Hello world!");

  printf("%s\n", cstring_eq_cstring(&cs1, &cs2) == 0
         ? "same" : "different");

  cstring_free(&cs1);
  cstring_free(&cs2);
  return 0;
}
```
Output:
```
same
```

### `cstring_eq_cstr`
`int cstring_eq_cstr(const Cstring *cs, const char *data);`

`strcmp()` on a `Cstring` and a `char *`.

Example:

```c
int main(void) {
  Cstring cs = cstring_create("Hello world!");
  char *s = "Hello world!";

  printf("%s\n", cstring_eq_cstr(&cs, s) == 0
         ? "same" : "different");

  cstring_free(&cs);
  return 0;
}
```
Output:
```
same
```

### `cstring_numerics`
`void cstring_numerics(Cstring *cs, int *data, size_t *len);`

Extract all numbers. Numbers that have more than 10 digits are not accepted.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello32 wo199rld4!");

  size_t len;
  int *nums = malloc(sizeof(int) * 3);

  cstring_numerics(&cs, nums, &len);

  for (size_t i = 0; i < len; i++) {
    printf("%d\n", nums[i]);
  }

  cstring_free(&cs);
  free(nums);
  return 0;
}
```
Output:
```
32
199
4
```

### `cstring_to_atoi`
`int *cstring_to_atoi(Cstring *cs, size_t *len);`

Create a new array of integers that are the ascii equivalent in the `Cstring`.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world!");

  size_t len;
  int *nums = cstring_to_atoi(&cs, &len);

  for (size_t i = 0; i < len; i++) {
    printf("%d\n", nums[i]);
  }

  cstring_free(&cs);
  free(nums);
  return 0;
}
```
Output:
```
72
101
108
108
111
32
119
111
114
108
100
33
```

### `cstring_at`
`char cstring_at(Cstring *cs, int idx);`

Get a character at a given index.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world!");

  char c = cstring_at(&cs, 4);

  printf("%c\n", c);

  cstring_free(&cs);
  return 0;
}
```
Output:
```
o
```

### `cstring_to_cstr`
`char *cstring_to_cstr(Cstring *cs, size_t *len);`

Convert a `Cstring` to `char *`.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world!");

  size_t len;
  char *s = cstring_to_cstr(&cs, &len);

  for (size_t i = 0; i < len; i++) {
    putchar(s[i]);
  }
  putchar('\n');

  cstring_free(&cs);
  free(s);
  return 0;
}
```
Output:
```
Hello world!
```

### `cstring_slice_iter`
`char *cstring_slice_iter(const Cstring *cs, char delim, size_t *len);`

Return a pointer to the character `delim`. This function will alter the value in `len` to give the resulting pointer length.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world!");

  size_t len;
  char *slice = cstring_slice_iter(&cs, ' ', &len);

  for (size_t i = 0; i < len; i++) {
    putchar(slice[i]);
  }
  putchar('\n');

  cstring_free(&cs);
  return 0;
}
```
Output:
```
 world!
```

### `cstring_split`
`Cstring *cstring_split(Cstring *cs, char delim, size_t *len);`

Return an array of `Cstring`s split on `delim`. This function will alter the value in `len` to give the resulting pointer length.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world, foo bar baz, some more text.");

  size_t len;
  Cstring *arr = cstring_split(&cs, ' ', &len);

  for (size_t i = 0; i < len; i++) {
    cstring_print(&arr[i]);
    cstring_free(&arr[i]);
  }

  cstring_free(&cs);
  free(arr);
  return 0;
}
```
Output:
```
Hello
world,
foo
bar
baz,
some
more
text.
```

### `cstring_from_range`
`Cstring cstring_from_range(Cstring *cs, int start, int end);`

Create a new `Cstring` from a range of characters in `cs` starting from `start` and ending at `end` - 1.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world");

  Cstring range = cstring_from_range(&cs, 6, 11);

  cstring_print(&range);

  cstring_free(&cs);
  cstring_free(&range);
  return 0;
}
```
Output:
```
world
```

### `cstring_fill`
`void cstring_fill(Cstring *cs, char repl);`

Fill the `Cstring` with a character.

```c
int main(void) {
  Cstring cs = cstring_create("Hello world");

  cstring_fill(&cs, '*');

  cstring_print(&cs);

  cstring_free(&cs);
  return 0;
}
```
Output:
```
***********
```

### `cstring_fill_range`
`void cstring_fill_range(Cstring *cs, char repl, int start, int end);`

Fill a range of the `Cstring`.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world");

  cstring_fill_range(&cs, '*', 0, 5);

  cstring_print(&cs);

  cstring_free(&cs);
  return 0;
}
```
Output:
```
******world
```

### `cstring_cap`
`size_t cstring_cap(const Cstring *cs);`

Get the `Cstring` capacity.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world");

  printf("%zu\n", cstring_cap(&cs));

  cstring_free(&cs);
  return 0;
}
```
Output:
```
16777216
```

### `cstring_len`
`size_t cstring_len(const Cstring *cs);`

Get the `Cstring` length.

```c
int main(void) {
  Cstring cs = cstring_create(NULL);

  for (int i = 0; i < 10000000; i++) {
    cstring_push(&cs, 'a');
  }

  printf("%zu\n", cstring_len(&cs));

  cstring_free(&cs);
  return 0;
}
```
Output:
```
10000000
```

### `cstring_empty`
`int cstring_empty(const Cstring *cs);`


Check to see if a `Cstring` is empty.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world!");

  while (!cstring_empty(&cs)) {
    cstring_pop(&cs);
  }

  cstring_free(&cs);
  return 0;
}
```

### `cstring_toupper`
`void cstring_toupper(Cstring *cs);`

Convert a string to uppercase.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world!");

  cstring_print(&cs);

  cstring_toupper(&cs);

  cstring_print(&cs);

  cstring_free(&cs);
  return 0;
}
```
Output:
```
Hello world!
HELLO WORLD!
```

### `cstring_tolower`
`void cstring_tolower(Cstring *cs);`

Convert a string to lowercase.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("HELLO WORLD!");

  cstring_print(&cs);

  cstring_tolower(&cs);

  cstring_print(&cs);

  cstring_free(&cs);
  return 0;
}
```
Output:
```
HELLO WORLD!
hello world!
```

### `cstring_repl_idx`
`void cstring_repl_idx(Cstring *cs, char data, int idx);`

Change a value in `cs`.

Example:
```c
int main(void) {
  Cstring cs = cstring_create("Hello world!");

  cstring_print(&cs);

  cstring_repl_idx(&cs, 'x', 1);

  cstring_print(&cs);

  cstring_free(&cs);
  return 0;
}
```
Output:
```
Hello world!
Hxllo world!
```

### `cstring_join`
`Cstring cstring_join(Cstring *cs1, Cstring *cs2, char *join);`

Join two `Cstring`'s together to form a new `Cstring`. It gets merged such that `res = cs1 + join + cs2`. If `join` is NULL, it will be: `res = cs1 + cs2`. This function consumes both `Cstring`'s.

Example:
```c
int main(void) {
  Cstring cs1 = cstring_create("Hello world!");
  Cstring cs2 = cstring_create("Foo bar baz.");

  Cstring merged = cstring_join(&cs1, &cs2, " ;;; ");

  cstring_print(&merged);

  cstring_free(&merged);
  return 0;
}
```
Output:
```
Hello world! ;;; Foo bar baz.
```

### `cstring_alter`
`void cstring_alter(Cstring *cs, void (*alter_func)(char *data, size_t *len, size_t *cap));`

Apply `alter_func` on the underlying `char *` data. If you do anything that would alter the `Cstring` length, be sure to update `len` and/or `cap`.

Example:
```c
void alter_func(char *data, size_t *len, size_t *cap) {
  for (int i = 0; i < *len; i++) {
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
```
Output:
```
Hello world!
xxxxxxxxxxxx
```
