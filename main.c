#include <stdio.h>
#include "trie.h"

void callback(char * string){
    printf("%s", string);
}

int main() {
    parent_t *root = init();
    add(root, "test");
    add(root, "atest");
    iterate(root, callback);
    return 0;
}
