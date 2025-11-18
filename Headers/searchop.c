#include <stdio.h>
#include "car_list.h"
#include "same_string.h"
#include "utils.h"  

void searchByFuel(struct car_list Cars[], int count) {
    char fuelType[50];
    printf("Ievadiet degvielas tipu: ");
    scanf("%49s", fuelType);
    
    int found = 0;
    for(int i = 0; i < count; i++) {
        if(caseInsensitiveCompare(Cars[i].gas_type, fuelType) == 0) {
            printf("\nBrand: %s\nModel: %s\nYear: %d\nPrice: %d\nKM: %d\n"
                   "Engine: %.1f\nGas: %s\nType: %s\nPrevious Owners: %d\n",
                   Cars[i].Brand, Cars[i].Model, Cars[i].year, Cars[i].price,
                   Cars[i].km, Cars[i].engine_size, Cars[i].gas_type,
                   Cars[i].car_type, Cars[i].prev_owners);
            found = 1;
        }
    }
    if(!found) {
        printf("No cars found with fuel type: %s\n", fuelType);
    }
}

void searchByType(struct car_list Cars[], int count) {
    char carType[50];
    printf("Ievadiet auto tipu: ");
    scanf("%49s", carType);
    
    int found = 0;
    for(int i = 0; i < count; i++) {
        if(caseInsensitiveCompare(Cars[i].car_type, carType) == 0) {
            printf("\nBrand: %s\nModel: %s\nYear: %d\nPrice: %d\nKM: %d\n"
                   "Engine: %.1f\nGas: %s\nType: %s\nPrevious Owners: %d\n",
                   Cars[i].Brand, Cars[i].Model, Cars[i].year, Cars[i].price,
                   Cars[i].km, Cars[i].engine_size, Cars[i].gas_type,
                   Cars[i].car_type, Cars[i].prev_owners);
            found = 1;
        }
    }
    if(!found) {
        printf("No cars found of type: %s\n", carType);
    }
}

void searchByBrand(struct car_list Cars[], int count) {
    char brand[100];
    printf("Ievadiet marku: ");
    scanf("%99s", brand);
    
    int found = 0;
    for(int i = 0; i < count; i++) {
        if(caseInsensitiveCompare(Cars[i].Brand, brand) == 0) {
            printf("\nBrand: %s\nModel: %s\nYear: %d\nPrice: %d\nKM: %d\n"
                   "Engine: %.1f\nGas: %s\nType: %s\nPrevious Owners: %d\n",
                   Cars[i].Brand, Cars[i].Model, Cars[i].year, Cars[i].price,
                   Cars[i].km, Cars[i].engine_size, Cars[i].gas_type,
                   Cars[i].car_type, Cars[i].prev_owners);
            found = 1;
        }
    }
    if(!found) {
        printf("No cars found from brand: %s\n", brand);
    }
}

void sortByYear(struct car_list Cars[], int count) {
    struct car_list temp[200];
    for(int i = 0; i < count; i++) {
        temp[i] = Cars[i];
    }
    
    
    for(int i = 0; i < count - 1; i++) {
        for(int j = 0; j < count - i - 1; j++) {
            if(temp[j].year < temp[j+1].year) {
                struct car_list tmp = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = tmp;
            }
        }
    }
    
    
    for(int i = 0; i < count; i++) {
        printf("\nBrand: %s\nModel: %s\nYear: %d\nPrice: %d\nKM: %d\n"
               "Engine: %.1f\nGas: %s\nType: %s\nPrevious Owners: %d\n",
               temp[i].Brand, temp[i].Model, temp[i].year, temp[i].price,
               temp[i].km, temp[i].engine_size, temp[i].gas_type,
               temp[i].car_type, temp[i].prev_owners);
    }
}

void sortByPrice(struct car_list Cars[], int count) {
    
    struct car_list temp[200];
    for(int i = 0; i < count; i++) {
        temp[i] = Cars[i];
    }
    
    
    for(int i = 0; i < count - 1; i++) {
        for(int j = 0; j < count - i - 1; j++) {
            if(temp[j].price > temp[j+1].price) {
                struct car_list tmp = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = tmp;
            }
        }
    }
    
    
    for(int i = 0; i < count; i++) {
        printf("\nBrand: %s\nModel: %s\nYear: %d\nPrice: %d\nKM: %d\n"
               "Engine: %.1f\nGas: %s\nType: %s\nPrevious Owners: %d\n",
               temp[i].Brand, temp[i].Model, temp[i].year, temp[i].price,
               temp[i].km, temp[i].engine_size, temp[i].gas_type,
               temp[i].car_type, temp[i].prev_owners);
    }
}