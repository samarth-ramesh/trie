//
// Created by samar on 2021-09-26.
//
#include <stdlib.h>
#include "trie.h"
#include <string.h>
#include <stdio.h>

parent_t *init(){
    parent_t *rv = malloc(sizeof(parent_t));
    for ( int i = 0; i < 26; ++i ) {
        rv->children[i] = NULL;
    }
    return rv;
}

void set_children_to_null(node_t *node){
    for ( int i = 0; i < 26; ++i ) {
        node->children[i] = NULL;
    }
}

int charToIndex(char c){
    return c - 'a';
}


node_t *set_letter(char c, node_t *node){
    int index = charToIndex(c);
    node_t *child = node->children[index];
    if ( child == NULL) {
        // need to initialise it
        child = malloc(sizeof(node_t));
        memset(child, 0, sizeof(node_t));

        set_children_to_null(child);
        node->children[charToIndex(c)] = child;
    }
    child->c = c;
    return child;
}


void add(parent_t *root, const char *word){
    char c = word[0];
    node_t *last_node;

    if ( root->children[charToIndex(c)] == NULL) {
        last_node = malloc(sizeof(node_t));
        memset(last_node, 0, sizeof(node_t));

        last_node->is_eow = false;
        set_children_to_null(last_node);
        last_node->c = c;

        root->children[charToIndex(c)] = last_node;
    }
    last_node = root->children[charToIndex(c)];

    for ( int i = 1, c = word[i]; c != '\0'; ++i, c = word[i] ) {
        last_node = set_letter(c, last_node);
    }
    last_node->is_eow = true;
}


size_t makeSize(char *string){
    return ( sizeof(char)) * ( strlen(string) + 2 ); // one for the next char, one for nul termination
}


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"


void iterate(node_t *node, callback_t callback, char *prefix){
    for ( int i = 0; i < 26; ++i ) {
        if ( node->children[i] != NULL) {
            size_t newSize = makeSize(prefix);
            char *newPrefix = malloc(newSize); // alloccing a new prefix
            memset(newPrefix, 0, newSize);

            strcpy(newPrefix, prefix);
            newPrefix[strlen(prefix)] = node->c;
            iterate(node->children[i], callback, newPrefix);
            free(newPrefix);
        }
    }
    if ( node->is_eow ) {
        size_t newSize = makeSize(prefix);

        char *newString = malloc(newSize);
        memset(newString, 0, newSize);
        strcpy(newString, prefix);
        newString[newSize - 2] = node->c;
        callback(newString);

        free(newString);
        return;
    }
}

#pragma clang diagnostic pop

void iterate_tree(parent_t *root, callback_t callback){
    // calls a callback on each word;
    char prefix[26] = {""};
    for ( int i = 0; i < 26; ++i ) {
        if ( root->children[i] != NULL) {
            iterate(( root->children[i] ), callback, prefix);
        }
    }
}
