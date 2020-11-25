#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "input.h"
#include "Candy.h"
#include "inventory.h"
#include <iostream>
#include <math.h>
using namespace std;


//Marissa Gustafson, COMS 327 Final
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
    printf("Number of candies is: %d\n", numCandies);

    //Create an array to hold all the candy:
    store * storePtr = new store;

    cout<<"Size candy: "<<sizeof(Candy)*numCandies<<endl;
    storePtr ->inventory = (Candy *)malloc(sizeof(Candy)*numCandies);

    cout<<"Size of inventory[0]: "<<sizeof(storePtr -> inventory[0])<<endl;

    //Go through file and insert candies into store inventory
    int count = 0;
    int maxChars = 255;
    char *line = new char[maxChars];//(char *)malloc(sizeof(char)*maxChars);
    char *name = new char[maxChars];
    char *type = new char[maxChars];
    char *priceType = new char[maxChars];
    char *price= new char[maxChars];
    char *color= new char[maxChars];
    char *amount= new char[maxChars];
    char *calories= new char[maxChars];

    while(feof(fp) == 0){
        fscanf(fp, "%s", line);
        if(strcmp(line, "START") == 0){

            //Found a new candy!
            cout <<"Found a candy"<<endl;
            //Next fscanf gets the name
            fscanf(fp, "%s", name);
            //Next fscanf gets the candy type
            fscanf(fp, "%s", type);
            //Next fscanf gets the price type
            fscanf(fp, "%s", priceType);
            //Next fscanf gets the price
            fscanf(fp, "%s", price);

            //Next fscanf gets the color
            fscanf(fp, "%s", color);

            //Next fscanf gets the amount
            fscanf(fp, "%s", amount);
            //Next fscanf gets the calories
            fscanf(fp, "%s", calories);
            if(strcmp(type, "jelly") == 0){
                cout<<"jelly"<<endl;
                storePtr -> inventory[count] = Jelly(name, priceType, stof(price), stof(amount), stof(calories), stof(color));
            }else if(strcmp(type, "caramel") == 0){
                cout<<"caramel"<<endl;
                storePtr -> inventory[count] = Caramel(name, priceType, stof(price), stof(amount), stof(calories), stof(color));
            }else if(strcmp(type, "chocolate") == 0){
                cout<<"chocolate"<<endl;
                storePtr -> inventory[count] = Chocolate(name, priceType, stof(price), stof(amount), stof(calories), stof(color));
            }else if(strcmp(type, "hard") == 0){
                cout<<"hard"<<endl;
                storePtr -> inventory[count] = Hard(name, priceType, stof(price), stof(amount), stof(calories), stof(color));
            }
            count++;
        }
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

    free(line);
    free(name);
    free(type);
    free(priceType);

    for(int i = 0; i< numCandies; i++){
        printf("%d: %s\n", i, storePtr->inventory[i].getName());
        storePtr->inventory[i].addToInventory(storePtr);
    }

    printf("Total Value of All Candy in Inventory: $%.2f\n", storePtr->priceOfStore);

    printf("Total Number of Jelly Candies: %d\n", storePtr->numJelly);
    printf("Total Number of Caramel Candies: %d\n", storePtr->numCaramel);
    printf("Total Number of Chocolate Candies: %d\n", storePtr->numChocolate);
    printf("Total Number of Hard Candies: %d\n", storePtr->numHard);

    for(int i = 0; i< numCandies; i++){
        //free(storePtr ->inventory[i].getName());
        //free(storePtr ->inventory[i]);
    }
    free(storePtr->inventory);
    free(storePtr);
    printf("Freed pointers.\n");

}

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
        //printf("%d\n", count);
    }
    free(line);
    rewind(file);
    return count;
}