#include "nucleotide.h"


int nucleotide_index(NUCLEOTIDE nucleotide) {
    if (nucleotide == A) return 0;
    if (nucleotide == C) return 1;
    if (nucleotide == G) return 2;
    if (nucleotide == T) return 3;
    if (nucleotide == BLANC) return 4;
    return -1;
}

double nucleotide_distance(NUCLEOTIDE first, NUCLEOTIDE second) {
    return NUCLEOTIDES_DISTANCES[nucleotide_index(first)]
                                [nucleotide_index(second)];
}

int is_nucleotide(char car) {
    switch (car) {
        case 'A':
        case 'a':
        case 'C':
        case 'c':
        case 'T':
        case 't':
        case 'G':
        case 'g':
        case ' ':
        case '_':
            return 1;
        default:
            return 0;
    }
}

NUCLEOTIDE char_to_nucleotide(char car) {
    return is_nucleotide(car) ? car : UNKNOWN;
}