#include "mathlib.h"

#include <stdio.h>

/********************************
 *Declaring all Variables for
 *for the function e() and
 *e_terms()
 *
 *counter (to counts terms
 *k (increment)
 *old (previous term of k)
 *nt (new term)
 *pt (previous term)
 ***********************************
 *Description:
    Implements the Taylor series to
    approximate the value of e
 ***********************************/
static int counter;
double e() {
    double k = 1.0;
    double pt = 0.0;
    double nt = 1.0;
    double old = 1.0;
    while (absolute(nt - pt) > EPSILON) {
        pt = nt;
        old = k * old;
        k += 1.0;
        nt = 1.0 / old;
        nt += pt;
        e_terms();
    }
    return nt;
}

int e_terms() {
    counter += 1;
    return counter;
}
