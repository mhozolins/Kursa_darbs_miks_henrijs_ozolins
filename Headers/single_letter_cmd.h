#ifndef SINGLE_LETTER_CMD_H
#define SINGLE_LETTER_CMD_H

#include "car_list.h"

int handleSingleLetterCommand(char choice, const char *value, struct car_list **Cars, int *count);
int isSingleLetterCommand(int argc, char *argv[]);

#endif