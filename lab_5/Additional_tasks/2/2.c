#include <stdio.h>
#include <math.h>

void stats(double* a, int size, double* min, double* max, double* avg);

void main() {
    double a[] = {1., 2., 3.};
    int size = 3;
    double min = 100000;
    double max = -100000;
    double avg = 0;
    stats(&a, size, &min, &max, &avg);
    //printf("%d, %d, %d", min, max, avg);
}

void stats(double* a, int size, double* min, double* max, double* avg) {
    printf("%d", &a);
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
