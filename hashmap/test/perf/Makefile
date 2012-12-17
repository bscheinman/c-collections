CC=gcc
CFLAGS=-ansi -pedantic -Wall -Werror -O3

CPPC=g++
CPPFLAGS=-std=c++0x -O3

all: hash_insert_test std_hash_insert_test

hash_insert_test: hash_insert_test.o ../../hashmap.o
	$(CC) $(CFLAGS) hash_insert_test.o ../../hashmap.o -o $@

std_hash_insert_test: std_hash_insert_test.o
	$(CPPC) $(CPPFLAGS) std_hash_insert_test.o -o $@

hash_insert_test.o: hash_insert_test.c
	$(CC) $(CFLAGS) -c hash_insert_test.c -o $@

std_hash_insert_test.o: std_hash_insert_test.cpp
	$(CPPC) $(CPPFLAGS) -c std_hash_insert_test.cpp -o $@

clean:
	rm -f *.o
