//
// Created by samar on 2021-10-02.
//

#include <stdio.h>

#include <jansson.h>


#include "init.h"
#include "initTrie.h"


parent_t *initFromJson() {
    parent_t *root = init();

    json_error_t err;
    json_t *jval = json_load_file("./books.json", 0, &err);
    size_t index;
    json_t *item;

    json_array_foreach(jval, index, item) {
        if (index > 2) break;

        json_t *bookIdObj = json_object_get(item, "id");
        json_int_t bookId = json_integer_value(bookIdObj);
        json_decref(bookIdObj);

        json_t *bookTitleObj = json_object_get(item, "title");
        const char *title = json_string_value(bookTitleObj);

        json_t *bookNormalObj = json_object_get(item, "normal");
        const char *normal = json_string_value(bookNormalObj);

        initTrie_add(root, normal, title);

        json_decref(bookTitleObj);
        json_decref(bookNormalObj);

    }
    json_decref(jval);
    return root;
}