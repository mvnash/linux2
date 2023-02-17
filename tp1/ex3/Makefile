CFLAGS=-std=c11 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE

all : encryptMorse decryptMorse

cryptMorse.o : cryptMorse.c cryptMorse.h
	cc $(CFLAGS) -c cryptMorse.c

encryptMorse.o : encryptMorse.c cryptMorse.h utils_v1.h
	cc $(CFLAGS) -c encryptMorse.c

decryptMorse.o : decryptMorse.c cryptMorse.h utils_v1.h
	cc $(CFLAGS) -c decryptMorse.c

utils_v1.o : utils_v1.c utils_v1.h
	cc $(CFLAGS) -c utils_v1.c

encryptMorse : encryptMorse.o cryptMorse.o utils_v1.o
	cc $(CFLAGS) -o encryptMorse encryptMorse.o cryptMorse.o utils_v1.o

decryptMorse : decryptMorse.o cryptMorse.o utils_v1.o
	cc $(CFLAGS) -o decryptMorse decryptMorse.o cryptMorse.o utils_v1.o

clean :
	rm -f *.o
	rm -f encryptMorse
	rm -f decryptMorse