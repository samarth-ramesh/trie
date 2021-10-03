//
// Created by srinivas on 10/2/21.
//

#include <iostream>
#include "trie.h"


node::root_t *node::init() {
    auto *root = static_cast<root_t *>(malloc(sizeof(node_t)));
    for (auto &item: root->children) {
        item = nullptr;
    }
    return root;
}

node::node_t *initNode(char c) {
    auto *node = static_cast<node::node_t *>(malloc(sizeof(node::node_t)));
    for (auto &item: node->children) {
        item = nullptr;
    }
    node->c = c;
    return node;
}

int charToIndex(const char c) {
    return c - 'a';
}

node::node_t *setLetter(char c, node::node_t *item) {
    int index = charToIndex(c);
    node::node_t *child = item->children[index];
    if (child == nullptr) {
        child = initNode(c);
        item->children[index] = child;
    }
    child->c = c;
    return child;
}

void setWord(node::word_t* word, node::node_t* item){
    if (item->words.size() < MAX_ITEMS){
        item->words.push(*word);
    } else if (item->words.top().rank < word->rank) {
        item->words.pop();
        item->words.push(*word);
    }
}

void node::add(root_t *root, word_t *word, char *normal) {
    int i = 0;
    char c = normal[i];
    int itemIndex = charToIndex(c);
    node_t *curNode;
    if (root->children[itemIndex] == nullptr) {
        curNode = initNode(c);
        root->children[itemIndex] = curNode;
    }
    curNode = root->children[itemIndex];

    while (c != '\0') {
        c = normal[++i];
        setLetter(c, curNode);
        setWord(word, curNode);
        curNode = curNode->children[charToIndex(c)];
    }

}

void printQ(std::priority_queue<node::word_t, std::vector<node::word_t>, node::CompareRank> q) {
    while (!q.empty()) {
        std::cout << q.top().word << "\t" << q.top().rank << std::endl;
        q.pop();
    }
}

void nodePrint(node::node_t *node) {
    for (const auto &item: node->children) {
        if (item != nullptr) {
            nodePrint(item);
        }
    }
    printQ(node->words); // pass words by value to prevent deletion
}

void node::print(root_t *root) {
    for (const auto &item: root->children) {
        if (item != nullptr) {
            nodePrint(item);
        }
    }
}