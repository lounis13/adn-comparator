cmake_minimum_required(VERSION 3.24)
project(adn_comparator C)

set(CMAKE_C_STANDARD 11)

add_executable(adn_comparator main.c sequence/sequence.c sequence/sequence.h sequence/distance.c sequence/distance.h sequence/nucleotide.c sequence/nucleotide.h util/file.c util/file.h family/family.c family/family.h util/sorted_hash_map.c util/sorted_hash_map.h util/sorted_linked_list.c util/sorted_linked_list.h view/view.c view/view.h)
