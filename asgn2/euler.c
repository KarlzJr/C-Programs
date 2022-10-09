#include "mathlib.h"

#include <stdio.h>

/********************************
 *Declaring all Variables for
 *for the function pi_euler() and
 *pi_euler_terms()
 *
 *counter (to counts terms)
 *k (increment)
 *nt (new term)
 *pt (previous term)
 ***********************************
 *Description:
    Implements the Euler’s solution 
    to approximate π
 ***********************************/
static int counter = 0;

double pi_euler() {
    long double k = 2.0;
    long double pt = 0.0;
    long double nt = 1.0;
    while (absolute(nt - pt) > EPSILON) {
        pt = nt;
        nt = 1.0 / (k * k);
        nt = pt + nt;
        k += 1.0;
        pi_euler_terms();
    }
    nt = nt * 6.0;
    nt = sqrt_newton(nt);
    return nt;
}

int pi_euler_terms() {
    counter += 1;
    return counter;
}
