#include <stdio.h>

int counting();

void main() {
    printf("Ответ: %i", counting());
}

int counting() {
    int max_count = 0;
    int count = 0;
    char letter;
    char string[500];
    printf("Введите слово(а): ");
    scanf("%s", string);

    printf("Введите символ: ");
    scanf(" %c", &letter);
    for (int i = 0; i < (sizeof(string) / sizeof(string[0])); i++) {
        if (string[i] == letter) {
            count++;
        }
        else {
            if (max_count < count) {
                max_count = count;
            }
            count = 0;
        }
    }
    return max_count;
}