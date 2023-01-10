#include <stdio.h>
#include <stdlib.h>
#include "util/file.h"
#include "sequence/sequence.h"
#include "sequence/distance.h"
#include "family/family.h"
#include "view/view.h"


int main() {

    DIRECTORY directory = directory_init("./sequences_adn");
    DISTANCE distance = distance_init(directory.size);
    for (int i = 0; i < directory.size; ++i) {
        SEQUENCE sequence = sequence_from_file(directory.filenames[i]);
        distance_add(&distance, sequence);
    }

    FAMILY_MEMBER *family_members = create_family_members(&distance);
    FAMILY_LIST families = family_list_create(&distance, family_members);

    int option;

    while (1) {
        menu();

        // Lire l'option choisie par l'utilisateur en utilisant la fonction read_option()
        option = read_option("Saisissez votre option: ", 1, 4);
        if (option == 0) continue;  // Passer à l'itération suivante de la boucle si une erreur de saisie s'est produite

        switch (option) {
            case 1:
                printf("1. Afficher les séquences ADN\n");
                for (int i = 0; i < distance.size; ++i) {
                    printf("[%.2d] => ", (i + 1));
                    sequence_print(family_members[i].sequence);
                }
                break;
            case 2:
                printf("2. Calculer la distance entre les séquences ADN\n");
                distance_print(distance);
                break;
            case 3:
                printf("3. Construire les familles\n");
                family_list_print(families);
                break;
            case 4:
                printf("Au revoir!\n");
                family_list_free(families);
                free(family_members);
                directory_free(&directory);
                distance_free(&distance);
                return 0;
        }
    }
}


