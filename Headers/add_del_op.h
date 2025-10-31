#ifndef ADD_DEL_OP_H
#define ADD_DEL_OP_H

#include "car_list.h"

void addCar(struct car_list Cars[], int *count);
void deleteCar(struct car_list Cars[], int *count);
void saveCars(struct car_list Cars[], int count);

#endif
