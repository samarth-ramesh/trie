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
    char prefix[MAX_LEN] = {""};
    iterate(get_node_by_prefix("tes", root), callback, prefix);
    return 0;
}
