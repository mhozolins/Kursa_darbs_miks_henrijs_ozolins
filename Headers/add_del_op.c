#include "add_del_op.h"
#include "same_string.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>


void addCar(struct car_list *Cars, int *count) {
    if(*count >= 200) {
        printf("Katalogs ir pilns!\n");
        return;
    }

    // Temporary buffers
    char tempBrand[100], tempModel[100], tempGas[50], tempType[50];
    int year, price, km, prev_owners;
    float engine_size;

    printf("Ievadiet marku: "); scanf("%99s", tempBrand);
    printf("Ievadiet modeli: "); scanf("%99s", tempModel);
    printf("Ievadiet gadu: "); scanf("%d", &year);
    printf("Ievadiet cenu: "); scanf("%d", &price);
    printf("Ievadiet nobraukumu: "); scanf("%d", &km);
    printf("Ievadiet dzineja tilpumu: "); scanf("%f", &engine_size);
    printf("Ievadiet degvielas tipu: "); scanf("%49s", tempGas);
    printf("Ievadiet auto tipu: "); scanf("%49s", tempType);
    printf("Ievadiet ieprieksejos ipasniekus: "); scanf("%d", &prev_owners);

    
    Cars[*count].Brand = malloc(strLength(tempBrand) + 1);
    Cars[*count].Model = malloc(strLength(tempModel) + 1);
    Cars[*count].gas_type = malloc(strLength(tempGas) + 1);
    Cars[*count].car_type = malloc(strLength(tempType) + 1);
    
    
    strCopy(Cars[*count].Brand, tempBrand);
    strCopy(Cars[*count].Model, tempModel);
    strCopy(Cars[*count].gas_type, tempGas);
    strCopy(Cars[*count].car_type, tempType);
    
    
    Cars[*count].year = year;
    Cars[*count].price = price;
    Cars[*count].km = km;
    Cars[*count].engine_size = engine_size;
    Cars[*count].prev_owners = prev_owners;

    (*count)++;
    saveCars(Cars, *count);
    printf("Jaunais auto saglabats faila!\n");
}

void deleteCar(struct car_list *Cars, int *count) {
    char delBrand[200], delModel[200];
    printf("Ievadi marku, kuru dzest: "); scanf("%199s", delBrand);
    printf("Ievadi modeli, kuru dzest: "); scanf("%199s", delModel);

    int newCount = 0;
    for(int i=0; i<*count; i++) {
        if(!(sameString(Cars[i].Brand, delBrand) && sameString(Cars[i].Model, delModel))) {
            // Keep the car - copy to new position
            Cars[newCount] = Cars[i];
            newCount++;
        } else {
            // Delete the car - free its memory
            free(Cars[i].Brand);
            free(Cars[i].Model);
            free(Cars[i].gas_type);
            free(Cars[i].car_type);
        }
    }

    if(newCount == *count) {
        printf("Auto netika atrasts!\n");
    } else {
        *count = newCount;
        saveCars(Cars, *count);
        printf("Auto dzests!\n");
    }
}