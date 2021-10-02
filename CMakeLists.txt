cmake_minimum_required(VERSION 3.19)
project(autocomplete C)

set(CMAKE_C_STANDARD 11)

find_package(jansson CONFIG REQUIRED)

add_executable(autocomplete main.c trie.c trie.h init.c init.h)
target_link_libraries(autocomplete PRIVATE jansson::jansson)
