#include <stdio.h>
#include <stdlib.h>
#include "same_string.h"
#include "add_del_op.h"
#include "list_op.h"
#include "search_op.h"

// Manual lowercase conversion (no ctype.h)
char toLowerManual(char c) {
    if(c >= 'A' && c <= 'Z') return c + ('a' - 'A');
    return c;
}

// Case-insensitive comparison for gas type (no string.h)
int cmpGas(const char *a, const char *b) {
    int i = 0;
    while(a[i] != '\0' || b[i] != '\0') {
        char ca = (a[i] != '\0') ? toLowerManual(a[i]) : '\0';
        char cb = (b[i] != '\0') ? toLowerManual(b[i]) : '\0';

        if(ca < cb) return -1;
        if(ca > cb) return 1;

        i++;
    }
    return 0;  // strings are equal
}

// Handle CLI commands
int handleArguments(int argc, char *argv[], struct car_list Cars[], int *count) {
    if(argc < 2) return 0; // no command -> menu

    const char *cmd = argv[1];

    // LIST
    if(sameString(cmd, "list")) {
        listCars(Cars, *count);
        return 1;
    }

    // ADD
    else if(sameString(cmd, "add")) {
        if(argc != 11) {
            printf("ERROR: Missing arguments!\n");
            printf("Usage: make add BRAND MODEL YEAR PRICE KM ENGINE GAS TYPE OWNERS\n");
            return 1;
        }

        struct car_list car;
        int i;
        for(i=0; i<100 && argv[2][i] != '\0'; i++) car.Brand[i] = argv[2][i];
        car.Brand[i] = '\0';
        for(i=0; i<100 && argv[3][i] != '\0'; i++) car.Model[i] = argv[3][i];
        car.Model[i] = '\0';

        car.year = atoi(argv[4]);
        car.price = atoi(argv[5]);
        car.km = atoi(argv[6]);
        car.engine_size = atof(argv[7]);

        for(i=0; i<50 && argv[8][i] != '\0'; i++) car.gas_type[i] = argv[8][i];
        car.gas_type[i] = '\0';
        for(i=0; i<50 && argv[9][i] != '\0'; i++) car.car_type[i] = argv[9][i];
        car.car_type[i] = '\0';

        car.prev_owners = atoi(argv[10]);

        if(*count >= 200) {
            printf("Catalog is full!\n");
            return 1;
        }

        Cars[*count] = car;
        (*count)++;
        saveCars(Cars, *count);
        printf("Car added successfully!\n");
        return 1;
    }


    else if(sameString(cmd, "delete")) {
        if(argc != 4) {
            printf("ERROR: Missing arguments!\n");
            printf("Usage: make delete BRAND MODEL\n");
            return 1;
        }

        const char *brand = argv[2];
        const char *model = argv[3];

        int newCount = 0;
        for(int i=0; i<*count; i++) {
            if(!(sameString(Cars[i].Brand, brand) && sameString(Cars[i].Model, model))) {
                Cars[newCount++] = Cars[i];
            }
        }

        if(newCount == *count) {
            printf("Car not found!\n");
        } else {
            *count = newCount;
            saveCars(Cars, *count);
            printf("Car deleted successfully!\n");
        }
        return 1;
    }

    
    else if(sameString(cmd, "sort")) {
        const char *brand = "";
        const char *field = "price";

        if(argc > 2) brand = argv[2];
        if(argc > 3) field = argv[3];

        struct car_list filtered[200];
        int fcount = 0;
        for(int i=0; i<*count; i++) {
            if(brand[0] == '\0' || sameString(Cars[i].Brand, brand)) {
                filtered[fcount++] = Cars[i];
            }
        }

        if(fcount == 0) {
            printf("No cars found for brand '%s'\n", brand);
            return 1;
        }

        
        for(int i=0; i<fcount-1; i++) {
            for(int j=i+1; j<fcount; j++) {
                int swap = 0;

                if(sameString(field, "price") && filtered[i].price > filtered[j].price)
                    swap = 1;
                else if(sameString(field, "year") && filtered[i].year < filtered[j].year)
                    swap = 1;
                else if(sameString(field, "km") && filtered[i].km > filtered[j].km)
                    swap = 1;
                else if(sameString(field, "gas") && cmpGas(filtered[i].gas_type, filtered[j].gas_type) > 0)
                    swap = 1;

                if(swap) {
                    struct car_list tmp = filtered[i];
                    filtered[i] = filtered[j];
                    filtered[j] = tmp;
                }
            }
        }

        listCars(filtered, fcount);
        return 1;
    }

    return 0;
}
