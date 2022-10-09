#include "mathlib.h"

#include <stdio.h>

static int counter = 0;

/********************************
 *Declaring all Variables for
 *for the function pi_madhava()
 *
 *n (numerator)
 *d1 and d2 (denominator terms)
 *final (final term)
 *nt (new term)
 *pt (previous term)
 ********************************/
static double n = 0.0;
static double final = 0.0;
static double d1 = 1.0;
static double d2 = 1.0;
static double nt = 1.0;
static double pt = 0.0;

/***********************************
 *Description:
    implements he Madhava series to 
    approximate π
 ***********************************/
double pi_madhava() {
    n = sqrt_newton(12.0);
    while (absolute(pt - nt) > EPSILON) {
        pt = nt;
        d1 = d1 + 2.0;
        d2 = d2 * (-3.0);
        nt = 1 / (d1 * d2);
        nt = pt + nt;
        pi_madhava_terms();
    }
    final = sqrt_newton(12.0) * nt;
    return final;
}

/***********************************
 *Description:
    increments the counter the
    the amount of times it is called
 ***********************************/
int pi_madhava_terms() {
    counter += 1;
    return counter;
}
