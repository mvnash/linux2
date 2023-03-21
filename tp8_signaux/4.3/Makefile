CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

all: minusculeToMaj

minusculeToMaj: minusculeToMaj.o utils_v2.o
	gcc $(CFLAGS) -o minusculeToMaj minusculeToMaj.o utils_v2.o

minusculeToMaj.o: minusculeToMaj.c utils_v2.h
	gcc $(CFLAGS) -c minusculeToMaj.c

utils_v2.o: utils_v2.c utils_v2.h
	gcc $(CFLAGS) -c utils_v2.c

clean:
	rm -f *.o
	rm -f minusculeToMaj