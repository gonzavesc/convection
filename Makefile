CC = g++
FLAG = -std=c++11 -c -Wall -O3

all: read ini metho gaus exp fin
	$(CC) *.o -o _convection
read:
	$(CC) $(FLAG) read.cpp
ini:
	$(CC) $(FLAG) initialize.cpp
metho:
	$(CC) $(FLAG) method.cpp
gaus:
	$(CC) $(FLAG) gauss.cpp
exp:
	$(CC) $(FLAG) export.cpp
fin:
	$(CC) $(FLAG) convection.cpp
clean:
	rm *.o