//
// Created by samar on 2021-09-26.
//

#ifndef AUTOCOMPLETE_TRIE_H

#define MAX_LEN 30

#include "stdbool.h"

typedef struct trie_node {
    struct trie_node *children[26];
    bool is_eow;
    char c;
} node_t;

typedef struct trie_parent {
    node_t *children[26];
} parent_t;

parent_t *init();

void add(parent_t *root, const char *word);

void iterate(parent_t *root, void (*callback)(char *));

typedef void (*callback_t)(char *);

#define AUTOCOMPLETE_TRIE_H

#endif //AUTOCOMPLETE_TRIE_H
