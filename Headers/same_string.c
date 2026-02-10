#include "same_string.h"
#include "utils.h"

int sameString(const char *s1, const char *s2) {
    return caseInsensitiveCompare(s1, s2) == 0;
}