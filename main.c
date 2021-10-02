#include "init.h"
#include "stdio.h"

void callback(char *string) {
    printf("Item: %s\n", string);
}

int main() {
    parent_t *root = initFromJson();
    iterate_tree(root, callback);
    delete_tree(root);
}