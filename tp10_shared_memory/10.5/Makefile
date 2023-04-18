CFLAGS = -std=c11 -pedantic -Wall -Wvla -Werror -Wno-unused-variable -D_DEFAULT_SOURCE

ALL= train switch admin3

all: $(ALL)

train: train.o utils_v2.o
	gcc $(CFLAGS) -o train train.o utils_v2.o

admin3: admin3.o utils_v2.o
	gcc $(CFLAGS) -o admin3 admin3.o utils_v2.o

switch: switch.o utils_v2.o
	gcc $(CFLAGS) -o switch switch.o utils_v2.o

switch.o: switch.c ipc_conf.h
	gcc $(CFLAGS) -c switch.c

admin3.o: admin3.c ipc_conf.h
	gcc $(CFLAGS) -c admin3.c

train.o: train.c ipc_conf.h
	gcc $(CFLAGS) -c train.c

utils_v2.o: utils_v2.c utils_v2.h
	gcc $(CFLAGS) -c utils_v2.c

clean:
	rm -f *.o
	rm -f $(ALL)