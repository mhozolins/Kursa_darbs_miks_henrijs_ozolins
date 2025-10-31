#ifndef SEARCH_OP_H
#define SEARCH_OP_H

#include "car_list.h"
#include "same_string.h"

void searchByFuel(struct car_list Cars[], int count);
void searchByType(struct car_list Cars[], int count);
void searchByBrand(struct car_list Cars[], int count);
void sortByYear(struct car_list Cars[], int count);
void sortByPrice(struct car_list Cars[], int count);

#endif
