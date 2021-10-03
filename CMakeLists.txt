cmake_minimum_required(VERSION 3.20)
project(autocomplete)

set(CMAKE_CXX_STANDARD 20)

add_executable(autocomplete main.cpp trie.cpp trie.h)
