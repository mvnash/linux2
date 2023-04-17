CFLAGS = -std=c11 -pedantic -Wall -Wvla -Werror -Wno-unused-variable -D_DEFAULT_SOURCE

ALL= ecran distributeur admin

all: $(ALL)

ecran: ecran.c utils_v2.o
	gcc $(CFLAGS) -o ecran ecran.c utils_v2.o

admin: admin.c utils_v2.o
	gcc $(CFLAGS) -o admin admin.c utils_v2.o

distributeur: distributeur.c utils_v2.o
	gcc $(CFLAGS) -o distributeur distributeur.c utils_v2.o

utils_v2.o: utils_v2.c utils_v2.h
	gcc $(CFLAGS) -c utils_v2.c

clean:
	rm -f *.o
	rm -f $(ALL)