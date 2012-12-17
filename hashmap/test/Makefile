CC=gcc
CFLAGS=-ansi -pedantic -Wall -Werror -O0 -g

all: hashtest hashtest_str
	$(MAKE) -C ./perf all

hashtest: hashtest.o ../hashmap.o
	$(CC) $(CFLAGS) hashtest.o ../hashmap.o -o $@

hashtest_str: hashtest_str.o ../hashmap.o
	$(CC) $(CFLAGS) hashtest_str.o ../hashmap.o -o $@

hashtest.o: hashtest.c
	$(CC) $(CFLAGS) -c hashtest.c -o $@

hashtest_str.o: hashtest_str.c
	$(CC) $(CFLAGS) -c hashtest_str.c -o $@

clean:
	rm -f *.o
	$(MAKE) -C ./perf clean
