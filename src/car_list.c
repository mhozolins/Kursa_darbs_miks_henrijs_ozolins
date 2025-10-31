#include <stdio.h>
#include <stdlib.h>
#include "../Headers/search_op.h"
#include "../Headers/add_del_op.h"
#include "../Headers/list_op.h"
#include "../Headers/same_string.h"
#include "../Headers/car_list.h"

int main(int argc, char *argv[]) {
    struct car_list Cars[200];
    int count = loadCars(Cars, 200);

    
    if(argc > 1 && sameString(argv[1], "sort")) {
        const char *brand = "";
        const char *sortby = "price"; // default

        if(argc > 2) brand = argv[2];      // optional brand
        if(argc > 3) sortby = argv[3];     // optional sort field

        struct car_list filtered[200];
        int fcount = 0;

        // Filter cars by brand if provided
        for(int i = 0; i < count; i++) {
            if(brand[0] == '\0' || sameString(Cars[i].Brand, brand)) {
                filtered[fcount++] = Cars[i];
            }
        }

        if(fcount == 0) {
            printf("Nav atrasti auto ar noradito marku.\n");
            return 0;
        }

        // Simple bubble sort based on chosen field
        for(int i = 0; i < fcount - 1; i++) {
            for(int j = i + 1; j < fcount; j++) {
                int swap = 0;
                if(sameString(sortby, "price") && filtered[i].price > filtered[j].price)
                    swap = 1;
                else if(sameString(sortby, "year") && filtered[i].year < filtered[j].year)
                    swap = 1;
                else if(sameString(sortby, "km") && filtered[i].km > filtered[j].km)
                    swap = 1;

                if(swap) {
                    struct car_list tmp = filtered[i];
                    filtered[i] = filtered[j];
                    filtered[j] = tmp;
                }
            }
        }

        listCars(filtered, fcount);
        return 0; 
    }


    char choice;
    while(1) {
        printf("================== LABAS TACKAS.LV ========================");
        printf("\nL - Paradit visus auto\n"
               "G - Meklet pec degvielas tipa\n"
               "T - Meklet pec auto tipa\n"
               "M - Meklet pec markas\n"
               "S - Sakartot pec gada\n"
               "P - Sakartot pec cenas\n"
               "A - Pievienot jaunu auto\n"
               "D - Dzest auto\n"
               "Q - Iziet\nChoice: ");

        choice = getchar();
        while(choice == '\n') choice = getchar();

        if(choice=='Q' || choice=='q') break;
        else if(choice=='L' || choice=='l') listCars(Cars, count);
        else if(choice=='G' || choice=='g') searchByFuel(Cars, count);
        else if(choice=='T' || choice=='t') searchByType(Cars, count);
        else if(choice=='M' || choice=='m') searchByBrand(Cars, count);
        else if(choice=='S' || choice=='s') sortByYear(Cars, count);
        else if(choice=='P' || choice=='p') sortByPrice(Cars, count);
        else if(choice=='A' || choice=='a') addCar(Cars, &count);
        else if(choice=='D' || choice=='d') deleteCar(Cars, &count);

        while(getchar()!='\n');
    }

    return 0;
}
