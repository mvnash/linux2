CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

lireEtEcrire: lireEtEcrire.o utils_v2.o
	gcc $(CFLAGS) -o lireEtEcrire lireEtEcrire.o utils_v2.o

lireEtEcrire.o: lireEtEcrire.c utils_v2.h
	gcc $(CFLAGS) -c lireEtEcrire.c

utils_v2.o: utils_v2.c utils_v2.h
	gcc $(CFLAGS) -c utils_v2.c

clean:
	rm -f *.o
	rm -f lireEtEcrire test
