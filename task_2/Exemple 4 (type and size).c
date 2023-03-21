#include <stdio.h>  // Библиотека для работы с функциями ввода-вывода
#include <locale.h> // Библиотека для указания локации (региональной кодировки)
#include <stdbool.h>// Библиотека для работы с логическими переменными

int main(){

	setlocale(LC_ALL, "Rus");

	char c = 'A';		int sizc = sizeof(char);
	int i = 10;			int sizi = sizeof(int);
	float f = 10.0;		int sizf = sizeof(float);
	double d = 10.0;	int sizd = sizeof(double);
	bool b=10;			int sizb = sizeof(bool);   // не является базовым типом, определён в библиотеки stdbool.h

	printf("Размер переменной типа   bool: %2d байт или %2d бит, со значением %10i\n", sizb, 8 * sizb, (int)b);
	printf("Размер переменной типа   char: %2d байт или %2d бит, со значением %10c\n", sizc, 8 * sizc, c);
	printf("Размер переменной типа    int: %2d байт или %2d бит, со значением %10i\n", sizi, 8 * sizi, i);
	printf("Размер переменной типа  float: %2d байт или %2d бит, со значением %10.5f\n", sizf, 8 * sizf, f);
	printf("Размер переменной типа double: %2d байт или %2d бит, со значением %10.3e\n", sizd, 8 * sizd, d);

	return 0;
}
/*
Упражнение 1.

1. Запустите программу и обратите внимание на размеры стандартных типов данных.

*/