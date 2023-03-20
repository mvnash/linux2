CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

all: exA exB exC

exA: exA.o utils_v2.o
	gcc $(CFLAGS) -o exA exA.o utils_v2.o

exA.o: exA.c utils_v2.h
	gcc $(CFLAGS) -c exA.c

exB: exB.o utils_v2.o
	gcc $(CFLAGS) -o exB exB.o utils_v2.o

exB.o: exB.c utils_v2.h
	gcc $(CFLAGS) -c exB.c

exC: exC.o utils_v2.o
	gcc $(CFLAGS) -o exC exC.o utils_v2.o

exC.o: exC.c utils_v2.h
	gcc $(CFLAGS) -c exC.c

utils_v2.o: utils_v2.c utils_v2.h
	gcc $(CFLAGS) -c utils_v2.c

clean:
	rm -f *.o
	rm -f exA exB exC