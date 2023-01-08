#include "file.h"
#include "sequence.h"
#include "distance.h"
#include "double_hash_map.h"
#include "family.h"

int hash(const double *key) {
    return (int) (*key * 2);
}

int main() {

    DIRECTORY directory = directory_init("../sequences_adn");
    DISTANCE distance = distance_init(directory.size);
    for (int i = 0; i < directory.size; ++i) {
        SEQUENCE sequence = sequence_from_file(directory.filenames[i]);
        distance_add(&distance, sequence);
    }

    family_list_create(distance);
}

