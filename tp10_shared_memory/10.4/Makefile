CFLAGS = -std=c11 -pedantic -Wall -Wvla -Werror -Wno-unused-variable -D_DEFAULT_SOURCE

ALL= client serveur admin2

all: $(ALL)

client: client.c utils_v2.o
	gcc $(CFLAGS) -o client client.c utils_v2.o

admin2: admin2.c utils_v2.o
	gcc $(CFLAGS) -o admin2 admin2.c utils_v2.o

serveur: serveur.c utils_v2.o
	gcc $(CFLAGS) -o serveur serveur.c utils_v2.o

utils_v2.o: utils_v2.c utils_v2.h
	gcc $(CFLAGS) -c utils_v2.c

clean:
	rm -f *.o
	rm -f $(ALL)