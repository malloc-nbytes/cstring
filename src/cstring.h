#ifndef CSTRING_H
#define CSTRING_H

typedef struct {
  char *data;
  size_t sz;
  size_t cap;
} Cstring;

Cstring cstring_alloc(char *init);
void cstring_print(const Cstring *cs);
void cstring_push(Cstring *cs, char c);
void cstring_trim(Cstring *cs);
void cstring_free(Cstring *cs);
void cstring_del_idx(Cstring *cs, int idx);
char cstring_pop_front(Cstring *cs);
char cstring_pop(Cstring *cs);
size_t cstring_cap(const Cstring *cs);
size_t cstring_len(const Cstring *cs);
char cstring_at(Cstring *cs, int idx);
void cstring_from(Cstring *cs, char *data);
Cstring cstring_copy(Cstring *cs);
size_t cstring_cap(const Cstring *cs);
char *cstring_to_cstr(Cstring *cs);
void cstring_numerics(Cstring *cs, int *data, int *sz);

#endif // CSTRING_H
