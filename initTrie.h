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
    char *word;
} node_t;

typedef struct trie_parent {
    node_t *children[26];
} parent_t;

parent_t *init();

typedef void (*callback_t)(char *);


void initTrie_add(parent_t *root, const char *normalWord, const char *word);

void initTrie_iterateNode(node_t *node, callback_t callback, char *prefix);

void initTrie_iterateTree(parent_t *root, callback_t callback);

node_t *initTrie_getNodeByPrefix(const char *prefix, parent_t *root);

void initTrie_deleteTree(parent_t* root);

#define AUTOCOMPLETE_TRIE_H

#endif //AUTOCOMPLETE_TRIE_H
