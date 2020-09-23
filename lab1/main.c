#include <stdio.h>
#include <stdlib.h>
#include <count.h>

int main()
{
    char * fname = count();
    FILE * input = fopen(fname, "r");
    if (input == NULL) {
        perror ("Cannot open file");
        return EXIT_FAILURE;
    }
    short int i, SIZE = 26;
    int * counters  = (int*) malloc(SIZE * sizeof(int));
    for (i = 0; i < SIZE; i++)
        counters[i] = 0;
    char c;
    int count, total = 0, max = 0;
    while (fscanf(input, "%c %d\n", &c, &count) != EOF) {
        //printf("%c %d\n", c, count);
        counters[c - 'a'] = count;
        total += count;
        if (max < count)
            max = count;
    }
    fclose (input);
    for (i = 0; i < SIZE; i++)
        if (counters[i]) {
            printf("%c %3d%% ", i + 'a', counters[i] * 100 / total);
            int j, LINE_LENGTH = 70;
            for (j = 0; j <= counters[i] * LINE_LENGTH / max; j++)
                printf("#");
            printf("\n");
        }
    free(counters);
    return 0;
}
