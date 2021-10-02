cmake_minimum_required(VERSION 3.19)
project(autocomplete C)

set(CMAKE_C_STANDARD 11)
LINK_LIBRARIES(jansson)

add_executable(autocomplete main.c initTrie.c initTrie.h init.c init.h)
