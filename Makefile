CC=gcc
CFLAGS=-ansi -pedantic -Wall -O0 -g

all: vectest queuetest hashtest hashtest_str

vectest: vectest.o vector.o
	$(CC) $(CFLAGS) vectest.o vector.o -o $@

queuetest: queuetest.o queue.o
	$(CC) $(CFLAGS) queuetest.o queue.o -o $@

hashtest: hashtest.o hashmap.o
	$(CC) $(CFLAGS) hashtest.o hashmap.o -o $@

hashtest_str: hashtest_str.o hashmap.o
	$(CC) $(CFLAGS) hashtest_str.o hashmap.o -o $@

vectest.o: vectest.c
	$(CC) $(CFLAGS) -c vectest.c -o $@

queuetest.o: queuetest.c
	$(CC) $(CFLAGS) -c queuetest.c -o $@

hashtest.o: hashmap.c
	$(CC) $(CFLAGS) -c hashtest.c -o $@

hashtest_str.o: hashmap.c
	$(CC) $(CFLAGS) -c hashtest_str.c -o $@

vector.o: vector.h vector.c
	$(CC) $(CFLAGS) -c vector.c -o $@

queue.o: queue.h queue.c
	$(CC) $(CFLAGS) -c queue.c -o $@

clean:
	rm -f *.o
