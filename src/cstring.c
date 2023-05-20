#include <errno.h>
#include <stdio.h>
#include <ctype.h>
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

void cstring_print(const Cstring *cs) {
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

char cstring_pop(Cstring *cs) {
  if (!cs->sz) {
    return '\0';
  }
  char save = cs->data[cs->sz - 1];
  cs->data[--(cs->sz)] = '\0';
  return save;
}

char cstring_pop_front(Cstring *cs) {
  if (!cs->sz) {
    return '\0';
  }
  char save = cs->data[0];
  shift_elems_left(cs, 0);
  return save;
}

int cstring_empty(const Cstring *cs) {
  return cs->sz == 0;
}

size_t cstring_cap(const Cstring *cs) {
  return cs->cap;
}

size_t cstring_len(const Cstring *cs) {
  return cs->sz;
}

int cstring_empty(const Cstring *cs) {
  return !cs->sz;
}

char cstring_at(Cstring *cs, int idx) {
  if (idx < 0 || idx >= cs->sz) {
    return '\0';
  }
  return cs->data[idx];
}
 
Cstring cstring_copy(Cstring *cs) {
  return cstring_alloc(cs->data);
}

char *cstring_to_cstr(Cstring *cs) {
  char *data = s_malloc(cs->sz + 1);
  strcpy(data, cs->data);
  return data;
}

void cstring_reverse(Cstring *cs) {
  int start = 0, tmp, end = cs->sz - 1;
  while (start < end) {
    tmp = cs->data[start];
    cs->data[start] = cs->data[end];
    cs->data[end] = tmp;
    start += 1;
    end -= 1;
  }
}

void cstring_numerics(Cstring *cs, int *data, size_t *sz) {
  *sz = 0;
  char buff[10];
  memset(buff, '\0', 10);
  int buff_sz = 0;
  for (size_t i = 0; i < cs->sz; i++) {
    if (isdigit(cs->data[i])) {
      if (buff_sz == 10) {
        fprintf(stderr, "ERROR: numbers in Cstring must not exceed 10 digits.\n");
        exit(EXIT_FAILURE);
      }
      buff[buff_sz++] = cs->data[i];
    } else if (buff_sz > 0) {
      data[*sz] = atoi(buff);
      *sz += 1;
      buff_sz = 0;
      memset(buff, '\0', 10);
    }
  }
}

char *cstring_substr(Cstring *cs, char *substr) {
  Cstring buff = cstring_alloc(NULL);
  int ptr = 0;
  size_t n = strlen(substr);
  for (int i = 0; i < cs->sz; i++) {
    char c = cs->data[i];
    if (c == substr[ptr]) {
      cstring_push(&buff, c);
      ptr += 1;
    } else {
      i -= ptr;
      ptr = 0;
      if (cstring_len(&buff) > 0) {
        cstring_from(&buff, "");
      }
    }
    if (cstring_len(&buff) == n) {
      char *res = cstring_to_cstr(&buff);
      cstring_free(&buff);
      return res;
    }
  }
  if (cstring_len(&buff) > 0) {
    cstring_free(&buff);
  }
  return NULL;
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
  cs->data = s_malloc(sizeof(char) * 2);
  memset(cs->data, '\0', sizeof(cs->data[0]) * 2);
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


