
#ifndef ADN_COMPARATOR_FILE_H
#define ADN_COMPARATOR_FILE_H

typedef struct DIRECTORY {
    int size;
    const char *path;
    char **filenames;
} DIRECTORY;

DIRECTORY directory_init(const char *directory_path);

void directory_print(DIRECTORY directory);

char *read_file_content(const char *filename);

#endif //ADN_COMPARATOR_FILE_H
