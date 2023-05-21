# cstring
# Provides a string struct with helpful functions.
## Functions Overview

### Creation

    Cstring cstring_create(char *init);

Create a new Cstring object.

    Cstring cstring_from_file(FILE *fp);

Create a new Cstring object from file text.

    Cstring cstring_copy(Cstring *cs);

Create a new Cstring object from another Cstring.

### Query

    int cstring_contains_char(Cstring *cs, char data);

Checks to see if a Cstring contains a char.

    int cstring_has_substr(Cstring *cs, char *substr);

Checks to see if a Cstring contains a substring.

    int cstring_eq_cstring(const Cstring *cs, const Cstring *cs2);

Compares two Cstrings together.

    int cstring_eq_cstr(const Cstring *cs, const char *data);

Compares a Cstring and a char *.

    void cstring_numerics(Cstring *cs, int *data, size_t *sz);

Return a list of numbers that are contained in the Cstring. Data must be alloc'd and free'd by caller.

    char cstring_at(Cstring *cs, int idx);

Return the char at an index.

    char *cstring_slice_iter(const Cstring *cs, char delim, size_t *sz);

Given a delimiter, will return a pointer to the first character after the first location of the delimiter.

    size_t cstring_cap(const Cstring *cs);

Return the Cstring capacity.

    size_t cstring_len(const Cstring *cs);

Return the Cstring length.

    int cstring_empty(const Cstring *cs);

Check to see if a Cstring is emtpy.

### Modification

    void cstring_push(Cstring *cs, char c);

    char cstring_pop_front(Cstring *cs);

    char cstring_pop(Cstring *cs);

    void cstring_trim(Cstring *cs);

    void cstring_from(Cstring *cs, char *data);

    void cstring_reverse(Cstring *cs);

    void cstring_del_idx(Cstring *cs, int idx);

    void cstring_delall_char(Cstring *cs, char del);

    void cstring_delfst_char(Cstring *cs, char del);

    char *cstring_to_cstr(Cstring *cs);

    char *cstring_substr(Cstring *cs, char *substr);

    void cstring_free(Cstring *cs);

### Other

    int *cstring_to_ascii(Cstring *cs, size_t *sz);

    void cstring_print(const Cstring *cs);
