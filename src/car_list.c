#include <stdio.h>
#include <stdlib.h>
#include "../Headers/car_list.h"
#include "../Headers/add_del_op.h"
#include "../Headers/list_op.h"
#include "../Headers/same_string.h"
#include "../Headers/search_op.h"
#include "../Headers/argument_handler.h"
#include "../Headers/single_letter_cmd.h"

int main(int argc, char *argv[]) {
    struct car_list *Cars = malloc(200 * sizeof(struct car_list));
    if (Cars == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Initialize all pointers to NULL
    for(int i = 0; i < 200; i++) {
        Cars[i].Brand = NULL;
        Cars[i].Model = NULL;
        Cars[i].gas_type = NULL;
        Cars[i].car_type = NULL;
    }
    
    int count = loadCars(Cars, 200);

   
    if(argc > 1) {
        if(isSingleLetterCommand(argc, argv)) {
            const char *value = (argc > 2) ? argv[2] : "";
            if(handleSingleLetterCommand(argv[1][0], value, &Cars, &count)) {
                freeCars(Cars, count);
                free(Cars);
                return 0;
            }
        }
        
        
        if(handleArguments(argc, argv, &Cars, &count)) {
            freeCars(Cars, count);
            free(Cars);
            return 0;
        }
    }

    
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

        scanf(" %c", &choice);

        if(choice=='Q' || choice=='q') break;
        else if(choice=='L' || choice=='l') listCars(Cars, count);
        else if(choice=='G' || choice=='g') searchByFuel(Cars, count);
        else if(choice=='T' || choice=='t') searchByType(Cars, count);
        else if(choice=='M' || choice=='m') searchByBrand(Cars, count);
        else if(choice=='S' || choice=='s') sortByYear(Cars, count);
        else if(choice=='P' || choice=='p') sortByPrice(Cars, count);
        else if(choice=='A' || choice=='a') addCar(Cars, &count);
        else if(choice=='D' || choice=='d') deleteCar(Cars, &count);
        else printf("Invalid choice!\n");

        
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

   
    freeCars(Cars, count);
    free(Cars);
    return 0;
}