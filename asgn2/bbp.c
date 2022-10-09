#include "mathlib.h"

#include <stdio.h>
/********************************
 *Declaring all Variables for
 *for the function pi_bbp()
 *
 *k (increment)
 *tt (numerator)
 *tt (denominator)
 *old (previous term of 16)
 *nt (new term)
 *pt (previous term)
 ********************************
 *Declaring Variable for pi_bbp_terms
 *
 *counter (static term counter)
 ********************************/
static int counter = 0;
static double k = 1.0;
static double pt = 0.0;
static double old = (1.0);
static double nt = 47.0 / 15.0;
static double tt = 0.0;
static double bt = 0.0;

/***********************************
 *Description:
    Implements the Bailey-Borwein
    Plouffe formula to approximate π
 ***********************************/
double pi_bbp() {
    while (absolute(nt - pt) > EPSILON) {
        pt = nt;
        tt = (k * (120.0 * k + 151.0) + 47.0);
        bt = (k * (k * (k * (512.0 * k + 1024.0) + 712.0) + 194.0) + 15.0);
        old = 16.0 * old;
        nt = (1 / old) * (tt / bt);
        nt = pt + nt;
        pi_bbp_terms();
        k += 1.0;
    }
    return nt;
}

/***********************************
 *Description:
    increments the counter the
    the amount of times it is called
 ***********************************/
int pi_bbp_terms() {
    counter += 1;
    return counter;
}
