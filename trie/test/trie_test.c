#include "../trie.h"

#include <stdio.h>

int main() {
    trie *t = trie_init();

    trie_insert(t, "asdf");
    trie_insert(t, "zxcv");
    trie_insert(t, "asdg");

    printf("%i\n", trie_contains(t, "asdf"));
    printf("%i\n", trie_contains(t, "qwer"));

    trie_print(t, "");

    trie_dispose(t);
    return 0;
}
