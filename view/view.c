#include <stdio.h>
#include <stdlib.h>

#include "view.h"


void menu() {
    printf("\n");
    printf("  ┌──────────────────────────────────────────────────────┐\n");
    printf("  │ Menu                                                 │\n");
    printf("  ├──────────────────────────────────────────────────────┤\n");
    printf("  │ 1. Afficher les séquences ADN                        │\n");
    printf("  ├──────────────────────────────────────────────────────┤\n");
    printf("  │ 2. Calculer la distance entre les séquences ADN      │\n");
    printf("  ├──────────────────────────────────────────────────────┤\n");
    printf("  │ 3. Construire les familles                           │\n");
    printf("  ├──────────────────────────────────────────────────────┤\n");
    printf("  │ 4. Quitter                                           │\n");
    printf("  └──────────────────────────────────────────────────────┘\n");
}

int read_option(const char *message, int min, int max) {
    int option = 0;
    printf("%s", message);

    // Lire l'option choisie par l'utilisateur
    if (scanf("%d", &option) != 1) {
        // Si l'utilisateur n'a pas saisi un nombre entier, nettoyer le buffer d'entrée
        // et afficher un message d'erreur
        fprintf(stderr, "Erreur de saisie. Veuillez saisir un nombre entier.\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return 0;  // Retourner 0 pour indiquer qu'une erreur de saisie s'est produite
    }

    // Vérifier que l'option choisie par l'utilisateur est valide
    if (option < min || option > max) {
        fprintf(stderr, "Option non valide. Veuillez saisir un nombre entre %d et %d.\n", min, max);
        return 0;  // Retourner 0 pour indiquer qu'une erreur de saisie s'est produite
    }

    return option;  // Retourner l'option choisie par l'utilisateur
}
