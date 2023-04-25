#include <stdio.h>

void selection_sort(int *arr, int size);
void bubble_sort(int *arr, int size);
void comb_sort(int *arr, int size);
void swap(int *arr, int i, int j);


void main() {
    int size = 11;
    int arr[] = {5, 3, 6, 4, 1, 2, 7, 10, 9, 8, 11};
    bubble_sort(arr, size);
}

void swap(int *arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}


void selection_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(arr, i, min_index);
            printf("[");
            for (int j = 0; j < size; j++) {
                printf(" %i", arr[j]);
            }
            printf(" ] \n");
        }
    }
}


void bubble_sort(int *arr, int size) {
    int flag = 1;
    while (flag == 1) {
        flag = 0;
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr, i, i + 1);
                flag = 1;
                printf("[");
                for (int j = 0; j < size; j++) {
                    printf(" %i", arr[j]);
                }
                printf(" ] \n");
            }
        }
    }
}


void comb_sort(int *arr, int size) {
    const float factor = 1.247;
    int step = size;
    int flag = 1;
    while ((step > 1) && (flag = 1)) {
        if (step > 1) {
            step = (step / factor);
        }
        flag = 0;
        int i = 0;
        while (i + step < size) {
            if (arr[i] > arr[i + step]) {
                swap(arr, i, i + step);
                flag = 1;
            i++;
            }
        }
    }
}