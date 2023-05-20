#ifndef CSTRING_H
#define CSTRING_H

typedef struct {
  char *data;
  size_t sz;
  size_t cap;
} Cstring;

Cstring cstring_alloc(char *init);
Cstring cstring_copy(Cstring *cs);

void cstring_print(const Cstring *cs);
void cstring_push(Cstring *cs, char c);
void cstring_trim(Cstring *cs);
void cstring_free(Cstring *cs);
void cstring_del_idx(Cstring *cs, int idx);
void cstring_from(Cstring *cs, char *data);
void cstring_numerics(Cstring *cs, int *data, size_t *sz);
void cstring_reverse(Cstring *cs);

char cstring_pop_front(Cstring *cs);
char cstring_pop(Cstring *cs);
char cstring_at(Cstring *cs, int idx);
char *cstring_to_cstr(Cstring *cs);
char *cstring_substr(Cstring *cs, char *substr);

size_t cstring_cap(const Cstring *cs);
size_t cstring_len(const Cstring *cs);

int cstring_empty(const Cstring *cs);

#endif // CSTRING_H
