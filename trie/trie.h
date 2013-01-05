#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct trie {
    struct trie *children[ALPHABET_SIZE];
    unsigned is_word:1;
} trie;


trie *trie_init(void);
bool trie_insert(trie *, char *);
bool trie_contains(trie *, char *);

/* if print_all is true, print internal, non-word nodes as well */
void trie_print(trie *, char *prefix, bool print_all);
void trie_dispose(trie *);


#endif /* TRIE_H */
