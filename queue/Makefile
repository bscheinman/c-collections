CC=gcc
CFLAGS=-ansi -pedantic -Wall -Werror -O0 -g

all: queuetest

queuetest: queuetest.o queue.o
	$(CC) $(CFLAGS) queuetest.o queue.o -o $@

queuetest.o: queuetest.c queue.c
	$(CC) $(CFLAGS) -c queuetest.c -o $@

queue.o: queue.h queue.c
	$(CC) $(CFLAGS) -c queue.c -o $@

clean:
	rm -f *.o
