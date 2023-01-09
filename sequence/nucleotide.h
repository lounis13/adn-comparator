#ifndef ADN_COMPARATOR_NUCLEOTIDE_H
#define ADN_COMPARATOR_NUCLEOTIDE_H

typedef enum NUCLEOTIDE {
    A = 'A', C = 'C', G = 'G', T = 'T', BLANC = '_', UNKNOWN
} NUCLEOTIDE;

const static double NUCLEOTIDES_DISTANCES[5][5] = {
        {0,   2,   1,   2,   1.5},
        {2,   0,   2,   1,   1.5},
        {1,   2,   0,   2,   1.5},
        {2,   1,   2,   0,   1.5},
        {1.5, 1.5, 1.5, 1.5, 1.5}
};

double nucleotide_distance(NUCLEOTIDE first, NUCLEOTIDE second);

NUCLEOTIDE char_to_nucleotide(char car);


#endif //ADN_COMPARATOR_NUCLEOTIDE_H
