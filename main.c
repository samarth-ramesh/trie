#include <stdio.h>
#include "trie.h"

void callback(char * string){
    printf("%s\n", string);
}

int main() {
    parent_t *root = init();
    add(root, "test");
    add(root, "testa");
    add(root, "atest");
    iterate_tree(root, callback);
    return 0;
}
