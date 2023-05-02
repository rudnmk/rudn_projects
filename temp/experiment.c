#include <stdio.h>
#include <stdlib.h>
#include "temp.h"

extern int from_another_file;

int a = 1;

int sum(int x1) {
    return x1;
}

void main() {
    printf("%i \n", from_another_file);
    printf("%i", substruct(5, 3));
}