CC=gcc
CFLAGS=-ansi -pedantic -Wall -Werror -O0 -g

all: vector.o
	$(MAKE) -C ./test all

vector.o: vector.h vector.c
	$(CC) $(CFLAGS) -c vector.c -o $@

clean:
	rm -f *.o
	$(MAKE) -C ./test clean
