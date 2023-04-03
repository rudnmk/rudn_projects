#include <stdio.h>
#include <math.h>

void stats(double* a, int size, double* min, double* max, double* avg);
double* a[] = {1, 2, 3};
int size = 3;
double* min;
double* max;
double* avg;

void main() {
    stats(a, size, min, max, avg);
}

void stats(double* a, int size, double* min, double* max, double* avg) {
    for (int i = 0; i < size; i++) {
        if (a[i] < min[0]) {
            min[0] = a[i];
        }
        else if (a[i] > max[0]) {
            max[0] = a[i];
        }
        avg[0] += a[i];
    }
    avg[0] /= size;
}
