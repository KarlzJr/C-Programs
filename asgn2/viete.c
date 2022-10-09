#include "mathlib.h"

#include <stdio.h>
/********************************
 *Declaring all Variables for
 *for the function pi_viete() and
 *pi_viete_factors()
 *
 *counter (to counts terms)
 *pt (previous term)
 *old (previous term of sqrt2+2)
 *nt (new term)
 ***********************************
 *Description:
    Implements Viète’s formula to 
    approximate π 
 ***********************************/
static double pt = 0.0;
static double nt = 0.0;
static double old = 0.0;

static int counter = 0;
double pi_viete() {
    old = sqrt_newton(2.0);
    nt = old / 2.0;
    while (absolute(nt - pt) > EPSILON) {
        pt = nt;
        old = sqrt_newton(2.0 + old);
        nt = old / 2.0;
        nt = pt * nt;
        pi_viete_factors();
    }
    nt = 2 / nt;
    return nt;
}

int pi_viete_factors() {
    counter += 1;
    return counter;
}
