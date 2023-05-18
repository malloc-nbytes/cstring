#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cstring.h"

void *s_malloc(size_t nbytes) {
  void *p = malloc(nbytes);
  if (!p) {
    fprintf(stderr, "ERROR: failed to allocate %zu bytes. Reason: %s\n",
            nbytes, strerror(errno));
    exit(EXIT_FAILURE);
  }
  return p;
}

void cstring_realloc(Cstring *cs) {
  cs->data = realloc(cs->data, (cs->cap * 2) + 1);
  if (!cs->data) {
    fprintf(stderr, "ERROR: failed to reallocate. Reason: %s\n",
            strerror(errno));
    exit(EXIT_FAILURE);
  }
  memset(cs->data + cs->cap + 1, '\0', cs->cap);
  cs->cap *= 2;
}

void cstring_push(Cstring *cs, char c) {
  if (cs->sz >= cs->cap) {
    cstring_realloc(cs);
  }
  cs->data[cs->sz++] = c;
}

void cstring_dump(const Cstring *cs) {
  printf("%s\n", cs->data);
}

void shift_elems_left(Cstring *cs, int start) {
  for (size_t i = start; i < cs->sz - 1; i++) {
    cs->data[i] = cs->data[i + 1];
  }
  cs->data[--(cs->sz)] = '\0';
}

void cstring_del_idx(Cstring *cs, int idx) {
  if (idx < 0 || idx >= cs->sz) {
    return;
  }
  shift_elems_left(cs, idx);
}

void cstring_pop(Cstring *cs) {
  if (!cs->sz) {
    return;
  }
  cs->data[--(cs->sz)] = '\0';
}

void cstring_pop_front(Cstring *cs) {
  if (!cs->sz) {
    return;
  }
  shift_elems_left(cs, 0);
}

size_t cstring_cap(const Cstring *cs) {
  return cs->cap;
}

size_t cstring_len(const Cstring *cs) {
  return cs->sz;
}

char cstring_get_char(Cstring *cs, int idx) {
  if (idx < 0 || idx >= cs->sz) {
    return '\0';
  }
  return cs->data[idx];
}

void cstring_trim(Cstring *cs) {
  if (!cs->sz) {
    return;
  }
  while (cs->data[0] == ' ') {
    cstring_pop_front(cs);
  }
  while (cs->data[cs->sz - 1] == ' ') {
    cstring_pop(cs);
  }
}

void cstring_from(Cstring *cs, char *data) {
  if (cs->sz > 0) {
    cstring_free(cs);
  }
  cs->data = s_malloc(sizeof(char));
  cs->data[0] = '\0';
  cs->cap = 1;
  cs->sz = 0;
  if (data) {
    for (int i = 0; data[i] != '\0'; i++) {
      cstring_push(cs, data[i]);
    }
  }
}

Cstring cstring_alloc(char *init) {
  Cstring cs = { 0 };
  cstring_from(&cs, init);
  return cs;
}

void cstring_free(Cstring *cs) {
  free(cs->data);
  cs->cap = 0;
  cs->sz = 0;
}


