#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


void shutdown();
void readline();
void analyze_string(char *);
bool is_valid(char *);
bool check_separator(char *);

int main() {
    readline();
    return 0;
}

void shutdown() {
    fprintf(stdout, "End of work\n");
    exit(EXIT_SUCCESS);
}

void readline() {
    char input[100];
    fgets(input, 100, stdin);
    if (!strcmp("exit\n", input))
        return shutdown();
    else {
        return analyze_string(input);
    }
}

void analyze_string(char * string) {
    if (is_valid(string))
        fprintf(stdout, "%s", string);
    return readline();
}

bool is_valid(char * string) {
    return check_separator(string);
}

bool check_separator(char * original) {
    char string[100];
    strcpy(string, original);
    bool result = true;
    char separators[] = ".,?!;:\n";
    char *ptr = strtok(string, separators);
    while(ptr != NULL) {
        char t[10];
        sprintf(t, "%s", ptr);
        unsigned i;
        for(i = 0; i < strlen(t); i++)
            result &= '0' <= t[i] && t[i] <= '9';
        ptr = strtok(NULL, separators);
    }
    return result;
}
