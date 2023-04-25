#include <stdio.h>
#include <string.h>


void vowels_and_consonants_count(char *ch, int size);


void main() {
    char str[1024];
    printf("Введите слово: ");
    scanf("%s", str);
    int size = strlen(str);
    printf("%i\n", size);
    char *pChar = &str;
    vowels_and_consonants_count(pChar, size);
}

void vowels_and_consonants_count(char *ch, int size) {
    int vowel_count = 0;
    int consonant_count = 0;

    for (int i = 0; i < size; i++) {
        if (*(ch + i) == 'a' || *(ch + i) == 'e' || *(ch + i) == 'i' || *(ch + i) == 'o' || *(ch + i) == 'u') {
            vowel_count++;
        }
        else {
            consonant_count++;
        }
    }
    printf("Число гласных: %i, число согласных: %i", vowel_count, consonant_count);
}