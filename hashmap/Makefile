CC=gcc
CFLAGS=-ansi -pedantic -Wall -Werror -O0 -g

all: hashmap.o
	$(MAKE) -C ./test all

hashmap.o: hashmap.h hashmap.c
	$(CC) $(CFLAGS) -c hashmap.c -o $@

clean:
	$(MAKE) -C ./test clean
