#ifndef CSTRING_H
#define CSTRING_H

typedef struct {
  char *data;
  size_t sz;
  size_t cap;
} Cstring;

// Append a character.
void cstring_append(Cstring *cs, char *data);

// Remove all occurrences of `remove`.
// Nothing will happen when given an empty string.
void cstring_delall_str(Cstring *cs, char *remove);

// Create a new `Cstring`.
// When given NULL or "", no data will be added.
Cstring cstring_create(char *init);

// Init a `Cstring` from file contents.
// File must be opened and closed from caller.
Cstring cstring_from_file(FILE *fp);

// Returns a new `Cstring` that is a direct
// copy of a given `Cstring`.
Cstring cstring_copy(Cstring *cs);

// See if a character is present. 1 on success, 0 on failure.
int cstring_contains_char(Cstring *cs, char data);

// Checks to see if a `Cstring` contains a given substring.
// 1 on success, 0 on failure.
int cstring_has_substr(Cstring *cs, char *substr);

// strcmp() on two `Cstring`'s.
int cstring_eq_cstring(const Cstring *cs, const Cstring *cs2);

// strcmp() on a `Cstring` and a char *.
int cstring_eq_cstr(const Cstring *cs, const char *data);

// Print the contents.
void cstring_print(const Cstring *cs);

// Push a character.
void cstring_push(Cstring *cs, char c);

// Remove leading and trailing whitespace.
void cstring_trim(Cstring *cs);

// Free memory.
void cstring_free(Cstring *cs);

// Changes the contents of a `Cstring`. If given "",
// it essentially acts as a clear() function.
void cstring_from(Cstring *cs, char *data);

// Extract all numbers. Numbers that have more than 10
// digits are not accepted.
void cstring_numerics(Cstring *cs, int *data, size_t *sz);

// Reverse characters.
void cstring_reverse(Cstring *cs);

// Delete a character at a given idx.
void cstring_del_idx(Cstring *cs, int idx);

// Delete all characters matching `del`.
void cstring_delall_char(Cstring *cs, char del);

// Delete the first character matching `del`.
void cstring_delfst_char(Cstring *cs, char del);

// Create a new array of integers that are the
// ascii equivalent in the `Cstring`.
int *cstring_to_ascii(Cstring *cs, size_t *sz);

// Pop the front character.
char cstring_pop_front(Cstring *cs);

// Pop the last character.
char cstring_pop(Cstring *cs);

// Get a character at a given index.
char cstring_at(Cstring *cs, int idx);

// Convert a `Cstring` to char *.
char *cstring_to_cstr(Cstring *cs, size_t *len);

// Get a pointer to the start of a substring. This function
// will alter the value in `len` to give the substring's length.
char *cstring_substr(Cstring *cs, char *substr, size_t *len);

// Return a pointer to the character after `delim`. This function
// will alter the value in `len` to give the resulting pointer length.
char *cstring_slice_iter(const Cstring *cs, char delim, size_t *sz);

// Get the `Cstring` capacity.
size_t cstring_cap(const Cstring *cs);

// Get the `Cstring` length.
size_t cstring_len(const Cstring *cs);

// Check to see if a `Cstring` is empty.
int cstring_empty(const Cstring *cs);

#endif // CSTRING_H
