CC=gcc
CFLAGS=-ansi -pedantic -Wall -Werror -O0 -g

all: vectest

vectest: vectest.o ../vector.o
	$(CC) $(CFLAGS) vectest.o ../vector.o -o $@

vectest.o: vectest.c
	$(CC) $(CFLAGS) -c vectest.c -o $@

clean:
	rm -f *.o
