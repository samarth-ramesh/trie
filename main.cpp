#include <iostream>
#include "trie.h"

int main() {
    node::root_t *root = node::init();
    node::word_t word1 = node::word_t();
    word1.rank = 1;
    word1.word = "test";
    node::add(root, &word1, "test");

    node::word_t word2 = node::word_t();
    word2.rank = 2;
    word2.word = "test";
    node::add(root, &word2, "test");


    node::print(root);
}
