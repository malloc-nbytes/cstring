# cstring
# Provides a string struct with helpful functions.
## Functions Overview

### Creation
`Cstring cstring_create(char *init);`

    Create a new `Cstring` object.

`Cstring cstring_from_file(FILE *fp);`

    Create a new `Cstring` object from file text.

`Cstring cstring_copy(Cstring *cs);`

    Create a new `Cstring` object from another `Cstring`.

### Query

`int cstring_contains_char(Cstring *cs, char data);`

`int cstring_has_substr(Cstring *cs, char *substr);`

`int cstring_eq_cstring(const Cstring *cs, const Cstring *cs2);`

`int cstring_eq_cstr(const Cstring *cs, const char *data);`

`void cstring_numerics(Cstring *cs, int *data, size_t *sz);`

`char cstring_at(Cstring *cs, int idx);`

`char *cstring_slice_iter(const Cstring *cs, char delim, size_t *sz);`

`size_t cstring_cap(const Cstring *cs);`

`size_t cstring_len(const Cstring *cs);`

`int cstring_empty(const Cstring *cs);`

### Modification

`void cstring_push(Cstring *cs, char c);`

`char cstring_pop_front(Cstring *cs);`

`char cstring_pop(Cstring *cs);`

`void cstring_trim(Cstring *cs);`

`void cstring_from(Cstring *cs, char *data);`

`void cstring_reverse(Cstring *cs);`

`void cstring_del_idx(Cstring *cs, int idx);`

`void cstring_delall_char(Cstring *cs, char del);`

`void cstring_delfst_char(Cstring *cs, char del);`

`char *cstring_to_cstr(Cstring *cs);`

`char *cstring_substr(Cstring *cs, char *substr);`

`void cstring_free(Cstring *cs);`

### Other

`int *cstring_to_ascii(Cstring *cs, size_t *sz);`

`void cstring_print(const Cstring *cs);`
