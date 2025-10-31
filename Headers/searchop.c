#include "search_op.h"
#include "list_op.h"
#include "same_string.h"
#include <stdio.h>
#include <stdlib.h>




void searchByFuel(struct car_list Cars[], int count) {
    char gtype[50];
    printf("Ievadi degvielas tipu: ");
    scanf("%s", gtype);
    int found = 0;

    for(int i=0; i<count; i++) {
        if(sameString(Cars[i].gas_type, gtype)) {
            printf("\nBrand: %s\nModel: %s\nYear: %d\nPrice: %d\nKM: %d\n"
                   "Engine: %.1f\nGas: %s\nType: %s\nPrevious Owners: %d\n",
                Cars[i].Brand, Cars[i].Model, Cars[i].year, Cars[i].price,
                Cars[i].km, Cars[i].engine_size, Cars[i].gas_type,
                Cars[i].car_type, Cars[i].prev_owners);
            found = 1;
        }
    }

    if(!found)
        printf("Nav atrasti auto ar tadu degvielas tipu.\n");
}


void searchByType(struct car_list Cars[], int count) {
    char ctype[50];
    printf("Ievadi auto tipu: ");
    scanf("%s", ctype);
    int found = 0;

    for(int i=0; i<count; i++) {
        if(sameString(Cars[i].car_type, ctype)) {
            printf("\nBrand: %s\nModel: %s\nYear: %d\nPrice: %d\nKM: %d\n"
                   "Engine: %.1f\nGas: %s\nType: %s\nPrevious Owners: %d\n",
                Cars[i].Brand, Cars[i].Model, Cars[i].year, Cars[i].price,
                Cars[i].km, Cars[i].engine_size, Cars[i].gas_type,
                Cars[i].car_type, Cars[i].prev_owners);
            found = 1;
        }
    }

    if(!found)
        printf("Nav atrasti auto ar tadu tipu.\n");
}


void searchByBrand(struct car_list Cars[], int count) {
    char brand[200];
    printf("Ievadi marku: ");
    scanf("%s", brand);
    int found = 0;

    for(int i=0; i<count; i++) {
        if(sameString(Cars[i].Brand, brand)) {
            printf("\nBrand: %s\nModel: %s\nYear: %d\nPrice: %d\nKM: %d\n"
                   "Engine: %.1f\nGas: %s\nType: %s\nPrevious Owners: %d\n",
                Cars[i].Brand, Cars[i].Model, Cars[i].year, Cars[i].price,
                Cars[i].km, Cars[i].engine_size, Cars[i].gas_type,
                Cars[i].car_type, Cars[i].prev_owners);
            found = 1;
        }
    }

    if(!found)
        printf("Nav atrasti auto ar tadu marku.\n");
}


void sortByYear(struct car_list Cars[], int count) {
    for(int i=0; i<count-1; i++)
        for(int j=i+1; j<count; j++)
            if(Cars[i].year < Cars[j].year) {
                struct car_list tmp = Cars[i];
                Cars[i] = Cars[j];
                Cars[j] = tmp;
            }
    listCars(Cars, count);
}


void sortByPrice(struct car_list Cars[], int count) {
    for(int i=0; i<count-1; i++)
        for(int j=i+1; j<count; j++)
            if(Cars[i].price > Cars[j].price) {
                struct car_list tmp = Cars[i];
                Cars[i] = Cars[j];
                Cars[j] = tmp;
            }
    listCars(Cars, count);
}

void sortByPriceFiltered(struct car_list Cars[], int count, const char *brand, const char *model) {
    struct car_list filtered[200];
    int fcount = 0;

    // Filter cars
    for (int i = 0; i < count; i++) {
        int match = 1;
        if (brand[0] != '\0' && !sameString(Cars[i].Brand, brand)) match = 0;
        if (model[0] != '\0' && !sameString(Cars[i].Model, model)) match = 0;
        if (match) filtered[fcount++] = Cars[i];
    }

    if (fcount == 0) {
        printf("Nav atrasti auto ar noradito marku/modeli.\n");
        return;
    }

    // Simple bubble sort by price
    for(int i = 0; i < fcount - 1; i++)
        for(int j = i + 1; j < fcount; j++)
            if(filtered[i].price > filtered[j].price) {
                struct car_list tmp = filtered[i];
                filtered[i] = filtered[j];
                filtered[j] = tmp;
            }

    // Print filtered & sorted cars
    listCars(filtered, fcount);
}

