#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

struct func_deriv {

    double func;
    double der;

};

struct func_deriv derivative(double x) {

    double der = 0;

    struct func_deriv res;
    der = (2 * x) * sin(x) + x * x * cos(x) - 5;
    res.der = der;
    res.func = x * x * sin(x) - 5 * x + 7;

    return res;
}

typedef struct func_deriv (*fder_t) (double x);

double newton(fder_t f, double x) {

    double new_x = 0;
    double old_x = 0;
    
    int iter = 0;

    old_x = x;

    while (fabs(new_x - old_x) > 10 * DBL_EPSILON) {

        struct func_deriv res = f(old_x);
        double temp = old_x;
        old_x = new_x;
        new_x = temp - (res.func / res.der);
        ++iter;

    }
    printf("iterations: %d\n", iter);

    return new_x;
}

int main() {

    double root = newton(derivative, 2.3);
    printf("Root: %lg", root);

    return 0;
}
