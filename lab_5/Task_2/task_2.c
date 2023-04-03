#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

char str[50];
int intStr;
char *getInput(void);
bool testInput(char[50]);
int strToInt(char[50]);
void printInt(int);


void main() {

    getInput();
    if (testInput(str)) {
        strToInt(str);
        printInt(intStr);
    }
    else {
        printf("Невозможно преобразовать данную строку в целое число.");
    }

}


char *getInput() {
    printf("Введите текст: ");
    scanf("%s", &str);
    return(str);
}

bool testInput(char[50]) {
    for(int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i]) == 0 && str[i] != "." && str[i] == " ") { //я так понял, isdigit(char) считает, что русские буквы = числа (возвращает 1), поэтому если написать строку полностью на русском, выведет 1
            return false;
        }
    }
    return true;
}

int strToInt(char[50]) {
    sscanf(str, "%i", &intStr);
    return intStr;
}

void printInt(int) {
    printf("%i", intStr);
}