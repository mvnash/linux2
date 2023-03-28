CFLAGS = -std=c11 -pedantic -Wall -Wvla -Werror -Wno-unused-variable -D_DEFAULT_SOURCE

ALL= ex5.1 ex5.2 ex5.3

all: $(ALL)

ex5.1: ex5.1.c utils_v2.o
	gcc $(CFLAGS) -o ex5.1 ex5.1.c utils_v2.o

ex5.2: ex5.2.c utils_v2.o
	gcc $(CFLAGS) -o ex5.2 ex5.2.c utils_v2.o

ex5.3: ex5.3.c utils_v2.o
	gcc $(CFLAGS) -o ex5.3 ex5.3.c utils_v2.o

utils_v2.o: utils_v2.c utils_v2.h
	gcc $(CFLAGS) -c utils_v2.c

clean:
	rm -f *.o
	rm -f $(ALL)