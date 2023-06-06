#ifndef CSTRING_H
#define CSTRING_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *data;
  size_t len;
  size_t cap;
} Cstring;

// Creation //
Cstring cstring_create(char *init);
Cstring cstring_from_file(FILE *fp);
Cstring cstring_copy(Cstring *cs);
Cstring cstring_from_range(Cstring *cs, int start, int end);
Cstring cstring_join(Cstring *cs1, Cstring *cs2, char *join);

// Lookup //
void cstring_print(const Cstring *cs);
char cstring_at(Cstring *cs, int idx);

// Alter //
void cstring_free(Cstring *cs);
void cstring_from(Cstring *cs, char *data);
void cstring_append(Cstring *cs, char *data);
void cstring_trim(Cstring *cs);
void cstring_rev(Cstring *cs);
void cstring_push(Cstring *cs, char c);
void cstring_swap_idx(Cstring *cs, int idx1, int idx2);
void cstring_delall_str(Cstring *cs, char *remove);
void cstring_del_idx(Cstring *cs, int idx);
void cstring_filter(Cstring *cs, int (*func)(char));
void cstring_delall_char(Cstring *cs, char del);
void cstring_delfst_char(Cstring *cs, char del);
void cstring_fill(Cstring *cs, char repl);
void cstring_fill_range(Cstring *cs, char repl, int start, int end);
void cstring_toupper(Cstring *cs);
void cstring_tolower(Cstring *cs);
void cstring_repl_idx(Cstring *cs, char data, int idx);
char cstring_pop(Cstring *cs);
char cstring_pop_front(Cstring *cs);
void cstring_alter(Cstring *cs, void (*alter_func)(char *data, size_t *len, size_t *cap));

// Get //
char *cstring_substr(Cstring *cs, char *substr, size_t *len);
char *cstring_to_cstr(Cstring *cs, size_t *len);
char *cstring_slice_iter(const Cstring *cs, char delim, size_t *len);
void cstring_numerics(Cstring *cs, int *data, size_t *len);

// Equality //
int cstring_contains_char(Cstring *cs, char data);
int cstring_has_substr(Cstring *cs, char *substr);
int cstring_eq_cstring(const Cstring *cs, const Cstring *cs2);
int cstring_eq_cstr(const Cstring *cs, const char *data);
int cstring_empty(const Cstring *cs);

// Underlying Data //
size_t cstring_cap(const Cstring *cs);
size_t cstring_len(const Cstring *cs);

// Other //
int *cstring_to_atoi(Cstring *cs, size_t *len);
Cstring *cstring_split(Cstring *cs, char delim, size_t *len);
