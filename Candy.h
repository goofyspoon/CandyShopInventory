#ifndef CANDY_H
#define CANDY_H
#include <iostream>
//using std namespace;

#ifdef __cplusplus
extern "C" {
#include <cstddef>
#include <cstring>

typedef struct store_t store;

class Candy{
    public:
        Candy();
        Candy(char * name, int type, char * priceType, float price, float amount, float calories, float color);
        ~Candy(){
            if(name != NULL){
                name = NULL;
            }
            if(priceType != NULL){
                priceType = NULL;
            }
        
        }
        const Candy& operator=(const Candy &rhs){
            if(this!= &rhs){
                if(name == NULL){
                    name = new char[250];
                }
                if(priceType == NULL){
                    priceType = new char[250];
                }
                strcpy(name, rhs.name);
                strcpy(priceType, rhs.priceType);
                candyType = rhs.candyType;
                price = rhs.price;
                amount = rhs.amount;
                calories = rhs.calories;
                totalPrice = rhs.totalPrice;
            }
            return *this;
        }

        void calculateTotalPrice();
        char * getName();
        void addToInventory(store * inventory);

    protected:
        char * name;
        int candyType; //1: jelly, 2: caramel, 3: chocolate, 4: hard
        char * priceType; //piece or pound
        float price;
        float amount; //16 ounces in a pound
        float calories;
        float totalPrice;
        float color; //valid input 0-9
};

class Jelly: public Candy{
    public:
    Jelly(char * name, char * priceType, float price, float amount, float calories, float color);

    //void addToInventory(store * inventory);

};

class Caramel: public Candy{
    public:
    Caramel(char * name, char * priceType, float price, float amount, float calories, float color);

    //void addToInventory(store * inventory);

};

class Chocolate: public Candy{
    public:
    Chocolate(char * name, char * priceType, float price, float amount, float calories, float color);

    //void addToInventory(store * inventory);

};

class Hard: public Candy{
    public:
    Hard(char * name, char * priceType, float price, float amount, float calories, float color);

    //void addToInventory(store * inventory);

};

}
#endif
#endif