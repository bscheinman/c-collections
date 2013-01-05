#include "trie.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


trie *trie_init(void)
{
    trie *t = malloc(sizeof(trie));
    if (!t) return NULL;
    memset(t->children, 0, sizeof(t->children));
    return t;
}


bool trie_insert(trie *t, char *s)
{
    char c;
    trie **next;
    bool trie_created = false, result;

    c = tolower(*s);

    /* this won't be reached recursively but we can consider the empty string to
       be trivially contained in every trie */
    if (c == '\0') return true;

    /* reject strings with non-alphabetic characters */
    if (c < 'a' || c > 'z') return false;

    /* find appropriate child next level down */
    next = t->children + c - 'a';

    /* create new child if necessary */
    if (!*next) {
        *next = trie_init();
        if (!*next) return false;
        trie_created = true;
    }

    /* if this is the last character of the string, we only "inserted" if we created a new child */
    if (*(s + 1) == '\0') {
        return trie_created;
    } else { /* otherwise, continue downwards in the trie */
        result = trie_insert(*next, s + 1);
        if (!result && trie_created) {
            /* if recursive insert failed and the child node was created just for this entry, remove it */
            free(*next);
            *next = NULL;
        }
        return result;
    }

}


bool trie_contains(trie *t, char *s)
{
    trie *child;
    char c = tolower(*s);

    /* if we've reached the end of the string, then it must be contained in the trie */
    if (!t || c == '\0') return true;

    /* the trie cannot contain non-alphabetic strings */
    if (c < 'a' || c > 'z') return false;

    child = t->children[c - 'a'];

    /* if there isn't a matching child then the word isn't in the trie */
    if (!child) return false;

    /* otherwise, check child node */
    return trie_contains(child, s + 1);

}


void trie_print(trie *t, char *prefix)
{
    size_t prefix_length = strlen(prefix);
    char *entry = malloc(sizeof(char) * (prefix_length + 2));
    trie **child;
    int i;
    
    strcpy(entry, prefix);
    entry[prefix_length + 1] = '\0';
    for (i = 0 ; i < ALPHABET_SIZE ; ++i) {
        child = t->children + i;
        if (*child) {
            entry[prefix_length] = 'a' + i;
            printf("%s\n", entry);
            trie_print(*child, entry);
        }
    }
    free(entry);
}


void trie_dispose(trie *t)
{
    trie **child;
    int i;
    for (i = 0 ; i < ALPHABET_SIZE ; ++i) {
        child = t->children + i;
        if (*child) {
            trie_dispose(*child);
            *child = NULL;
        }
    }
    free(t);
}
