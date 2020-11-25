/**
 * This class is immutable and encapsulates the following information:
 * Name: This is a unique name that identifies the particular wave.
 * This class also contains the method generateSamples that creates the samples for the specified wave at the specified sample rate for the
 * specified duration: SoundSamples * generateSamples(float frequency, float samplerate, float duration)
 * This method calls generateFunction which resides in a subclass that will generate a sample of a wave given the time.
 * This means that your class.h file contains the following prototype for the class: virtual float generateFunction(float time) = 0;
 * 
 * */
#include "inventory.h"
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

Candy::Candy(){}

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

void Candy::calculateTotalPrice(){
    if(strcmp(this->priceType, "piece") == 0){
        //priced by piece
        this->totalPrice = this->price * this->amount;
    }else{
        //priced by ounce
        this->totalPrice = this->price * this->amount * 16;
    }
}

char * Candy::getName(){
    return this->name;
}

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

Jelly::Jelly(char * n, char * pType, float p, float a, float cc, float c):Candy(n, 1, pType, p, a, cc,c){}

// void Jelly::addToInventory(store * inventory){
//    inventory-> numJelly++;
//    Candy::addToInventory(inventory);
// }

Caramel::Caramel(char * n, char * pType, float p, float a, float cc, float c):Candy(n, 2, pType, p, a, cc, c){}

// void Caramel::addToInventory(store * inventory){
//    inventory-> numCaramel++;
//    Candy::addToInventory(inventory);
// }

Chocolate::Chocolate(char * n, char * pType, float p, float a, float cc, float c): Candy(n, 3, pType, p, a, cc, c){}

// void Chocolate::addToInventory(store * inventory){
//     Candy::addToInventory(inventory);
//     inventory-> numChocolate++;
// }

Hard::Hard(char * n, char * pType, float p, float a, float cc, float c): Candy(n, 4, pType, p, a, cc, c){}

// void Hard::addToInventory(store * inventory){
//    inventory-> numHard++;
//    Candy::addToInventory(inventory);
// }