**Design Decisions**
*  Most decisions made for this project came from constraints given in the project description.
*  Mostly float types were used in this project, specifically price, amount, calories, and color were given float types.
*  One main() function, located in FinalMain.cpp, was utilized in this project that called functions in external C++ files.
*  Correct command line input is checked to ensure the user gave an input text file. If not correct, error is printed to stderr and program terminates.
*  The file is checked after attempt at opening to ensure file exists. If it does not exist, error is printed to stderr and program terminates.
*  The makefile was complete with two targets: all and clean.
*  The all target was designed for ease of use and by project constraints. This allows users to make all necessary files with a simple command.
*  The clean target was designed for ease of use and by project constraints. This allows users to clean the directory of unnecessary files when done with program.
*  The following standard libraries were used to complete this program: <stdio.h>, <stdlib.h>, <string>, <string.h>, "Candy.h","inventory.h", <iostream>, <math.h> 

**Inventory.h**
*  This file includes the declaration of the struct store which is used to model the entire store's inventory. This includes keeping track of:
*  candies, the total price of the store, the number of Jelly candies, the number of Caramel candies, the number of Chocolate candies, and the number of Hard candies.

**Candy.h**
*  This file includes the declaration of the C++ classes utilized in this program. This includes: Candy, Jelly, Caramel, Chocolate, and Hard.
*  Candy is inherited by the rest of the classes.
*  Candy includes a default constructor, a constructor which allows for all user inputs to be initialized, a deconstructor, and an assignment operator.
*  Candy includes the protected members: (char *) name, int candyType (1: jelly, 2: caramel, 3: chocolate, 4: hard), (char *) priceType (piece or pound), (float) price, (float) amount, (float) calories, (float) totalPrice (of the specific candy), and (float) color.
*  Candy includes the following getters and setters utilized in finalMain.cpp: getName(), getTotalPrice(), getAmount(), getPriceType(), and setTotalPrice().

**Candy.cpp**
*  This file includes the execution of the constructors and methods declared in Candy.h.
*  All subclasses of Candy utilize Candy's Constructor to set the necessary user-inputted values.
*  calculateTotalPrice() ensures their is a correct unit conversion from pounds to ounces when calculating the total price of a candy in pounds.
*  addToInventory() adds the candy's totalCost to the store's overall total cost and ensures the correct count of candy type is increased by one.
*  addToInventory() utilizes polymorphism to ensure the correct count of the candy type is updated.

**finalMain.cpp**
*  This file includes the main function that handles all user interaction and calls the correct functions from Candy.cpp as necessary.
*  main() first checks for correct command line input from user and checks the file can be opened correctly.
*  getNumCandies() is called to find the number of candies in the given input file. It then resets the file pointer to correct placement to reread the file.
*  main() then creates the store structure that is used to model the entire store.
*  A while loop is used to read the file and set the correct candy type to the Candy array in the store struct. This is possible do to polymorphism.
*  Once the entire input file is read, each candy is added to the store struct by calling the addToInventory() function from Candy.cpp. Again, this is possible do to polymorphism.
*  In order to output the candies in highest to lowest totalCost, the Candy array in the store struct is read through and the highest totalCost is found. 
*  Once the totalCost is found, it is outputted with the necessary information about the candy and then the totalCost is set to -1.
*  This is repeated until all Candies are outputted.
*  Finally, the summaries of the total cost and number of each type of candy is outputted from the store struct values. 

**Author: Marissa Gustafson**

