CC=gcc

CCFLAGS=-D_DEFAULT_SOURCE -D_XOPEN_SOURCE -D_BSD_SOURCE -std=c11 -pedantic -Wvla -Wall -Werror

ALL= aspirateur

all: $(ALL)

aspirateur : aspirateur.o utils_v2.o
	$(CC) $(CCFLAGS) -o aspirateur aspirateur.o utils_v2.o
aspirateur.o: aspirateur.c
	$(CC) $(CCFLAGS) -c aspirateur.c

utils_v2.o: utils_v2.c utils_v2.h
	$(CC) $(CCFLAGS) -c utils_v2.c

clean:
	rm -f *.o
	rm -f *.html
	rm -f $(ALL)		