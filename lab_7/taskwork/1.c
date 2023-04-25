// 1) Кол-во итераций алгоритмов сортировки:
// сортировка выбором: всего 9 итераций
// сортировка пузырьком: всего 9 итераций
// сортировка расческий: всего 7 итераций
// Не при всех массивах будет такая последовательность(сортировка выбором примерно одинакого будет работать по времени с сортировкой пузырькем, а сортировка расческой будет быстрее)
// Это зависит от величины массива, а также его содержимого(целые числа сравнивать легче)
// В общем случае, сортировка пузырьком работает по времени одинакого с сортировкой выбором. Макс. возможное время(время работы в худшем случае) сортировки пузырем и выбором 
// тоже одинакого(len_of_arr ** 2), однако, минимальное время работы(время работы в лучшем случае) сортировки пузырьком равно len_of_arr, а сортировки выбором - len_of_arr^2.
//(потому что в лучшем случае, когда массив уже отсортирован(например, [1, 2, 3, 4])), при сортировке пузырьком мы 1 раз проходимся по списку, а при сортировке выбором мы проходим
//массив len_of_arr раз.

// 2) Все 3 алгоритма выполняют сортировку за примерно одинаковое время. Это аргументируется тем, что массив очень маленьких размеров.


#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>


void selection_sort(char arr[][1024]);
void bubble_sort(char arr[][1024]);
void comb_sort(char arr[][1024]);
void swap(char arr[][1024], int i, int j);
void results(char arr[][1024], int count, double time_spent);
int size = 10;
int count = 0;


void main() {
    char arr[][1024] = {"всем", "привет", "меня", "зовут", "строка", "и", "я", "сейчас", "буду", "сортироваться"};
    printf("Выберите, каким из алгоритмов вы хотите отсортировать список? 1 - алгоритм выбором, 2 - алгоритм пузырьком, 3 - алгоритм расчески. Введите 4 для активации сразу трех алгоритмов.\n");
    printf("Введите число от 1 до 4: ");
    int answer;
    scanf("%i", &answer);
    if (answer == 1) {
        selection_sort(arr);
    }
    else if (answer == 2) {
        bubble_sort(arr);
    }
    else if (answer == 3) {
        comb_sort(arr);
    }
    else if (answer == 4) {
        selection_sort(arr);
        bubble_sort(arr);
        comb_sort(arr);
    }
    else {
        printf("Неправильная команда");
    }
}

void swap(char arr[][1024], int i, int j) {
    char tmp[1024];
    strcpy(tmp, arr[i]);
    strcpy(arr[i], arr[j]);
    strcpy(arr[j], tmp);
}

void results(char arr[][1024], int count, double time_spent) {
    printf("Всего итераций: %i\n", count);
    printf("Конечный результат:");
    for (int j = 0; j < size; j++) {
        printf(" %s", arr[j]);
    }
    printf("\nВремя выполнения алгоритма равно %f секунд(ы) \n", time_spent);
}

void selection_sort(char arr[][1024]) {
    printf("АЛГОРИТМ СОРТИРОВКИ ВЫБОРОМ: \n");
    double time_spent = 0.0;
    clock_t start = clock();
    char copy_arr[10][1024];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < sizeof(arr[i])/sizeof(arr[i][0]); j++) {
            copy_arr[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < size - 1; i++) {
        count++;
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (strcmp(copy_arr[j], copy_arr[min_index]) < 0) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(copy_arr, i, min_index);
            printf("[");
            for (int j = 0; j < size; j++) {
                printf(" %s", copy_arr[j]);
            }
            printf(" ] \n");
        }
    }
    clock_t end = clock();
    time_spent += (double)(end - start) / CLOCKS_PER_SEC;
    results(copy_arr, count, time_spent);
    count = 0;
    time_spent = 0.0;
}


void bubble_sort(char arr[][1024]) {
    printf("АЛГОРИТМ СОРТИРОВКИ ПУЗЫРЬКОМ: \n");
    double time_spent = 0.0;
    clock_t start = clock();
    char copy_arr[10][1024];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < sizeof(arr[i])/sizeof(arr[i][0]); j++) {
            copy_arr[i][j] = arr[i][j];
        }
    }
    int flag = 1;
    while (flag) {
        count++;
        flag = 0;
        for (int i = 0; i < size - 1; i++) {
            if (strcmp(copy_arr[i], copy_arr[i + 1]) > 0) {
                swap(copy_arr, i, i + 1);
                flag = 1;
                printf("[");
                for (int j = 0; j < size; j++) {
                    printf(" %s", copy_arr[j]);
                }
                printf(" ] \n");
            }
        }
    }
    clock_t end = clock();
    time_spent += (double)(end - start) / CLOCKS_PER_SEC;
    results(copy_arr, count, time_spent);
    count = 0;
    time_spent = 0.0;
}


void comb_sort(char arr[][1024]) {
    printf("АЛГОРИТМ СОРТИРОВКИ РАСЧЕСКОЙ: \n");
    double time_spent = 0.0;
    clock_t start = clock();
    char copy_arr[10][1024];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < sizeof(arr[i])/sizeof(arr[i][0]); j++) {
            copy_arr[i][j] = arr[i][j];
        }
    }
    const float factor = 1.247;
    int step = size - 1;
    while (step >= 1) {
        count++;
        for (int i = 0; i + step < size; i++) {
            if (strcmp(copy_arr[i], copy_arr[i + step]) > 0) {
                swap(copy_arr, i, i + step);
                printf("[");
                for (int j = 0; j < size; j++) {
                    printf(" %s", copy_arr[j]);
                }
                printf(" ] \n");
            }
        }
        step /= factor;
    }
    clock_t end = clock();
    time_spent += (double)(end - start) / CLOCKS_PER_SEC;
    results(copy_arr, count, time_spent);
    count = 0;
    time_spent = 0.0;
}