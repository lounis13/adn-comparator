#ifndef ADN_COMPARATOR_SEQUENCE_H
#define ADN_COMPARATOR_SEQUENCE_H

#include "nucleotide.h"

typedef struct {
    NUCLEOTIDE *nucleotides;
    int length;
} SEQUENCE;

/**
 * @brief Utility methode - to parse char* to sequence
 *
 * @param char_sequence char* to parse
 * @return sequence
 */
SEQUENCE sequence_parse(const char *char_sequence);

/**
 * @brief Fonction pour lire une séquence d'ADN à partir d'un fichier et la stocker
 * dans une variable de type SEQUENCE
 *
 * @param filename le nom de fichier
 * @return La nucleotides lue
 */
SEQUENCE sequence_from_file(const char *filename);

void sequence_print(SEQUENCE sequence);

void sequence_free(SEQUENCE sequence);

double compute_distance(SEQUENCE seq1, SEQUENCE seq2);

#endif //ADN_COMPARATOR_SEQUENCE_H
