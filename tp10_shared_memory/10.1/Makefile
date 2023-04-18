CFLAGS = -std=c11 -pedantic -Wall -Wvla -Werror -Wno-unused-variable -D_DEFAULT_SOURCE

ALL= radar dashboard

all: $(ALL)

radar: radar.c utils_v2.o
	gcc $(CFLAGS) -o radar radar.c utils_v2.o

dashboard: dashboard.c utils_v2.o
	gcc $(CFLAGS) -o dashboard dashboard.c utils_v2.o

utils_v2.o: utils_v2.c utils_v2.h
	gcc $(CFLAGS) -c utils_v2.c

clean:
	rm -f *.o
	rm -f $(ALL)