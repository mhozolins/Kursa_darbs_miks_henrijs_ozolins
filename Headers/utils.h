#ifndef UTILS_H
#define UTILS_H

// Manual string length (no string.h)
int strLength(const char *str);

// Manual string copy (no string.h) 
void strCopy(char *dest, const char *src);

// Manual lowercase conversion (no ctype.h)
char toLowerManual(char c);

// Case-insensitive comparison for strings
int caseInsensitiveCompare(const char *a, const char *b);

#endif