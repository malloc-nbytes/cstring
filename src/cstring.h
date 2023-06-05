#ifndef CSTRING_H
#define CSTRING_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *data;
  size_t len;
  size_t cap;
} Cstring;

// Create a new `Cstring`.
// When given NULL or "", no data will be added.
Cstring cstring_create(char *init);

// Init a `Cstring` from file contents.
// File must be opened and closed from caller.
Cstring cstring_from_file(FILE *fp);

// Changes the contents of a `Cstring`. If given "",
// it essentially acts as a clear() function.
void cstring_from(Cstring *cs, char *data);

// Print the contents.
void cstring_print(const Cstring *cs);

// Free memory.
void cstring_free(Cstring *cs);

// Append a string.
void cstring_append(Cstring *cs, char *data);

// Remove leading and trailing whitespace.
void cstring_trim(Cstring *cs);

// Returns a new `Cstring` that is a direct
// copy of a given `Cstring`.
Cstring cstring_copy(Cstring *cs);

// Reverse characters.
void cstring_reverse(Cstring *cs);

// Push a character.
void cstring_push(Cstring *cs, char c);

// Pop the front character.
char cstring_pop_front(Cstring *cs);

// Pop the last character.
char cstring_pop(Cstring *cs);

// Swap the character at `idx1` with `idx2`.
void cstring_swap_idx(Cstring *cs, int idx1, int idx2);

// Remove all occurrences of `remove`.
// Nothing will happen when given an empty string.
void cstring_delall_str(Cstring *cs, char *remove);

// Delete a character at a given idx.
void cstring_del_idx(Cstring *cs, int idx);

// Filter the `Cstring` data by giving a function.
void cstring_filter(Cstring *cs, int (*func)(char));

// Delete all characters matching `del`.
void cstring_delall_char(Cstring *cs, char del);

// Delete the first character matching `del`.
void cstring_delfst_char(Cstring *cs, char del);

// See if a character is present. 1 on success, 0 on failure.
int cstring_contains_char(Cstring *cs, char data);

// Checks to see if a `Cstring` contains a given substring.
// 1 on success, 0 on failure.
int cstring_has_substr(Cstring *cs, char *substr);

// Get a pointer to the start of a substring. This function
// will alter the value in `len` to give the substring's length.
char *cstring_substr(Cstring *cs, char *substr, size_t *len);

// strcmp() on two `Cstring`'s.
int cstring_eq_cstring(const Cstring *cs, const Cstring *cs2);

// strcmp() on a `Cstring` and a char *.
int cstring_eq_cstr(const Cstring *cs, const char *data);

// Extract all numbers. Numbers that have more than 10
// digits are not accepted.
void cstring_numerics(Cstring *cs, int *data, size_t *len);

// Create a new array of integers that are the
// ascii equivalent in the `Cstring`.
int *cstring_to_atoi(Cstring *cs, size_t *len);

// Get a character at a given index.
char cstring_at(Cstring *cs, int idx);

// Convert a `Cstring` to char *.
char *cstring_to_cstr(Cstring *cs, size_t *len);

// Return a pointer to the character `delim`. This function
// will alter the value in `len` to give the resulting pointer length.
char *cstring_slice_iter(const Cstring *cs, char delim, size_t *len);

// Return an array of `Cstring`s split on `delim`. This function
// will alter the value in `len` to give the resulting pointer length.
Cstring *cstring_split(Cstring *cs, char delim, size_t *len);

// Create a new `Cstring` from a range of characters in `cs`
// starting from `start` and ending at `end` - 1.
Cstring cstring_from_range(Cstring *cs, int start, int end);

// Fill the `Cstring` with a character.
void cstring_fill(Cstring *cs, char repl);

// Fill a range of the `Cstring`.
void cstring_fill_range(Cstring *cs, char repl, int start, int end);

// Get the `Cstring` capacity.
size_t cstring_cap(const Cstring *cs);

// Get the `Cstring` length.
size_t cstring_len(const Cstring *cs);

// Check to see if a `Cstring` is empty.
int cstring_empty(const Cstring *cs);

// Convert a string to uppercase.
void cstring_toupper(Cstring *cs);

// Convert a string to lowercase.
void cstring_tolower(Cstring *cs);

// Change a value in `cs`.
void cstring_repl_idx(Cstring *cs, char data, int idx);

// Join two `Cstring`'s together to form a new `Cstring`.
// It gets merged such that `res = cs1 + join + cs2`.
// If `join` is NULL, it will be: `res = cs1 + cs2`.
// This function consumes both `Cstring`'s.
Cstring cstring_join(Cstring *cs1, Cstring *cs2, char *join);

// Apply `alter_func` on the underlying `char *` data.
void cstring_alter(Cstring *cs, void (*alter_func)(char *data, size_t *len, size_t *cap));

#endif // CSTRING_H
