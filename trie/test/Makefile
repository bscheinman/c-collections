CC=gcc
CFLAGS=-ansi -pedantic -Wall -Werror -O0 -g

all: trie_test

trie_test: trie_test.o ../trie.o
	$(CC) $(CFLAGS) trie_test.o ../trie.o -o $@

trie_test.o: trie_test.c
	$(CC) $(CFLAGS) -c trie_test.c -o $@

clean:
	rm -f *.o
