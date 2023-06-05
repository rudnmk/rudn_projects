#include <stdio.h>
#include <stdlib.h>

//матрицы задаются в файлах matrix_1(LEFT).txt и matrix_2(RIGHT). Они могут быть любой размерности. Главное, чтобы последняя строка не заканчивалась /n
//т.к. подсчеты будут немного съежать


int* check_sizes(FILE* m_1, FILE* m_2);


void main() {
    FILE* m_1 = fopen("matrix_1(LEFT).txt", "r");
    FILE* m_2 = fopen("matrix_2(RIGHT).txt", "r");
    FILE* m_3 = fopen("matrix_3(RESULT).txt", "a");
    //FILE* result = fopen("result.txt", "a");
    int *arr = check_sizes(m_1, m_2);
    int row_1 = arr[0];
    int col_1 = arr[1];
    int row_2 = arr[2];
    int col_2 = arr[3];
    //int nums[100];
    int count = 0;
    if (col_1 != row_2) {
        printf("Размерности матриц не позволяют подсчитать произведение! Кол-во столбцов первой(левой) матрицы должно быть равно кол-ву строк второй(правой) матрицы");
    }
    else {
        char i;
        char j;
        int cursor_1 = 0;
        int cursor_2 = 0;
        for (cursor_1; cursor_1 < ((row_1 * 2 * col_1) + row_1 - 1); cursor_1 = cursor_1 + (2 * col_1) + 1 ) { //cursor_1 < 20; cursor_1 += 7
            int c = 0;
            for (int step = 0; step < (2 * col_2); step = step + 2) { //step < 6; step += 2
                cursor_2 = step;
                for (int tmp = 0; tmp < (2 * col_2); tmp = tmp + 2) { //tmp < 6; tmp += 2
                    fseek(m_1, cursor_1, SEEK_SET);
                    fseek(m_2, cursor_2, SEEK_SET);
                    i = fgetc(m_1);
                    j = fgetc(m_2);
                    int num_1 = i - '0';
                    int num_2 = j - '0';
                    c = c + (num_1 * num_2);
                    cursor_1 = cursor_1 + 2;
                    cursor_2 = cursor_2 + (2 * col_1) + 1;
                }
                //nums[count] = c;
                count++;
                fprintf(m_3, "%i ", c);
                c = 0;
                cursor_1 = cursor_1 - (2 * row_1);
            }
            //nums[count] = 82;
            count++;
            fprintf(m_3, "\n");
        }
    }
    
    // rewind(m_1);
    // rewind(m_2);
    // int ct = 0;
    // for (int r = 0; r < row_1; r++) {
    //     char c;
    //     char row[1000];
    //     int k = 0;
    //     while ((c = fgetc(m_1)) != '\n') {
    //         if (c == '\0') {
    //             continue;
    //         }
    //         else {
    //             row[k] = c;
    //             k++;
    //         }
    //     }
    //     if (r == (row_1 / 2)) {
    //         row[k] = ' ';
    //         k++;
    //         row[k] = ' ';
    //         k++;
    //         row[k] = 'X';
    //         k++;
    //         row[k] = ' ';
    //         k++;
    //         row[k] = ' ';
    //         k++;
    //     }
    //     else {
    //         row[k] = ' ';
    //         k++;
    //         row[k] = ' ';
    //         k++;
    //         row[k] = ' ';
    //         k++;
    //         row[k] = ' ';
    //         k++;
    //         row[k] = ' ';
    //         k++;
    //     }
    //     while((c = fgetc(m_2)) != '\n') {
    //         row[k] = c;
    //         k++;
    //     }
    //     if (r == (row_1 / 2)) {
    //         row[k] = ' ';
    //         k++;
    //         row[k] = ' ';
    //         k++;
    //         row[k] = '=';
    //         k++;
    //         row[k] = ' ';
    //         k++;
    //         row[k] = ' ';
    //         k++;
    //     }
    //     else {
    //         row[k] = ' ';
    //         k++;
    //         row[k] = ' ';
    //         k++;
    //         row[k] = ' ';
    //         k++;
    //         row[k] = ' ';
    //         k++;
    //         row[k] = ' ';
    //         k++;
    //     }
    //     int n;
    //     while((n = nums[ct]) != 82) {
    //         row[k] = n;
    //         k++;
    //         ct++;
    //     row[k] = '\n';
    //     fprintf(result, "%s", row);
    //     }
    // }

    fclose(m_1);
    fclose(m_2);
    fclose(m_3);
    //fclose(result);
}

int* check_sizes(FILE* m_1, FILE* m_2) {
    //Матрица m_1 имеет размеры A x B, а матрица m_2 имеет размеры C x D. Начинаться матрица должна с числа и между числами должен быть 1 пробел.
    //Числа должны быть в диапазоне от 0 до 9!
    int A = 0;
    int B = 0;
    int C = 0;
    int D = 0;
    int fl = 0;
    char c;
    while ((c = fgetc(m_1)) != EOF) {
        if (c != '\n' && fl == 0) {
            if (c != ' ') {
                A++;
            }
        }
        else {
            fl = 1;
            if (c == '\n') {
                B++;
            }
        }
    }
    B++;
    fl = 0;
    while ((c = fgetc(m_2)) != EOF) {
        if (c != '\n' && fl == 0) {
            if (c != ' ') {
                C++;
            }
        }
        else {
            fl = 1;
            if (c == '\n') {
                D++;
            }
        }
    }
    D++;
    int *temp = (int*)malloc(sizeof(int) * 4);
    *temp = A;
    *(temp + 1) = B;
    *(temp + 2) = C;
    *(temp + 3) = D;
    return temp;
}
