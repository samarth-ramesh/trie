//
// Created by srinivas on 10/2/21.
//

#ifndef AUTOCOMPLETE_TRIE_H
#define AUTOCOMPLETE_TRIE_H

#define ALPHA_SIZE 26
#define MAX_ITEMS 2

#include <array>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

namespace node {

    typedef struct word_s {
        std::string word;
        int rank;
    } word_t;

    struct CompareRank {
        bool operator()(const word_s &w1, const word_s &w2) {
            return w1.rank > w2.rank;
        }
    };

    typedef struct node_s {
        std::array<node_s *, ALPHA_SIZE> children{};
        std::priority_queue<word_t, std::vector<word_t>, CompareRank> words;
        char c = 0;
    } node_t;

    typedef struct root_s {
        std::array<node_t *, ALPHA_SIZE> children;
    } root_t;

    node::root_t *init();

    void add(root_t *root, word_t *word, char *normal);

    void print(root_t *root);

}
#endif //AUTOCOMPLETE_TRIE_H
