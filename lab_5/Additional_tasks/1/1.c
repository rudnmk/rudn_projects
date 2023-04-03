#include <stdio.h>

int test();
void positive();
void negative();

void main() {
    int num = test();

    if (num > 0) {
        positive();
    }
    else if (num < 0) {
        negative();
    }
    else {
        printf("Нуль");
    }
}

int test() {
    int a;
    printf("Введите число: ");
    scanf("%i", &a);
    return a;
}

void positive() {
    printf("Положительно");
}

void negative() {
    printf("Отрицательно");
}