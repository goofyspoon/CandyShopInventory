#ifndef INVENTORY_H
#include "Candy.h"

typedef struct store_t store;

struct store_t{
    //Array of candies:
    Candy * inventory;
    //Total Value of candy in all inventory in the store:
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