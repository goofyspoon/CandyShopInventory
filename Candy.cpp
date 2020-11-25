#include "inventory.h"
#include <iostream>
#include <cmath>
#include <cstring>

/**
 * Candy Default Constructor
 * */
Candy::Candy(){}

/**
 * Constructor with necessary inputs, utilized by subclasses to set correct values,
 * Calls calculateTotalPrice to store this information based on price and amount inputs
 * */
Candy::Candy(char * n, int type, char * pType, float p, float a, float cc, float c){
    this->name = new char[250];
    this->priceType = new char[250];
    strcpy(this->name, n);
    this->candyType = type; //1: jelly, 2: caramel, 3: chocolate, 4: hard
    strcpy(this->priceType, pType);
    this->price = p;
    this->amount = a; //16 ounces in a pound
    this->calories = cc;
    this->color = c;
    this->calculateTotalPrice();
}

/**
 * Calculates the total price of all of "this" type of candy.
 * If priced by pound, convert amount from ounces to pounds to find totalPrice
 * */
void Candy::calculateTotalPrice(){
    if(strncmp(this->priceType, "piece", 5) == 0){
        //priced by piece
        this->totalPrice = this->price * this->amount;
    }else{
        //priced by ounce
        this->totalPrice = this->price * this->amount / 16;
    }
}

/**
 * Adds the totalPrice of the candy to the overall store price (stored in the store struct) and
 * Increases the number of the type of candy in the store by one
 * */
void Candy::addToInventory(store * inventory){
   inventory->priceOfStore += this->totalPrice;
   //1: jelly, 2: caramel, 3: chocolate, 4: hard
   if(this->candyType == 1){
       //Jelly
       inventory-> numJelly++;
   }else if(this->candyType == 2){
       //Caramel
       inventory-> numCaramel++;
   }else if(this->candyType == 3){
       //Chocolate
       inventory-> numChocolate++;
   }else if(this->candyType == 4){
       //Hard
       inventory-> numHard++;
   }
}

/**
 * Returns the name of "this" candy
 * */
char * Candy::getName(){
    return this->name;
}

/**
 * Returns the total price of "this" candy
 * */
float Candy::getTotalPrice(){
    return this->totalPrice;
}

/**
 * Returns the amount (by piece or by pound based on price type) of "this" candy
 * */
float Candy::getAmount(){
    return this->amount;
}

/**
 * Sets the total price of "this" candy to the given total input
 * */
void Candy::setTotalPrice(float total){
    this->totalPrice = total;
}

/**
 * Returns the price type of "this" candy (either piece of pound)
 * */
char * Candy::getPriceType(){
    return this->priceType;
}

/**
 * Jelly Constructor: Utilizes the super class, Candy's, constructor
 * */
Jelly::Jelly(char * n, char * pType, float p, float a, float cc, float c):Candy(n, 1, pType, p, a, cc,c){}


/**
 * Caramel Constructor: Utilizes the super class, Candy's, constructor
 * */
Caramel::Caramel(char * n, char * pType, float p, float a, float cc, float c):Candy(n, 2, pType, p, a, cc, c){}

/**
 * Chocolate Constructor: Utilizes the super class, Candy's, constructor
 * */
Chocolate::Chocolate(char * n, char * pType, float p, float a, float cc, float c): Candy(n, 3, pType, p, a, cc, c){}

/**
 * Hard Constructor: Utilizes the super class, Candy's, constructor
 * */
Hard::Hard(char * n, char * pType, float p, float a, float cc, float c): Candy(n, 4, pType, p, a, cc, c){}
