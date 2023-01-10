#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../util/file.h"
#include "sequence.h"

#define min2(a, b) ( ((a)<(b)) ? (a) : (b) )
#define min3(a, b, c) ( min2 ( (min2 (a,b) ) , (c) ) )


SEQUENCE sequence_from_file(const char *filename) {
    char *content = read_file_content(filename);
    SEQUENCE sequence = sequence_parse(content);
    if (!content || !sequence.nucleotides) {
        free(content);
        free(sequence.nucleotides);
        perror(" error when read_file");
        exit(EXIT_FAILURE);
    }
    free(content);
    return sequence;
}

void sequence_print(SEQUENCE sequence) {
    for (int i = 0; i < sequence.length; ++i) {
        printf(" %c", sequence.nucleotides[i]);
    }
    puts("");
}

SEQUENCE sequence_parse(const char *char_sequence) {
    int size = (int) strlen(char_sequence);
    NUCLEOTIDE *nucleotides = malloc(sizeof(NUCLEOTIDE) * size);
    for (int i = 0; i < size; ++i) {
        nucleotides[i] = char_to_nucleotide(char_sequence[i]);
        if (nucleotides[i] == UNKNOWN) {
            free(nucleotides);
            perror("UNKNOWN nucleotides");
            return (SEQUENCE) {NULL, size};
        }
    }
    return (SEQUENCE) {nucleotides, size};;
}

double compute_distance(SEQUENCE seq1, SEQUENCE seq2) {

    double memo[seq1.length + 1][seq2.length + 1];

    for (int i = 0; i < seq1.length + 1; i++) {
        for (int j = 0; j < seq2.length + 1; j++) {
            if (i == 0) memo[i][j] = (double) (j * 1.5);
            else if (j == 0) memo[i][j] = (double) (i * 1.5);
            else {
                double f1 = memo[i - 1][j - 1] + nucleotide_distance(seq1.nucleotides[i - 1], seq2.nucleotides[j - 1]);
                double f2 = memo[i - 1][j] + 1.5;
                double f3 = memo[i][j - 1] + 1.5;

                memo[i][j] = min3(f1, f2, f3);
            }
        }
    }
    return memo[seq1.length][seq2.length];

}

void sequence_free(SEQUENCE sequence) {
    free(sequence.nucleotides);
}

