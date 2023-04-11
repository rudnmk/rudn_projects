#include <stdio.h>
#include <stdlib.h>
// #include <locale.h>
#include <stdbool.h>
#include <math.h>

#include <time.h>

#define ARR_LENGTH (int)pow(10, 4)
//#define ARR_LENGTH 10

bool isFirstBigger(int, int);
void counter(int*);
int maxDifference(int*);

int main() {
	// setlocale(LC_ALL, "rus");
	int a = 4;
	int b = 5;
	int i = 0;
	int* ptrArr;
	scanf_s("%d", a);
	
// На самом деле, Вы можете вернуть разме массива, поделив размер всего массива на размер его 1-го элемента
// suze_t - особый тип, который всегда возвращает функция sizeof()
	//int arr[] = { 1,2,3,4,6 };
	//size_t arrLength = sizeof(arr) / sizeof(arr[0]);
	
	clock_t start = 0;
	clock_t end = 0;

// Объявить динамически массив и проинициализировать его
	ptrArr = (int*)malloc(ARR_LENGTH * sizeof(int));
	for (i = 0; i < ARR_LENGTH; i++) {
		ptrArr[i] = i;
	}

// Запуск таймера
	printf("\nStart!\n\n");
	start = clock();

// Раскомментируйте 1-ну из 3-ех строк, чтобы проверить скорость выполнения функции
	//printf("%s\n\n", isFirstBigger(a, b) ? "true" : "false");
	//counter(ptrArr);
	//printf("Max difference = %d\n", maxDifference(ptrArr));

// Выключение таймера
	end = clock();
	printf("\nFinished!\n\n");

	printf("For the function it took %.10lf seconds to execute:\n",
		((double)(end - start)) / CLOCKS_PER_SEC);

	return 0;
} 

// Constant Function Analysis
// 2 operation = O(1)
bool isFirstBigger(int a, int b) {
	if (a>b) {
		return true;
	} 
	else {
		return false;
	}
}

// Linear Function Analysis
//4+3*n = O(n)
void counter(int* ptrArr) {
	int i = 0;
	int count = 0;
	
	printf("narrLength = %d\n", ARR_LENGTH);
	for (; i < ARR_LENGTH; i++) {
		count++;
	}
	printf("count = %d\n", count);
}

// Quadratic Function Analysis
//O(n^2)
int maxDifference(int* ptrArr) {
	int i = 0;
	int j = 0;
	int maxDifference = ptrArr[1] - ptrArr[0];
	for (i = 0; i < ARR_LENGTH; i++) {
		for (j = i+1; j < ARR_LENGTH; j++) {
			if (ptrArr[j] - ptrArr[i] > maxDifference) {
				maxDifference = ptrArr[j] - ptrArr[i];
			}
		}
	}
	return maxDifference;
}