#include "../trie.h"

#include <stdio.h>

int main() {
    trie *t = trie_init();

    trie_insert(t, "asdf");
    trie_insert(t, "zxcv");
    trie_insert(t, "asdg");
    trie_insert(t, "asqw");
    trie_insert(t, "zop");

    printf("%i\n", trie_contains(t, "asdf"));
    printf("%i\n", trie_contains(t, "qwer"));
    printf("%i\n", trie_contains(t, "asd"));

    trie_print(t, "", 0);
    trie_print(t, "", 1);

    trie_dispose(t);
    return 0;
}
