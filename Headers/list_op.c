#include <stdio.h>
#include "car_list.h"  // struct definition

int loadCars(struct car_list Cars[], int maxCount) {
    FILE *file = fopen("car_list.txt", "r");
    int count = 0;
    if(file) {
        while(count < maxCount && fscanf(file, "%99s %99s %d %d %d %f %49s %49s %d",
            Cars[count].Brand, Cars[count].Model, &Cars[count].year,
            &Cars[count].price, &Cars[count].km, &Cars[count].engine_size,
            Cars[count].gas_type, Cars[count].car_type, &Cars[count].prev_owners) == 9)
        {
            count++;
        }
        fclose(file);
    }
    return count;
}

void saveCars(struct car_list Cars[], int count) {
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

void listCars(struct car_list Cars[], int count) {
    for(int i = 0; i < count; i++) {
        printf("\nBrand: %s\nModel: %s\nYear: %d\nPrice: %d\nKM: %d\n"
               "Engine: %.1f\nGas: %s\nType: %s\nPrevious Owners: %d\n",
               Cars[i].Brand, Cars[i].Model, Cars[i].year, Cars[i].price,
               Cars[i].km, Cars[i].engine_size, Cars[i].gas_type,
               Cars[i].car_type, Cars[i].prev_owners);
    }
}
