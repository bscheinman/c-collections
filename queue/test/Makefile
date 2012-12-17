CC=gcc
CFLAGS=-ansi -pedantic -Wall -Werror -O0 -g

all: queuetest

queuetest: queuetest.o ../queue.o
	$(CC) $(CFLAGS) queuetest.o ../queue.o -o $@

queuetest.o: queuetest.c
	$(CC) $(CFLAGS) -c queuetest.c -o $@

clean:
	rm -f *.o
