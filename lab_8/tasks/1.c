#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void main() {
    FILE* file = fopen("temp.txt", "r");
    char string[100];
    int step = 0;
    int count;
    for (int i = 0; i < 3; i++) {
        fseek(file, step, SEEK_SET);
        fgets(string, 100, file);
        int sl = strlen(string) - 1;
        if (string[sl] == '\n') {
            string[sl] = 0;
        }
        char letter = string[strlen(string) - 1];
        int j = 0;
        while (strlen(string) < 10) {
            //strcat(string, "          ");
            string[strlen(string) + j - 1] = letter;
            j++;
        }
        printf("%.10s\n", string);
        step = ftell(file);

    }
    fclose(file);
}