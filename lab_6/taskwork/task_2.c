#include <stdio.h>
 
int placement();

void main() {
    placement();
}

int placement() {
    int flag = 0;
    int arr[3][3] = {{ 1,2,3 }, { 4,5,6 }, { 7,8,9 }};
    int num;
    printf("Введите число: ");
    scanf("%i", &num);

    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++) {
        for (int j = 0; j < (sizeof(arr[i]) / sizeof(arr[i][0])); j++) {
            if (arr[i][j] == num) {
                int x = i + 1;
                int y = j + 1;
                printf("Ваше число находится в %i-ой строке и %i-ом столбце", x, y);
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0) {
        printf("Такого числа нет.");
    }
}