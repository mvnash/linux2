CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

all: timer

timer: timer.o utils_v2.o
	gcc $(CFLAGS) -o timer timer.o utils_v2.o

timer.o: timer.c utils_v2.h
	gcc $(CFLAGS) -c timer.c

utils_v2.o: utils_v2.c utils_v2.h
	gcc $(CFLAGS) -c utils_v2.c

clean:
	rm -f *.o
	rm -f timer