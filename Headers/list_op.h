#ifndef LIST_OP_H
#define LIST_OP_H

#include "car_list.h"

int loadCars(struct car_list Cars[], int maxCount);
void listCars(struct car_list Cars[], int count);
void saveCars(struct car_list Cars[], int count);

#endif
