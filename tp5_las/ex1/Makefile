CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

ecrireEntiers: ecrireEntiers.o utils_v2.o
	gcc $(CFLAGS) -o ecrireEntiers ecrireEntiers.o utils_v2.o

ecrireEntiers.o: ecrireEntiers.c utils_v2.h
	gcc $(CFLAGS) -c ecrireEntiers.c

utils_v2.o: utils_v2.c utils_v2.h
	gcc $(CFLAGS) -c utils_v2.c

clean:
	rm -f *.o
	rm -f ecrireEntiers test
