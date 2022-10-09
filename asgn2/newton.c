#include "mathlib.h"

#include <stdio.h>

/********************************
 *Declaring all Variables for
 *for the function sqrt_newton() and
 *sqrt_newton_iters()
 *
 *counter (to counts terms)
 *k (increment)
 *x (parameter that is need to square)
 *pt (previous term)
 ***********************************
 *Description:
    Implements the Newton’s method 
    to approximate the square root 
    *credit to Asginment Doc and Dr.Long
 ***********************************/
static int counter = 0;

double sqrt_newton(double x) {
    double k = 1.0;
    double pt = 0.0;
    while (absolute(k - pt) > EPSILON) {
        pt = k;
        k = 0.5 * (k + x / k);
        sqrt_newton_iters();
    }
    return k;
}

int sqrt_newton_iters() {
    counter += 1;
    return counter;
}
