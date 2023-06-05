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


