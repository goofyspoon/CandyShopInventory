#ifndef INVENTORY_H
#include "Candy.h"

typedef struct store_t store;

/**
 * The struct is used to model the store's total inventory
 * */
struct store_t{
    //Array of candies available in the store:
    Candy * inventory;
    //Total Value of Candy in all inventory in the store:
    float priceOfStore;
    //Number of jelly types:
    int numJelly;
    //Number of caramel types:
    int numCaramel;
    //Number of chocolate types:
    int numChocolate;
    //Number of hard types:
    int numHard;
};

#endif