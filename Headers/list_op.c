#include <stdio.h>
#include <stdlib.h>
#include "car_list.h"
#include "same_string.h"
#include "utils.h"


int loadCars(struct car_list *Cars, int maxCount) {
    FILE *file = fopen("car_list.txt", "r");
    int count = 0;
    if(file) {
        while(count < maxCount) {
            char tempBrand[100], tempModel[100], tempGas[50], tempType[50];
            int year, price, km, prev_owners;
            float engine_size;
            
            if(fscanf(file, "%99s %99s %d %d %d %f %49s %49s %d",
                tempBrand, tempModel, &year, &price, &km, &engine_size,
                tempGas, tempType, &prev_owners) != 9) {
                break;
            }
            
            
            Cars[count].Brand = malloc(strLength(tempBrand) + 1);
            Cars[count].Model = malloc(strLength(tempModel) + 1);
            Cars[count].gas_type = malloc(strLength(tempGas) + 1);
            Cars[count].car_type = malloc(strLength(tempType) + 1);
            
            
            strCopy(Cars[count].Brand, tempBrand);
            strCopy(Cars[count].Model, tempModel);
            strCopy(Cars[count].gas_type, tempGas);
            strCopy(Cars[count].car_type, tempType);
            
            
            Cars[count].year = year;
            Cars[count].price = price;
            Cars[count].km = km;
            Cars[count].engine_size = engine_size;
            Cars[count].prev_owners = prev_owners;
            
            count++;
        }
        fclose(file);
    }
    return count;
}

void saveCars(struct car_list *Cars, int count) {
    FILE *file = fopen("car_list.txt", "w");
    if(file) {
        for(int i = 0; i < count; i++) {
            fprintf(file, "%s %s %d %d %d %.1f %s %s %d\n",
                Cars[i].Brand, Cars[i].Model, Cars[i].year, Cars[i].price,
                Cars[i].km, Cars[i].engine_size, Cars[i].gas_type,
                Cars[i].car_type, Cars[i].prev_owners);
        }
        fclose(file);
    }
}

void listCars(struct car_list *Cars, int count) {
    for(int i = 0; i < count; i++) {
        printf("\nBrand: %s\nModel: %s\nYear: %d\nPrice: %d\nKM: %d\n"
               "Engine: %.1f\nGas: %s\nType: %s\nPrevious Owners: %d\n",
               Cars[i].Brand, Cars[i].Model, Cars[i].year, Cars[i].price,
               Cars[i].km, Cars[i].engine_size, Cars[i].gas_type,
               Cars[i].car_type, Cars[i].prev_owners);
    }
}

// Free all allocated memory for cars
void freeCars(struct car_list *Cars, int count) {
    for(int i = 0; i < count; i++) {
        free(Cars[i].Brand);
        free(Cars[i].Model);
        free(Cars[i].gas_type);
        free(Cars[i].car_type);
    }
}