CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

ex2B: ex2B.o utils_v2.o
	gcc $(CFLAGS) -o ex2B ex2B.o utils_v2.o

ex2B.o: ex2B.c utils_v2.h
	gcc $(CFLAGS) -c ex2B.c

utils_v2.o: utils_v2.c utils_v2.h
	gcc $(CFLAGS) -c utils_v2.c

clean:
	rm -f *.o
	rm -f ex2B
