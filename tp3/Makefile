CFLAGS=-std=c11 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE -g

all: mainPile notationPolonaise

Pile.o : Pile.c Pile.h
	cc $(CFLAGS) -c Pile.c

utils_v1.o : utils_v1.c utils_v1.h
	cc $(CFLAGS) -c utils_v1.c

mainPile.o : mainPile.c Pile.h
	cc $(CFLAGS) -c mainPile.c

mainPile : Pile.o utils_v1.o mainPile.o
	cc $(CFLAGS) -o mainPile Pile.o utils_v1.o mainPile.o

notationPolonaise.o: Pile.o utils_v1.o notationPolonaise.c
	cc $(CFLAGS) -c notationPolonaise.c

notationPolonaise : Pile.o utils_v1.o notationPolonaise.o
	cc $(CFLAGS) -o notationPolonaise Pile.o utils_v1.o notationPolonaise.o

clean :
	rm -f *.o
	rm -f mainPile
	rm -f notationPolonaise