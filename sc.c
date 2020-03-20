#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <assert.h>

typedef double (*func_t)(double x);

double f(double x) {
    return x * x * sin(x) - 5 * x + 7;
}

double fsgn(double x) {
    return signbit(x) ? -1.0 : 1.0;
}

double secant(func_t f, double xleft, double xright) {

    assert(fsgn(f(xleft)) != fsgn(f(xright)));
    double xmid = 0;
    double fl = 0;
    double fr = 0;
    double fm = 0;
    double xnew = 0;
    int iter = 0;

    do {

        xmid = (xleft + xright) / 2.0;
        fl = f(xleft);
        fr = f(xright);
        fm = f(xmid);
        xnew = xmid + (xmid - xleft) * fsgn(fl - fr) * fm / sqrt(fm * fm - fl * fr);

        if (f(xnew) < 0) {
            xright = xnew;
        } else {
            xleft = xnew;
        }

        ++iter;
    } while (fabs(f(xnew)) > 10 * DBL_EPSILON);

    printf("iterations: %d\n", iter);

    return xnew;
}

int main() {

    double root = 0;
    root = secant(f, -3.0, 3.0);

    printf("Root: %lg", root);
    return 0;
}
