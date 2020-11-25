#ifndef CANDY_H
#define CANDY_H

#ifdef __cplusplus
extern "C" {
#include <cstddef>
#include <cstring>

typedef struct store_t store;

class Candy{
    public:
        //Default Constructor:
        Candy();
        //Constructor with necessary inputs:
        Candy(char * name, int type, char * priceType, float price, float amount, float calories, float color);
        //Deconstructor:
        ~Candy(){
            if(name != NULL){
                name = NULL;
            }
            if(priceType != NULL){
                priceType = NULL;
            }
        
        }
        //Assignment operator:
        const Candy& operator=(const Candy &rhs){
            if(this!= &rhs){
                if(name == NULL){
                    //Ensure there is enough allocated memory
                    name = new char[250];
                }
                if(priceType == NULL){
                    //Ensure there is enough allocated memory
                    priceType = new char[250];
                }
                //Copy right hand side values to this object
                strcpy(name, rhs.name);
                strcpy(priceType, rhs.priceType);
                candyType = rhs.candyType;
                price = rhs.price;
                amount = rhs.amount;
                calories = rhs.calories;
                totalPrice = rhs.totalPrice;
            }
            //Return a reference to this object
            return *this;
        }

        //Calculates the total price of the candy
        void calculateTotalPrice();
        //Updates the values stored in the store struct to include the new candy
        void addToInventory(store * inventory);

        //Getters and setters necessary for finalMain.cpp
        char * getName();
        float getTotalPrice();
        float getAmount();
        void setTotalPrice(float total);
        char * getPriceType();

    protected:
        char * name; //name of candy
        int candyType; //1: jelly, 2: caramel, 3: chocolate, 4: hard
        char * priceType; //piece or pound
        float price; //price per unit (either piece or ounce) of candy
        float amount; //amount of candy in store (either piece or pound), 16 ounces in a pound
        float calories; //number of calories in one unit of candy (either piece or pound)
        float totalPrice; //total price of all of this type of candy in the store
        float color; //valid input 0-9, Chocolate and caramel will always be 0, jelly and hard may be any other valid input
};

/**
 * Jelly class inherits from Candy, no special values necessary
 * */
class Jelly: public Candy{
    public:
    Jelly(char * name, char * priceType, float price, float amount, float calories, float color);

};

/**
 * Caramel class inherits from Candy, no special values necessary
 * */
class Caramel: public Candy{
    public:
    Caramel(char * name, char * priceType, float price, float amount, float calories, float color);

};

/**
 * Chocolate class inherits from Candy, no special values necessary
 * */
class Chocolate: public Candy{
    public:
    Chocolate(char * name, char * priceType, float price, float amount, float calories, float color);

};

/**
 * Hard class inherits from Candy, no special values necessary
 * */
class Hard: public Candy{
    public:
    Hard(char * name, char * priceType, float price, float amount, float calories, float color);

};

}
#endif
#endif