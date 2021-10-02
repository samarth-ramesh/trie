//
// Created by samar on 2021-09-26.
//
#include <stdlib.h>
#include "initTrie.h"
#include <string.h>
#include <stdio.h>

parent_t *init() {
    parent_t *rv = malloc(sizeof(parent_t));
    for (int i = 0; i < 26; ++i) {
        rv->children[i] = NULL;
    }
    return rv;
}

void initTrie_setChildrenToNull(node_t *node) {
    for (int i = 0; i < 26; ++i) {
        node->children[i] = NULL;
    }
}

int charToIndex(char c) {
    return c - 'a';
}

node_t *initTrie_setLetter(char c, node_t *node) {
    int index = charToIndex(c);
    node_t *child = node->children[index];
    if (child == NULL) {
        // need to initialise it
        child = malloc(sizeof(node_t));
        memset(child, 0, sizeof(node_t));

        initTrie_setChildrenToNull(child);
        node->children[charToIndex(c)] = child;
    }
    child->c = c;
    return child;
}

void initTrie_add(parent_t *root, const char *normalWord, const char *word) {
    char c = normalWord[0];
    node_t *last_node;

    if (root->children[charToIndex(c)] == NULL) {
        last_node = malloc(sizeof(node_t));
        memset(last_node, 0, sizeof(node_t));

        last_node->is_eow = false;
        initTrie_setChildrenToNull(last_node);
        last_node->c = c;

        root->children[charToIndex(c)] = last_node;
    }
    last_node = root->children[charToIndex(c)];
    c = normalWord[1];
    for (int i = 1; c != '\0'; c = normalWord[++i]) {
        last_node = initTrie_setLetter(c, last_node);
    }
    last_node->is_eow = true;

    size_t newLen = strlen(word) + 1; // len of str + 1 for nul byte
    char *dest = malloc(newLen);
    memset(dest, 0, newLen);
    strncpy(dest, word, newLen - 1);

    last_node->word = dest;
}

size_t makeSize(char *string) {
    return (sizeof(char)) * (strlen(string) + 2); // one for the next char, one for nul termination
}

void initTrie_iterateNode(node_t *node, callback_t callback, char *prefix) {
    for (int i = 0; i < 26; ++i) {
        if (node->children[i] != NULL) {
            size_t newSize = makeSize(prefix);
            char *newPrefix = malloc(newSize); // alloccing a new prefix
            memset(newPrefix, 0, newSize);

            strcpy(newPrefix, prefix);
            newPrefix[strlen(prefix)] = node->c;
            initTrie_iterateNode(node->children[i], callback, newPrefix);
            free(newPrefix);
        }
    }
    if (node->is_eow) {
        size_t newSize = strlen(node->word) + 1;

        char *newString = malloc(newSize);
        memset(newString, 0, newSize);
        strncpy(newString, node->word, newSize);
        callback(newString);

        free(newString);

        return;
    }
}

void initTrie_iterateTree(parent_t *root, callback_t callback) {
    // calls a callback on each word;
    char prefix[26] = {""};
    for (int i = 0; i < 26; ++i) {
        if (root->children[i] != NULL) {
            initTrie_iterateNode((root->children[i]), callback, prefix);
        }
    }
}

void initTrie_deleteNode(node_t *node) {
    for (int i = 0; i < 26; ++i) {
        if (node->children[i] != NULL) {
            initTrie_deleteNode(node->children[i]);
        }
    }
    if (node->word != NULL) {
        free(node->word);
    }
    free(node);

}

void initTrie_deleteTree(parent_t *root) {
    for (int i = 0; i < 26; ++i) {
        if (root->children[i] != NULL) {
            initTrie_deleteNode(root->children[i]);
        }
    }
    free(root);
}

node_t *initTrie_getNodeByPrefix(const char *prefix, parent_t *root) {
    char c = prefix[0];
    node_t *curChild = root->children[charToIndex(c)];
    if (curChild != NULL) {
        int i = 1;
        for (c = prefix[i]; c != '\0'; c = prefix[++i]) {
            if (curChild->children[charToIndex(c)] == NULL) {
                return NULL;
            } else {
                curChild = curChild->children[charToIndex(c)];
            }
        }
    }
    return curChild;
}