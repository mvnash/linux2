CC=gcc
CCFLAGS=-D_DEFAULT_SOURCE -D_XOPEN_SOURCE -D_BSD_SOURCE -std=c11 -pedantic -Wvla -Wall -Werror

all: server client 

server : server.o utils_v2.o
	$(CC) $(CCFLAGS) -o server server.o utils_v2.o

client : client.o utils_v2.o
	$(CC) $(CCFLAGS) -o client client.o utils_v2.o

server.o: server.c utils_v2.h messages.h
	$(CC) $(CCFLAGS) -c server.c 

client.o: client.c utils_v2.h messages.h
	$(CC) $(CCFLAGS) -c client.c

utils_v2.o: utils_v2.c utils_v2.h
	$(CC) $(CCFLAGS) -c utils_v2.c 

clear :
		clear

clean :
	rm -f *.o
	rm -f server
	rm -f client
