CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

all: heartbeat

heartbeat: heartbeat.o utils_v2.o
	gcc $(CFLAGS) -o heartbeat heartbeat.o utils_v2.o

heartbeat.o: heartbeat.c utils_v2.h
	gcc $(CFLAGS) -c heartbeat.c

utils_v2.o: utils_v2.c utils_v2.h
	gcc $(CFLAGS) -c utils_v2.c

clean:
	rm -f *.o
	rm -f heartbeat