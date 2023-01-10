#ifndef ADN_COMPARATOR_DISTANCE_H
#define ADN_COMPARATOR_DISTANCE_H

#include "sequence.h"

#define MAX_DISTANCE 0XFFFF

typedef struct DISTANCE {
    int size;
    int capacity;
    SEQUENCE *sequences;
    double **distances;
    double max_distance;
} DISTANCE;

DISTANCE distance_init(int capacity);

void distance_add(DISTANCE *distance, SEQUENCE sequence);

double distance_get_distance(DISTANCE distance, int first, int second);

SEQUENCE distance_get_sequence(DISTANCE distance, int index);

void distance_print(DISTANCE distance);

double *get_dmin(DISTANCE *distance, int index);

int get_dmin_occurrence(DISTANCE *distance, int index);

void distance_free(DISTANCE *distance);

#endif //ADN_COMPARATOR_DISTANCE_H
