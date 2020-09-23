#include <stdio.h>

char* count() {
    short int i, SIZE = 26;
    int * counters  = (int*) malloc(SIZE * sizeof(int));
    for (i = 0; i < SIZE; i++)
        counters[i] = 0;
    char c;
    do {
        c = fgetc(stdin);
        if ('a' <= c && c <= 'z')
            counters[c - 'a']++;
        else if ('A' <= c && c <= 'Z')
            counters[c - 'A']++;
    } while (c != '\n');
    char* fname = "file.txt";
    freopen(fname, "w", stdout);
    for (i = 0; i < SIZE; i++)
        if (counters[i])
            fprintf(stdout, "%c %d\n", i + 'a', counters[i]);
    freopen("CON", "w", stdout);
    free(counters);
    return fname;
}
