#Makefile for 20-Questions

CC = g++
CFLAGS = -std=c++11 -Wall 

all: Animals.o main.o
	$(CC) $(CFLAGS) -o 20Questions Animals.o main.o

main.o: main.cpp
	$(CC) -c main.cpp

Animals.o: Animals.cpp
	$(CC) -c Animals.cpp 	

test:
	./20Questions

clean:
	rm -f *.o 20-Questions



