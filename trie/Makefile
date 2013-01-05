CC=gcc
CFLAGS=-ansi -pedantic -Wall -Werror -O0 -g

all: trie.o
	$(MAKE) -C ./test all

trie.o: trie.h trie.c
	$(CC) $(CFLAGS) -c trie.c -o $@

clean:
	rm -f *.o
	$(MAKE) -C ./test clean
