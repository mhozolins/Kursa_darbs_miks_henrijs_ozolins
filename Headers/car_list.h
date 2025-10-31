#ifndef CAR_LIST_H
#define CAR_LIST_H

struct car_list {
    char Brand[100];
    char Model[100];
    int year;
    int price;
    int km;
    float engine_size;
    char gas_type[50];
    char car_type[50];
    int prev_owners;
};

#endif
