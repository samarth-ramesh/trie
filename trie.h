//
// Created by samar on 2021-09-26.
//

#ifndef AUTOCOMPLETE_TRIE_H

#include "stdbool.h"

typedef struct trie_node {
    struct trie_node * children[26];
    bool is_eow;
} node_t;

struct trie_parent {
    node_t ** children[26];
};

#define AUTOCOMPLETE_TRIE_H

#endif //AUTOCOMPLETE_TRIE_H
