//
// Created by samar on 2021-09-26.
//

#ifndef AUTOCOMPLETE_TRIE_H

#define MAX_LEN 30

#include "stdbool.h"

typedef struct initTrie_node {
    struct initTrie_node_t *children[26];
    bool is_eow;
    char c;
    char *word;
} initTrie_node_t;

typedef struct initTrie_parent {
    initTrie_node_t *children[26];
} initTrie_parent_t;

initTrie_parent_t *init();

typedef void (*callback_t)(char *);


void initTrie_add(initTrie_parent_t *root, const char *normalWord, const char *word);

void initTrie_iterateNode(initTrie_node_t *node, callback_t callback, char *prefix);

void initTrie_iterateTree(initTrie_parent_t *root, callback_t callback);

initTrie_node_t *initTrie_getNodeByPrefix(const char *prefix, initTrie_parent_t *root);

void initTrie_deleteTree(initTrie_parent_t* root);

#define AUTOCOMPLETE_TRIE_H

#endif //AUTOCOMPLETE_TRIE_H
