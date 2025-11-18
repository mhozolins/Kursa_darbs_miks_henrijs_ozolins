#ifndef CAR_LIST_H
#define CAR_LIST_H

struct car_list {
    char *Brand;           // Dynamic string
    char *Model;           // Dynamic string  
    int year;
    int price;
    int km;
    float engine_size;
    char *gas_type;        // Dynamic string
    char *car_type;        // Dynamic string
    int prev_owners;
};

#endif