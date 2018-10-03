CC = g++
FLAG = -std=c++11 -c -Wall -O3

all: read ini metho fin
	$(CC) *.o -o _convection
read:
	$(CC) $(FLAG) read.cpp
ini:
	$(CC) $(FLAG) initialize.cpp
metho:
	$(CC) $(FLAG) method.cpp
fin:
	$(CC) $(FLAG) convection.cpp
clean:
	rm *.o