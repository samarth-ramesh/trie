#include "init.h"
#include "stdio.h"

void callback(char *string) {
    printf("Item: %s\n", string);
}

int main() {
    initTrie_parent_t *root = initFromJson();
    initTrie_iterateTree(root, callback);
    initTrie_deleteTree(root);
}