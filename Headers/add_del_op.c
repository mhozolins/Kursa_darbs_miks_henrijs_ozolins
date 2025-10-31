#include "add_del_op.h"
#include "same_string.h"
#include <stdio.h>
#include <stdlib.h>

void addCar(struct car_list Cars[], int *count) {
    if(*count >= 200) {
        printf("Katalogs ir pilns!\n");
        return;
    }

    printf("Ievadiet marku: "); scanf("%s", Cars[*count].Brand);
    printf("Ievadiet modeli: "); scanf("%s", Cars[*count].Model);
    printf("Ievadiet gadu: "); scanf("%d", &Cars[*count].year);
    printf("Ievadiet cenu: "); scanf("%d", &Cars[*count].price);
    printf("Ievadiet nobraukumu: "); scanf("%d", &Cars[*count].km);
    printf("Ievadiet dzineja tilpumu: "); scanf("%f", &Cars[*count].engine_size);
    printf("Ievadiet degvielas tipu: "); scanf("%s", Cars[*count].gas_type);
    printf("Ievadiet auto tipu: "); scanf("%s", Cars[*count].car_type);
    printf("Ievadiet ieprieksejos ipasniekus: "); scanf("%d", &Cars[*count].prev_owners);

    (*count)++;
    saveCars(Cars, *count);
    printf("Jaunais auto saglabats faila!\n");
}

void deleteCar(struct car_list Cars[], int *count) {
    char delBrand[200], delModel[200];
    printf("Ievadi marku, kuru dzest: "); scanf("%s", delBrand);
    printf("Ievadi modeli, kuru dzest: "); scanf("%s", delModel);

    int newCount = 0;
    for(int i=0; i<*count; i++) {
        if(!(sameString(Cars[i].Brand, delBrand) && sameString(Cars[i].Model, delModel))) {
            Cars[newCount++] = Cars[i];
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
