CFLAGS=-std=c11 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE

all : encrypt decrypt

crypt.o : crypt.c crypt.h
	cc $(CFLAGS) -c crypt.c

encrypt.o : encrypt.c crypt.h utils_v1.h
	cc $(CFLAGS) -c encrypt.c

decrypt.o : decrypt.c crypt.h utils_v1.h
	cc $(CFLAGS) -c decrypt.c

utils_v1.o : utils_v1.c utils_v1.h
	cc $(CFLAGS) -c utils_v1.c

encrypt : encrypt.o crypt.o utils_v1.o
	cc $(CFLAGS) -o encrypt encrypt.o crypt.o utils_v1.o

decrypt : decrypt.o crypt.o utils_v1.o
	cc $(CFLAGS) -o decrypt decrypt.o crypt.o utils_v1.o

clean :
	rm -f *.o
	rm -f encrypt
	rm -f decrypt