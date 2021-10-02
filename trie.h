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


void add(parent_t *root, const char *normalWord, const char *word);

void iterate(node_t *node, callback_t callback, char *prefix);

void iterate_tree(parent_t *root, callback_t callback);

node_t *get_node_by_prefix(const char *prefix, parent_t *root);

void delete_tree(parent_t* parent);

#define AUTOCOMPLETE_TRIE_H

#endif //AUTOCOMPLETE_TRIE_H
