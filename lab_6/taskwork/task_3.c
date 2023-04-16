//динамический массив

#include <stdio.h>

int s;
char tmp;
int pos;
void print(char *array);
void append(char *array, char *tmp);
void insert(char *array, char *tmp, int pos);


void main() {
    printf("Сколько будет элементов в массиве?: ");
    scanf("%i", &s);
    char arr[s];
    for (int m = 0; m < s; m++) {
        printf("%c", arr);
        printf("Введите символ: ");
        scanf(" %c", &tmp);
        arr[m] = tmp;
    }
    //проверка работы функции append:
    append(&arr, "t");
    print(&arr);
    append(&arr, " ");
    print(&arr);
    append(&arr, "3");
    print(&arr);
    append(&arr, "z");
    print(&arr);
    append(&arr, "r");
    print(&arr);

    //проверка работы функции insert:
    insert(&arr, "t", 3);
    print(&arr);
    insert(&arr, "4", 5);
    print(&arr);
    insert(&arr, "e", 1);
    print(&arr);
    //проверка работы функции insert при некорректных вводах pos(pos < 0 или pos > size):
    insert(&arr, "t", 99);
    print(&arr);
    insert(&arr, "t", -11);
    print(&arr);
}

void print(char *array) {
    for (int m = 0; m < s; m++) {
        printf("arr[%i]: %c \n", (m + 1), *(array + m));
    }
}

void append(char *array, char *tmp) {
    s++;
    *(array + s - 1) = *tmp;

}

void insert(char *array, char *tmp, int pos) {
    if (pos < 0 || pos > s + 1) {
        printf("Невозможно выполнить операцию: задания позиция выходит за пределы массива!\n");
    }

    else {
        s++;
        for (int m = 1; m <= s; m++) {
            if ((s - m) == (pos - 1)) {
                *(array + s - m) = *tmp;
                break;
            }
            else {
                *(array + s - m) = *(array + s - m - 1);
            }
        }
    }
}