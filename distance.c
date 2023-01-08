#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "distance.h"
#include "sequence.h"


void update_dmin(DISTANCE *distance, int i_first, int i_second, double d);

DISTANCE distance_init(int capacity) {
    SEQUENCE *sequences = malloc(sizeof(SEQUENCE) * capacity);
    double **distances = malloc(sizeof(double *) * capacity);
    if (distances == NULL || sequences == NULL) {
        perror("malloc sequences or distances");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < capacity; ++i) {
        // + 2 pour stocker la distance minimale et l'occurrence de cette distance
        distances[i] = malloc(sizeof(double) * (i + 1 + 2));
        if (distances == NULL || sequences == NULL) {
            perror("malloc distances[i]");
            exit(EXIT_FAILURE);
        }
        distances[i][i] = 0.0;
    }
    return (DISTANCE) {0, capacity, sequences, distances, 0};
}

void distance_add(DISTANCE *distance, SEQUENCE sequence) {
    int index = distance->size;
    if (index >= distance->capacity) {
        perror("Distance is full");
        return;
    }
    distance->sequences[index] = sequence;
    for (int i = 0; i <= index; ++i) {
        double d = compute_distance(sequence, distance->sequences[i]);
        distance->distances[index][i] = d;
        if (d > distance->max_distance) distance->max_distance = d;
        update_dmin(distance, index, i, d);
    }
    (distance->size)++;
}

void update_dmin(DISTANCE *dis, int i_first, int i_second, double d) {
    double first_dmin = get_dmin(dis, i_first);
    double second_dmin = get_dmin(dis, i_second);
    if (d == first_dmin) {
        dis->distances[i_first][i_first + 1] += 1.0;
    }
    if (d == second_dmin) {
        dis->distances[i_second][i_second + 1] += 1.0;
    }
    if (d < first_dmin) {
        dis->distances[i_first][i_first] = d;
        dis->distances[i_first][i_first + 1] = 1.0;
    }
    if (d < second_dmin) {
        dis->distances[i_second][i_second] = d;
        dis->distances[i_second][i_second + 1] = 1.0;
    }
}

double get_dmin(DISTANCE *distance, int index) {
    return distance->distances[index][index];
}

int get_dmin_occurrence(DISTANCE *distance, int index) {
    return (int) distance->distances[index][index + 1];
}


void distance_print(DISTANCE distance) {
    for (int i = 0; i < distance.size; ++i) {
        for (int j = 0; j <= i; ++j) {
            printf("%2.2f\t", distance.distances[i][j]);
        }
        printf("\n");
    }
}

double distance_get_distance(DISTANCE distance, int first, int second) {
    // TODO
    if (first > second) return distance.distances[first][second];
    return distance.distances[second][first];
}

SEQUENCE distance_get_sequence(DISTANCE distance, int index) {
    if (index >= distance.size) {
        perror("error distance_get_sequence because (index >= distance.size)");
        exit(EXIT_FAILURE);
    }
    return distance.sequences[index];
}

bool check_index(DISTANCE *distance, int index) {
    return index >= distance->capacity || index < 0;
}

