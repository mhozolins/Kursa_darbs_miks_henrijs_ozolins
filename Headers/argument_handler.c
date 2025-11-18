#include <stdio.h>
#include <stdlib.h>
#include "same_string.h"
#include "add_del_op.h"
#include "list_op.h"
#include "search_op.h"
#include "utils.h"

int matchesAny(const char *str, const char *options[], int count) {
    for(int i = 0; i < count; i++) {
        if(sameString(str, options[i])) return 1;
    }
    return 0;
}

int handleArguments(int argc, char *argv[], struct car_list **Cars, int *count) {
    if(argc < 2) return 0; // no command -> menu

    const char *cmd = argv[1];

    // LIST
    if(sameString(cmd, "list")) {
        listCars(*Cars, *count);
        return 1;
    }

    // ADD
    else if(sameString(cmd, "add")) {
        if(argc != 11) {
            printf("ERROR: Missing arguments!\n");
            printf("Usage: ./car_list add BRAND MODEL YEAR PRICE KM ENGINE GAS TYPE OWNERS\n");
            return 1;
        }

        struct car_list car;
        
        // Allocate memory for strings and copy them
        car.Brand = malloc(strLength(argv[2]) + 1);
        car.Model = malloc(strLength(argv[3]) + 1);
        car.gas_type = malloc(strLength(argv[8]) + 1);
        car.car_type = malloc(strLength(argv[9]) + 1);
        
        strCopy(car.Brand, argv[2]);
        strCopy(car.Model, argv[3]);
        strCopy(car.gas_type, argv[8]);
        strCopy(car.car_type, argv[9]);

        car.year = atoi(argv[4]);
        car.price = atoi(argv[5]);
        car.km = atoi(argv[6]);
        car.engine_size = atof(argv[7]);
        car.prev_owners = atoi(argv[10]);

        if(*count >= 200) {
            printf("Catalog is full!\n");
            // Free allocated memory
            free(car.Brand);
            free(car.Model);
            free(car.gas_type);
            free(car.car_type);
            return 1;
        }

        (*Cars)[*count] = car;
        (*count)++;
        saveCars(*Cars, *count);
        printf("Car added successfully!\n");
        return 1;
    }

    else if(sameString(cmd, "delete")) {
        if(argc != 4) {
            printf("ERROR: Missing arguments!\n");
            printf("Usage: ./car_list delete BRAND MODEL\n");
            return 1;
        }

        const char *brand = argv[2];
        const char *model = argv[3];

        int newCount = 0;
        for(int i=0; i<*count; i++) {
            if(!(sameString((*Cars)[i].Brand, brand) && sameString((*Cars)[i].Model, model))) {
                (*Cars)[newCount++] = (*Cars)[i];
            } else {
                // Free memory of deleted car
                free((*Cars)[i].Brand);
                free((*Cars)[i].Model);
                free((*Cars)[i].gas_type);
                free((*Cars)[i].car_type);
            }
        }

        if(newCount == *count) {
            printf("Car not found!\n");
        } else {
            *count = newCount;
            saveCars(*Cars, *count);
            printf("Car deleted successfully!\n");
        }
        return 1;
    }

    else if(sameString(cmd, "sort")) {
        const char *brand = "";
        const char *field = "price";
        const char *sortOrder = "cheapest";

        if(argc > 2) brand = argv[2];
        if(argc > 3) field = argv[3];
        if(argc > 4) sortOrder = argv[4];

        struct car_list *filtered = malloc(200 * sizeof(struct car_list));
        if (filtered == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        
        // Initialize filtered array pointers to NULL
        for(int i = 0; i < 200; i++) {
            filtered[i].Brand = NULL;
            filtered[i].Model = NULL;
            filtered[i].gas_type = NULL;
            filtered[i].car_type = NULL;
        }
        
        int fcount = 0;
        for(int i=0; i<*count; i++) {
            if(brand[0] == '\0' || sameString((*Cars)[i].Brand, brand)) {
                // Allocate memory and copy the car
                filtered[fcount].Brand = malloc(strLength((*Cars)[i].Brand) + 1);
                filtered[fcount].Model = malloc(strLength((*Cars)[i].Model) + 1);
                filtered[fcount].gas_type = malloc(strLength((*Cars)[i].gas_type) + 1);
                filtered[fcount].car_type = malloc(strLength((*Cars)[i].car_type) + 1);
                
                strCopy(filtered[fcount].Brand, (*Cars)[i].Brand);
                strCopy(filtered[fcount].Model, (*Cars)[i].Model);
                strCopy(filtered[fcount].gas_type, (*Cars)[i].gas_type);
                strCopy(filtered[fcount].car_type, (*Cars)[i].car_type);
                
                filtered[fcount].year = (*Cars)[i].year;
                filtered[fcount].price = (*Cars)[i].price;
                filtered[fcount].km = (*Cars)[i].km;
                filtered[fcount].engine_size = (*Cars)[i].engine_size;
                filtered[fcount].prev_owners = (*Cars)[i].prev_owners;
                
                fcount++;
            }
        }

        if(fcount == 0) {
            printf("No cars found for brand '%s'\n", brand);
            // Free any allocated memory in filtered array
            for(int i = 0; i < fcount; i++) {
                free(filtered[i].Brand);
                free(filtered[i].Model);
                free(filtered[i].gas_type);
                free(filtered[i].car_type);
            }
            free(filtered);
            return 1;
        }

        const char *petrolTypes[] = {"Petrol", "petrol", "Gasoline", "gasoline", "Gas", "gas"};
        const char *dieselTypes[] = {"Diesel", "diesel", "Deisel", "deisel"};
        int petrolCount = 6;
        int dieselCount = 4;

        // Bubble sort
        for(int i=0; i<fcount-1; i++) {
            for(int j=i+1; j<fcount; j++) {
                int swap = 0;

                if(sameString(field, "price")) {
                    if(sameString(sortOrder, "cheapest") && filtered[i].price > filtered[j].price)
                        swap = 1;
                    else if(sameString(sortOrder, "expensive") && filtered[i].price < filtered[j].price)
                        swap = 1;
                }
                else if(sameString(field, "year")) {
                    if(sameString(sortOrder, "newest") && filtered[i].year < filtered[j].year)
                        swap = 1;
                    else if(sameString(sortOrder, "oldest") && filtered[i].year > filtered[j].year)
                        swap = 1;
                }
                else if(sameString(field, "km")) {
                    if(sameString(sortOrder, "lowest") && filtered[i].km > filtered[j].km)
                        swap = 1;
                    else if(sameString(sortOrder, "highest") && filtered[i].km < filtered[j].km)
                        swap = 1;
                }
                else if(sameString(field, "gas")) {
                    if(sameString(sortOrder, "petrol") || sameString(sortOrder, "gasoline")) {
                        int iIsPetrol = matchesAny(filtered[i].gas_type, petrolTypes, petrolCount);
                        int jIsPetrol = matchesAny(filtered[j].gas_type, petrolTypes, petrolCount);
                        int iIsDiesel = matchesAny(filtered[i].gas_type, dieselTypes, dieselCount);
                        int jIsDiesel = matchesAny(filtered[j].gas_type, dieselTypes, dieselCount);
                        
                        if(jIsPetrol && !iIsPetrol) swap = 1;
                        else if(!iIsPetrol && !jIsPetrol && jIsDiesel && !iIsDiesel) swap = 1;
                    }
                    else if(sameString(sortOrder, "diesel")) {
                        int iIsDiesel = matchesAny(filtered[i].gas_type, dieselTypes, dieselCount);
                        int jIsDiesel = matchesAny(filtered[j].gas_type, dieselTypes, dieselCount);
                        int iIsPetrol = matchesAny(filtered[i].gas_type, petrolTypes, petrolCount);
                        int jIsPetrol = matchesAny(filtered[j].gas_type, petrolTypes, petrolCount);
                        
                        if(jIsDiesel && !iIsDiesel) swap = 1;
                        else if(!iIsDiesel && !jIsDiesel && jIsPetrol && !iIsPetrol) swap = 1;
                    }
                    else {
                        if(caseInsensitiveCompare(filtered[i].gas_type, filtered[j].gas_type) > 0)
                            swap = 1;
                    }
                }
                else if(sameString(field, "owners")) {
                    if(sameString(sortOrder, "lowest") && filtered[i].prev_owners > filtered[j].prev_owners)
                        swap = 1;
                    else if(sameString(sortOrder, "highest") && filtered[i].prev_owners < filtered[j].prev_owners)
                        swap = 1;
                }
                else if(sameString(field, "type")) {
                    if(caseInsensitiveCompare(filtered[i].car_type, filtered[j].car_type) > 0)
                        swap = 1;
                }
                else if(sameString(field, "engine")) {
                    if(sameString(sortOrder, "smallest") && filtered[i].engine_size > filtered[j].engine_size)
                        swap = 1;
                    else if(sameString(sortOrder, "largest") && filtered[i].engine_size < filtered[j].engine_size)
                        swap = 1;
                }

                if(swap) {
                    struct car_list tmp = filtered[i];
                    filtered[i] = filtered[j];
                    filtered[j] = tmp;
                }
            }
        }

        listCars(filtered, fcount);
        
        // Free filtered array memory
        for(int i = 0; i < fcount; i++) {
            free(filtered[i].Brand);
            free(filtered[i].Model);
            free(filtered[i].gas_type);
            free(filtered[i].car_type);
        }
        free(filtered);
        return 1;
    }

    else if(sameString(cmd, "search")) {
        if(argc < 3) {
            printf("ERROR: Missing search type!\n");
            printf("Usage: ./car_list search [fuel|type|brand] [value]\n");
            return 1;
        }

        const char *searchType = argv[2];
        const char *searchValue = (argc > 3) ? argv[3] : "";

        if(sameString(searchType, "fuel")) {
            if(argc < 4) {
                printf("ERROR: Missing fuel type!\n");
                printf("Usage: ./car_list search fuel [petrol|diesel|gasoline]\n");
                return 1;
            }
            printf("Cars with fuel type '%s':\n", searchValue);
            int found = 0;
            for(int i=0; i<*count; i++) {
                if(sameString((*Cars)[i].gas_type, searchValue)) {
                    printf("\nBrand: %s\nModel: %s\nYear: %d\nPrice: %d\nKM: %d\n"
                           "Engine: %.1f\nGas: %s\nType: %s\nPrevious Owners: %d\n",
                           (*Cars)[i].Brand, (*Cars)[i].Model, (*Cars)[i].year, (*Cars)[i].price,
                           (*Cars)[i].km, (*Cars)[i].engine_size, (*Cars)[i].gas_type,
                           (*Cars)[i].car_type, (*Cars)[i].prev_owners);
                    found = 1;
                }
            }
            if(!found) printf("No cars found with fuel type '%s'\n", searchValue);
        }
        else if(sameString(searchType, "type")) {
            if(argc < 4) {
                printf("ERROR: Missing car type!\n");
                printf("Usage: ./car_list search type [sedan|suv|coupe|hatchback]\n");
                return 1;
            }
            printf("Cars of type '%s':\n", searchValue);
            int found = 0;
            for(int i=0; i<*count; i++) {
                if(sameString((*Cars)[i].car_type, searchValue)) {
                    printf("\nBrand: %s\nModel: %s\nYear: %d\nPrice: %d\nKM: %d\n"
                           "Engine: %.1f\nGas: %s\nType: %s\nPrevious Owners: %d\n",
                           (*Cars)[i].Brand, (*Cars)[i].Model, (*Cars)[i].year, (*Cars)[i].price,
                           (*Cars)[i].km, (*Cars)[i].engine_size, (*Cars)[i].gas_type,
                           (*Cars)[i].car_type, (*Cars)[i].prev_owners);
                    found = 1;
                }
            }
            if(!found) printf("No cars found of type '%s'\n", searchValue);
        }
        else if(sameString(searchType, "brand")) {
            if(argc < 4) {
                printf("ERROR: Missing brand!\n");
                printf("Usage: ./car_list search brand [brand_name]\n");
                return 1;
            }
            printf("Cars from brand '%s':\n", searchValue);
            int found = 0;
            for(int i=0; i<*count; i++) {
                if(sameString((*Cars)[i].Brand, searchValue)) {
                    printf("\nBrand: %s\nModel: %s\nYear: %d\nPrice: %d\nKM: %d\n"
                           "Engine: %.1f\nGas: %s\nType: %s\nPrevious Owners: %d\n",
                           (*Cars)[i].Brand, (*Cars)[i].Model, (*Cars)[i].year, (*Cars)[i].price,
                           (*Cars)[i].km, (*Cars)[i].engine_size, (*Cars)[i].gas_type,
                           (*Cars)[i].car_type, (*Cars)[i].prev_owners);
                    found = 1;
                }
            }
            if(!found) printf("No cars found from brand '%s'\n", searchValue);
        }
        else {
            printf("ERROR: Unknown search type '%s'\n", searchType);
            printf("Available search types: fuel, type, brand\n");
            return 1;
        }
        return 1;
    }

    else if(sameString(cmd, "help")) {
        printf("\n=== CAR MANAGEMENT SYSTEM - COMMAND REFERENCE ===\n\n");
        
        printf("LIST ALL CARS:\n");
        printf("  ./car_list list\n\n");
        
        printf("ADD A CAR:\n");
        printf("  ./car_list add BRAND MODEL YEAR PRICE KM ENGINE GAS TYPE OWNERS\n");
        printf("  Example: ./car_list add Toyota Corolla 2020 15000 5000 1.8 Petrol Sedan 1\n\n");
        
        printf("DELETE A CAR:\n");
        printf("  ./car_list delete BRAND MODEL\n");
        printf("  Example: ./car_list delete BMW M3\n\n");
        
        printf("SORT CARS:\n");
        printf("  ./car_list sort [BRAND] [FIELD] [ORDER]\n");
        printf("  Fields: price, year, km, gas, owners, type, engine\n");
        printf("  Orders: cheapest/expensive, newest/oldest, lowest/highest, petrol/diesel/alphabetical\n");
        printf("  Examples:\n");
        printf("    ./car_list sort BMW price cheapest\n");
        printf("    ./car_list sort Honda year newest\n");
        printf("    ./car_list sort '' gas petrol\n");
        printf("    ./car_list sort '' owners lowest\n\n");
        
        printf("SEARCH CARS:\n");
        printf("  ./car_list search [fuel|type|brand] [value]\n");
        printf("  Examples:\n");
        printf("    ./car_list search fuel Petrol\n");
        printf("    ./car_list search type SUV\n");
        printf("    ./car_list search brand Toyota\n\n");
        
        printf("SINGLE LETTER COMMANDS:\n");
        printf("  ./car_list M BMW        # Search by brand\n");
        printf("  ./car_list G Petrol     # Search by fuel\n");
        printf("  ./car_list T SUV        # Search by type\n");
        printf("  ./car_list L            # List all cars\n");
        printf("  ./car_list S            # Sort by year\n");
        printf("  ./car_list P            # Sort by price\n");
        printf("  ./car_list A            # Add car (interactive)\n");
        printf("  ./car_list D            # Delete car (interactive)\n");
        printf("  ./car_list Q            # Quit\n\n");
        
        printf("INTERACTIVE MODE:\n");
        printf("  ./car_list              # No arguments for interactive menu\n\n");
        
        return 1;
    }

    printf("ERROR: Unknown command '%s'\n", cmd);
    printf("Use './car_list help' to see available commands.\n");
    return 1;
}