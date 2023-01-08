cmake_minimum_required(VERSION 3.24)
project(adn_comparator C)

set(CMAKE_C_STANDARD 11)

add_executable(adn_comparator main.c sequence.c sequence.h distance.c distance.h nucleotide.c nucleotide.h file.c file.h family.c family.h double_hash_map.c double_hash_map.h sorted_linked_list.c sorted_linked_list.h)
