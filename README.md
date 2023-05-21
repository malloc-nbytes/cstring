# cstring
# Provides a string struct with helpful functions.
## Functions Overview

### Creation
`Cstring cstring\_create(char *init);`
Create a new `Cstring` object.
`Cstring cstring\_from\_file(FILE *fp);`
Create a new `Cstring` object from file text.
`Cstring cstring\_copy(Cstring *cs);`
Create a new `Cstring` object from another `Cstring`.

### Query
`int cstring\_contains\_char(Cstring *cs, char data);`
`int cstring\_has\_substr(Cstring *cs, char *substr);`
`int cstring\_eq\_cstring(const Cstring *cs, const Cstring *cs2);`
`int cstring\_eq\_cstr(const Cstring *cs, const char *data);`
`void cstring\_numerics(Cstring *cs, int *data, size\_t *sz);`
`char cstring\_at(Cstring *cs, int idx);`
`char *cstring\_slice\_iter(const Cstring *cs, char delim, size\_t *sz);`
`size\_t cstring\_cap(const Cstring *cs);`
`size\_t cstring\_len(const Cstring *cs);`
`int cstring\_empty(const Cstring *cs);`

### Modification
`void cstring\_push(Cstring *cs, char c);`
`char cstring\_pop\_front(Cstring *cs);`
`char cstring\_pop(Cstring *cs);`
`void cstring\_trim(Cstring *cs);`
`void cstring\_from(Cstring *cs, char *data);`
`void cstring\_reverse(Cstring *cs);`
`void cstring\_del\_idx(Cstring *cs, int idx);`
`void cstring\_delall\_char(Cstring *cs, char del);`
`void cstring\_delfst\_char(Cstring *cs, char del);`
`char *cstring\_to\_cstr(Cstring *cs);`
`char *cstring\_substr(Cstring *cs, char *substr);`
`void cstring\_free(Cstring *cs);`

### Other
`int *cstring\_to\_ascii(Cstring *cs, size\_t *sz);`
`void cstring\_print(const Cstring *cs);`
