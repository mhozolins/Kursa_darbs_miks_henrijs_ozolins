#include <stdio.h>
#include <stdlib.h>
#include "../Headers/car_list.h"
#include "../Headers/add_del_op.h"
#include "../Headers/list_op.h"
#include "../Headers/same_string.h"
#include "../Headers/search_op.h"
#include "../Headers/argument_handler.h"

int main(int argc, char *argv[]) {
    struct car_list Cars[200];
    int count = loadCars(Cars, 200);

    if(handleArguments(argc, argv, Cars, &count)) {
        return 0; // CLI command executed
    }

    // Interactive menu
    char choice;
    while(1) {
        printf("================== LABAS TACKAS.LV ========================\n");
        printf("L - Show all cars\n"
               "G - Search by fuel\n"
               "T - Search by type\n"
               "M - Search by brand\n"
               "S - Sort by year\n"
               "P - Sort by price\n"
               "A - Add car\n"
               "D - Delete car\n"
               "Q - Quit\nChoice: ");

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
