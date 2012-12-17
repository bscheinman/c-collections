CC=gcc
CFLAGS=-ansi -pedantic -Wall -Werror -O0 -g

all: queue.o
	$(MAKE) -C ./test all

queue.o: queue.h queue.c
	$(CC) $(CFLAGS) -c queue.c -o $@

clean:
	rm -f *.o
	$(MAKE) -C ./test clean
