CFLAGS=-std=c11 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE

all : encryptPolybe decryptPolybe

cryptPolybe.o : cryptPolybe.c cryptPolybe.h
	cc $(CFLAGS) -c cryptPolybe.c

encryptPolybe.o : encryptPolybe.c cryptPolybe.h utils_v1.h
	cc $(CFLAGS) -c encryptPolybe.c

decryptPolybe.o : decryptPolybe.c cryptPolybe.h utils_v1.h
	cc $(CFLAGS) -c decryptPolybe.c

utils_v1.o : utils_v1.c utils_v1.h
	cc $(CFLAGS) -c utils_v1.c

encryptPolybe : encryptPolybe.o cryptPolybe.o utils_v1.o
	cc $(CFLAGS) -o encryptPolybe encryptPolybe.o cryptPolybe.o utils_v1.o

decryptPolybe : decryptPolybe.o cryptPolybe.o utils_v1.o
	cc $(CFLAGS) -o decryptPolybe decryptPolybe.o cryptPolybe.o utils_v1.o

clean :
	rm -f *.o
	rm -f encryptPolybe
	rm -f decryptPolybe