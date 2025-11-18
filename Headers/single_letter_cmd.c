#include <stdio.h>
#include <stdlib.h>
#include "car_list.h"
#include "same_string.h"
#include "list_op.h"
#include "search_op.h"
#include "add_del_op.h"

int handleSingleLetterCommand(char choice, const char *value, struct car_list **Cars, int *count) {
    if(choice == 'M' || choice == 'm') {
        printf("Cars from brand '%s':\n", value);
        int found = 0;
        for(int i = 0; i < *count; i++) {
            if(sameString((*Cars)[i].Brand, value)) {
                printf("\nBrand: %s\nModel: %s\nYear: %d\nPrice: %d\nKM: %d\n"
                       "Engine: %.1f\nGas: %s\nType: %s\nPrevious Owners: %d\n",
                       (*Cars)[i].Brand, (*Cars)[i].Model, (*Cars)[i].year, (*Cars)[i].price,
                       (*Cars)[i].km, (*Cars)[i].engine_size, (*Cars)[i].gas_type,
                       (*Cars)[i].car_type, (*Cars)[i].prev_owners);
                found = 1;
            }
        }
        if(!found) printf("No cars found from brand '%s'\n", value);
        return 1;
    }
    else if(choice == 'G' || choice == 'g') {
        printf("Cars with fuel type '%s':\n", value);
        int found = 0;
        for(int i = 0; i < *count; i++) {
            if(sameString((*Cars)[i].gas_type, value)) {
                printf("\nBrand: %s\nModel: %s\nYear: %d\nPrice: %d\nKM: %d\n"
                       "Engine: %.1f\nGas: %s\nType: %s\nPrevious Owners: %d\n",
                       (*Cars)[i].Brand, (*Cars)[i].Model, (*Cars)[i].year, (*Cars)[i].price,
                       (*Cars)[i].km, (*Cars)[i].engine_size, (*Cars)[i].gas_type,
                       (*Cars)[i].car_type, (*Cars)[i].prev_owners);
                found = 1;
            }
        }
        if(!found) printf("No cars found with fuel type '%s'\n", value);
        return 1;
    }
    else if(choice == 'T' || choice == 't') {
        printf("Cars of type '%s':\n", value);
        int found = 0;
        for(int i = 0; i < *count; i++) {
            if(sameString((*Cars)[i].car_type, value)) {
                printf("\nBrand: %s\nModel: %s\nYear: %d\nPrice: %d\nKM: %d\n"
                       "Engine: %.1f\nGas: %s\nType: %s\nPrevious Owners: %d\n",
                       (*Cars)[i].Brand, (*Cars)[i].Model, (*Cars)[i].year, (*Cars)[i].price,
                       (*Cars)[i].km, (*Cars)[i].engine_size, (*Cars)[i].gas_type,
                       (*Cars)[i].car_type, (*Cars)[i].prev_owners);
                found = 1;
            }
        }
        if(!found) printf("No cars found of type '%s'\n", value);
        return 1;
    }
    else if(choice == 'L' || choice == 'l') {
        listCars(*Cars, *count);
        return 1;
    }
    else if(choice == 'S' || choice == 's') {
        sortByYear(*Cars, *count);
        return 1;
    }
    else if(choice == 'P' || choice == 'p') {
        sortByPrice(*Cars, *count);
        return 1;
    }
    else if(choice == 'A' || choice == 'a') {
        addCar(*Cars, count);
        return 1;
    }
    else if(choice == 'D' || choice == 'd') {
        deleteCar(*Cars, count);
        return 1;
    }
    else if(choice == 'Q' || choice == 'q') {
        printf("Quitting...\n");
        return 1;
    }
    return 0;
}

int isSingleLetterCommand(int argc, char *argv[]) {
    if(argc >= 2) {
        char *cmd = argv[1];
        // Check if command is single letter
        return (cmd[0] != '\0' && cmd[1] == '\0');
    }
    return 0;
}