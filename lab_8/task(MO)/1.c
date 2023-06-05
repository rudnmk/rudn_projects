#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void main() {
    FILE* file = fopen("temp.txt", "r");
    char string[100];
    int step = 0;
    int count;
    while (feof(file) == 0) {
        fseek(file, step, SEEK_SET);
        fgets(string, 100, file);
        int sl = strlen(string) - 1;
        if (string[sl] == '\n') {
            string[sl] = 0;
        }
        char letter = string[strlen(string) - 1];
        int j = 0;
        printf("%i символ(а/ов) - ", strlen(string));
        if (strlen(string) < 10) {
            strcat(string, "          ");
            for (int j = 0; j < 10; j++) {
                if (string[j] == ' ') {
                    string[j] = letter;
                }
            }
        }
        printf("%.10s\n", string);
        step = ftell(file);

    }
    fclose(file);
}