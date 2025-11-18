#include "utils.h"

// Manual string length (no string.h)
int strLength(const char *str) {
    int len = 0;
    while(str[len] != '\0') len++;
    return len;
}

// Manual string copy (no string.h)
void strCopy(char *dest, const char *src) {
    int i = 0;
    while(src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Manual lowercase conversion (no ctype.h)
char toLowerManual(char c) {
    if(c >= 'A' && c <= 'Z') return c + ('a' - 'A');
    return c;
}

// Case-insensitive comparison for strings
int caseInsensitiveCompare(const char *a, const char *b) {
    int i = 0;
    while(a[i] != '\0' || b[i] != '\0') {
        char ca = (a[i] != '\0') ? toLowerManual(a[i]) : '\0';
        char cb = (b[i] != '\0') ? toLowerManual(b[i]) : '\0';

        if(ca < cb) return -1;
        if(ca > cb) return 1;
        i++;
    }
    return 0;
}