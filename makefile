MATH_FLAG = -lm
EXECUTABLES = candy

all: candy

candy: finalMain.o Candy.o
	g++ finalMain.o Candy.o -o candy  $(MATH_FLAG)

finalMain.o: finalMain.cpp Candy.cpp
	g++ finalMain.cpp -c

Candy.o: Candy.cpp
	g++ Candy.cpp -c

clean:
	rm *.o $(EXECUTABLES)
