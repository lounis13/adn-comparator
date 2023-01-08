#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int directory_size(const char *directory_path) {
    int cpt = 0;
    struct dirent *dirent;
    DIR *dirp = opendir(directory_path);
    if (!dirp) {
        perror("opendir");
        exit(0);
    }
    while ((dirent = readdir(dirp)))
        if (dirent->d_name[0] != '.') cpt++;
    closedir(dirp);
    return cpt;
}

DIRECTORY directory_alloc(const char *directory_ath, int size) {
    char **filenames = malloc(sizeof(char *) * size);
    if (!filenames) {
        perror(" malloc");
        exit(EXIT_FAILURE);
    }
    return (DIRECTORY) {size, directory_ath, filenames};
}

DIRECTORY directory_init(const char *directory_path) {
    DIRECTORY directory = directory_alloc(directory_path, directory_size(directory_path));
    int i = 0;
    struct dirent *dirent;
    DIR *rep = opendir(directory_path);
    if (!rep) exit(0);
    while ((dirent = readdir(rep))) {
        if (dirent->d_name[0] != '.') {
            int filename_length = (int) (strlen(directory_path) + strlen(dirent->d_name) + 1);
            directory.filenames[i] = malloc(filename_length);
            sprintf(directory.filenames[i], "%s/%s", directory_path, dirent->d_name);
            i++;
        }
    }
    closedir(rep);
    return directory;
}

void directory_print(DIRECTORY directory) {
    for (int i = 0; i < directory.size; ++i) {
        printf(" - %s\n", directory.filenames[i]);
    }
}

char *read_file_content(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) return NULL;

    // Déterminer la taille du fichier
    fseek(fp, 0L, SEEK_END);
    int length = (int) ftell(fp);
    rewind(fp);

    char *content = malloc(length * sizeof(char));
    if (content == NULL) return NULL;

    fread(content, sizeof(char), length, fp);
    content[length] = 0;
    fclose(fp);
    return content;
}
