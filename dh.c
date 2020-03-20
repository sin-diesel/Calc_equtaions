#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

double f(double x) {

    return x * x * sin(x) - 5 * x + 7;
}

double find_root(double start, double end) {

    double pivot = (start + end) / 2;
    int iter = 0;

    while (fabs(f(pivot) - 0) > 10 * DBL_EPSILON) {

        pivot = (start + end) / 2;

        if (f(pivot) * f(start) < 0) {
            end = pivot;
        }

        if (f(pivot) * f(end) < 0) {
            start = pivot;
        }

        ++iter;
    }

    printf("iterations: %d\n", iter);

    return pivot;
}


int main() {

    double start = -3.0;
    double end = 3.0;

    double root = find_root(start, end);

    printf("Root: %lg", root);

    return 0;
}
