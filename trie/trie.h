#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct trie {
    struct trie *children[ALPHABET_SIZE];
} trie;


trie *trie_init(void);
bool trie_insert(trie *, char *);
bool trie_contains(trie *, char *);
void trie_print(trie *, char *prefix);
void trie_dispose(trie *);


#endif /* TRIE_H */
