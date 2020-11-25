MATH_FLAG = -lm
EXECUTABLES = candy

all: candy

candy: finalMain.o input.o Candy.o
	g++ finalMain.o input.o Candy.o -o candy  $(MATH_FLAG)

finalMain.o: finalMain.cpp input.c Candy.cpp
	g++ finalMain.cpp -c

input.o: input.c
	gcc input.c -c

Candy.o: Candy.cpp
	g++ Candy.cpp -c

clean:
	rm *.o $(EXECUTABLES)
