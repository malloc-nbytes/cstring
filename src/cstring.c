#include <errno.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
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

char cstring_at(Cstring *cs, int idx) {
  if (idx < 0 || idx >= cs->sz) {
    return '\0';
  }
  return cs->data[idx];
}
 
Cstring cstring_copy(Cstring *cs) {
  return cstring_create(cs->data);
}

char *cstring_to_cstr(Cstring *cs, size_t *len) {
  char *data = s_malloc(cs->sz + 1);
  strcpy(data, cs->data);
  *len = cs->sz;
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

char *cstring_substr(Cstring *cs, char *substr, size_t *len) {
  Cstring buff = cstring_create(NULL);
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
      // Return the start of the substr.
      char *res = &cs->data[i + 1 - n];
      *len = n;
      return res;
    }
  }
  if (cstring_len(&buff) > 0) {
    cstring_free(&buff);
  }
  *len = -1;
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

int cstring_has_substr(Cstring *cs, char *substr) {
  size_t len;
  (void) cstring_substr(cs, substr, &len);
  return len != -1;
}

int *cstring_to_atoi(Cstring *cs, size_t *sz) {
  *sz = 0;
  int *res = s_malloc(sizeof(int) * cs->sz);
  for (size_t i = 0; i < cs->sz; i++) {
    res[*sz] = cs->data[i];
    *sz += 1;
  }
  return res;
}

int cstring_contains_char(Cstring *cs, char data) {
  for (size_t i = 0; i < cs->sz; i++) {
    if (cs->data[i] == data) {
      return 1;
    }
  }
  return 0;
}

void cstring_delfst_char(Cstring *cs, char del) {
  for (size_t i = 0; i < cs->sz; i++) {
    if (cs->data[i] == del) {
      cstring_del_idx(cs, i);
      break;
    }
  }
}

void cstring_delall_char(Cstring *cs, char del) {
  for (size_t i = 0; i < cs->sz; i++) {
    if (cs->data[i] == del) {
      cstring_del_idx(cs, i);
      i -= 1;
    }
  }
}

Cstring cstring_from_file(FILE *fp) {
  Cstring cs = cstring_create(NULL);
  char *buffer = 0;
  long length;

  if (fp) {
    fseek(fp, 0, SEEK_END);
    length = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    buffer = s_malloc(length);
    if (buffer) {
      fread(buffer, 1, length, fp);
    }
  }

  if (buffer) {
    for (long i = 0; i < length; i++) {
      cstring_push(&cs, buffer[i]);
    }
    free(buffer);
  }

  return cs;
}

int cstring_eq_cstring(const Cstring *cs, const Cstring *cs2) {
  return strcmp(cs->data, cs2->data);
}

int cstring_eq_cstr(const Cstring *cs, const char *data) {
    return strcmp(cs->data, data);
}

Cstring cstring_from_range(Cstring *cs, int start, int end) {
  Cstring res = cstring_create(NULL);
  for (int i = start; i < end; i++) {
    cstring_push(&res, cs->data[i]);
  }
  return res;
}

Cstring *cstring_split(Cstring *cs, char delim, size_t *sz) {
  Cstring *res = s_malloc(sizeof(Cstring) * 32);
  *sz = 0;

  int ptr = 0;

  for (size_t i = 0; i < cs->sz; i++) {
    char c = cs->data[i];
    if (c == delim) {
      res[*sz] = cstring_from_range(cs, ptr, i);
      *sz += 1;
      i += 1;
      ptr = i;
    }
  }

  res[*sz] = cstring_from_range(cs, ptr, cs->sz);
  *sz += 1;

  return res;
}

char *cstring_slice_iter(const Cstring *cs, char delim, size_t *sz) {
  char *slice = NULL;
  for (size_t i = 0; i < cs->sz; i++) {
    if (cs->data[i] == delim) {
      slice = &cs->data[i];
      *sz = cs->sz - i;
      break;
    }
  }
  return slice;
}

void cstring_delall_str(Cstring *cs, char *remove) {
  if (!strlen(remove)) {
    return;
  }

  size_t len;
  do {
    char *substr = cstring_substr(cs, remove, &len);
    if (len != -1) {
      int idx = substr - cs->data;
      for (size_t i = 0; i < len; i++) {
        cstring_del_idx(cs, idx);
      }
    }
  } while (len != -1);
}

void cstring_append(Cstring *cs, char *data) {
  for (size_t i = 0; data[i] != '\0'; i++) {
    cstring_push(cs, data[i]);
  }
}

Cstring cstring_create(char *init) {
  Cstring cs = { 0 };
  cstring_from(&cs, init);
  return cs;
}

void cstring_swap_idx(Cstring *cs, int idx1, int idx2) {
  if ((idx1 < 0 || idx1 >= cs->sz) || (idx2 < 0 || idx2 >= cs->sz)) {
    fprintf(stderr, "ERROR: indices must be within the size of the cstring\n");
    exit(EXIT_FAILURE);
  }
  char tmp = cs->data[idx1];
  cs->data[idx1] = cs->data[idx2];
  cs->data[idx2] = tmp;
}

void cstring_free(Cstring *cs) {
  free(cs->data);
  cs->cap = 0;
  cs->sz = 0;
}

