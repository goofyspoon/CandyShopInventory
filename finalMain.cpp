#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "Candy.h"
#include "inventory.h"
#include <iostream>
#include <math.h>
using namespace std;


//Marissa Gustafson, COMS 327 Final

//Prototypes:
int getNumCandies(FILE * file);

int main(int argc, char *argv[]){

    //Check for valid input
    if(argc < 2){
        fprintf(stderr, "No input file given. Correct format is candy <filename>. Please try again.");
        return 0;
    }

    //open file for reading
    FILE * fp = fopen(argv[1], "r");

    if(fp == NULL){
        fprintf(stderr, "Could not open file\n\n");
        return 0;
    }

    //Count how many candies are listed in .txt file
    int numCandies = getNumCandies(fp);

    //Create an array to hold all the candy:
    store * storePtr = new store;
    storePtr ->inventory = (Candy *)malloc(sizeof(Candy)*numCandies);


    //Go through file and insert candies into store inventory
    int count = 0;
    int maxChars = 255;
    char *line = new char[maxChars];
    char *name = new char[maxChars];
    char *type = new char[maxChars];
    char *priceType = new char[maxChars];
    char *price= new char[maxChars];
    char *color= new char[maxChars];
    char *amount= new char[maxChars];
    char *calories= new char[maxChars];

    while(feof(fp) == 0){
        //Read in a line, if it is START then read in as a candy
        fgets(line, 250, fp);
        if(strncmp(line, "START", 5) == 0){
            //Found a new candy!

            //Read in the name
            fgets(name, maxChars, fp);
            name[strlen(name)-1] = '\0';

            //Read in the candy type
            fgets(type, maxChars, fp);

            //Read in the price type
            fgets(priceType, maxChars, fp);

            //Read in the price
            fgets(price, maxChars, fp);

            //Read in the color
            fgets(color, maxChars, fp);

            //Read in the amount
            fgets(amount, maxChars, fp);

            //Read in the calories
            fgets(calories, maxChars, fp);
            if(strncmp(type, "jelly", 5) == 0){
                //cout<<"jelly"<<endl;
                storePtr -> inventory[count] = Jelly(name, priceType, stof(price), stof(amount), stof(calories), stof(color));
            }else if(strncmp(type, "caramel",7) == 0){
                //cout<<"caramel"<<endl;
                //Caramel's only color options is 0, ensure no matter what user inputs, 0 is set for color
                storePtr -> inventory[count] = Caramel(name, priceType, stof(price), stof(amount), stof(calories), 0);
            }else if(strncmp(type, "chocolate", 9) == 0){
                //cout<<"chocolate"<<endl;
                //Chocolates's only color options is 0, ensure no matter what user inputs, 0 is set for color
                storePtr -> inventory[count] = Chocolate(name, priceType, stof(price), stof(amount), stof(calories), 0);
            }else if(strncmp(type, "hard",4) == 0){
                //cout<<"hard"<<endl;
                storePtr -> inventory[count] = Hard(name, priceType, stof(price), stof(amount), stof(calories), stof(color));
            }
            count++;
        }
        //Free pointers used and re-allocate memory
        line = NULL;
        name = NULL;
        type = NULL;
        priceType = NULL;
        line = new char[maxChars];
        name = new char[maxChars];
        type = new char[maxChars];
        priceType = new char[maxChars];
        price= new char[maxChars];
        color= new char[maxChars];
        amount= new char[maxChars];
        calories= new char[maxChars];
    }

    //Free memory used
    free(line);
    free(name);
    free(type);
    free(priceType);

    //Add each candy to store's overall inventory, stored in store struct
    for(int i = 0; i< numCandies; i++){
        storePtr->inventory[i].addToInventory(storePtr);
    }

    //Print out each candy info in order of most expensive to least expensive to buy all candy
    float maxTotal;
    int maxIndex;
    printf("\nStore Inventory:\n\n");
    for(int i = 0; i<numCandies; i++){
        //Each loop, set maxTotal equal to the first index and set maxIndex accordingly
        maxTotal = storePtr ->inventory[0].getTotalPrice();
        maxIndex = 0;
        for(int j = 0; j<numCandies; j++){
            if(storePtr ->inventory[j].getTotalPrice() > maxTotal){
                //If the total price of this candy is more than current maxTotal, maxTotal gets the higher value and update maxIndex
                maxTotal = storePtr ->inventory[j].getTotalPrice();
                maxIndex = j;
            }
        }

        //Next highest price total is found, print name to console:
        printf("Candy Name: %s", storePtr ->inventory[maxIndex].getName());
        //Weird formatting issue with fgets, I played around with it and its not the most pretty, but the following for loop fixes it:
        for(int k = 0; k < strlen(storePtr ->inventory[maxIndex].getName())/2; k++){
            printf("\t");
        }
        //Print candy's amount in store and total price:
        printf("--amount in store: %.2f", storePtr ->inventory[maxIndex].getAmount());
        if(strncmp(storePtr ->inventory[maxIndex].getPriceType(), "piece", 5) == 0){
            printf(" pieces");
        }else{
            printf(" lbs");
        }
        printf(", total price: $%.2f\n", storePtr ->inventory[maxIndex].getTotalPrice());
        storePtr->inventory[maxIndex].setTotalPrice(-1);
    }

    printf("\n----------------------------------------------------------------------------------------\n\n");
    //Print the rest of the values from the information stored in the store struct:
    printf("Total Value of All Candy in Inventory: $%.2f\n", storePtr->priceOfStore);

    printf("Total Number of Jelly Candies: %d\n", storePtr->numJelly);
    printf("Total Number of Caramel Candies: %d\n", storePtr->numCaramel);
    printf("Total Number of Chocolate Candies: %d\n", storePtr->numChocolate);
    printf("Total Number of Hard Candies: %d\n", storePtr->numHard);

    //Free the pointers in the struct, deconstructor will take care of class deletion
    free(storePtr->inventory);
    free(storePtr);
    printf("\nReport Complete.\n");

}

/**
 * Reads through the input file and returns the number of candies found in the file
 * Rewinds the file pointer so its ready to be read again
 * */
int getNumCandies(FILE * file){
    int count = 0;
    int maxChars = 255;
    char *line = (char *)malloc(sizeof(char)*maxChars);
    while(feof(file) == 0){
        fscanf(file, "%s", line);
        if(strcmp(line, "START") == 0){
            count++;
        }
        line = NULL;
        line = (char *)malloc(sizeof(char)*maxChars);
    }
    free(line);
    rewind(file);
    return count;
}