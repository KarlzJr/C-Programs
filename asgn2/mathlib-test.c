#include "mathlib.h"

#include <math.h>
#include <stdio.h>
#include <unistd.h>
#define OPTIONS "aebmrvnshi:"

void message();
/********************************
 *Declaring all Variables for
 *for the function main() and
 *message()
 *
 *flags (to see that the user inputs)
 *i (increment for -n test)
 *diff (difference of my code and math.h)
 ***********************************
 *Description:
    This program links all .c files 
    and compared the output of said
    .c file with the math.h library
 ***********************************/
static int aflag = 0, eflag = 0, bflag = 0, mflag = 0, rflag = 0, vflag = 0, nflag = 0, hflag = 0,
           sflag = 0;
static double i = 0.0;
double diff = 0.0;
int main(int argc, char **argv) {
    int opt = 0;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a': aflag = 1; break;
        case 'r': rflag = 1; break;
        case 'e': eflag = 1; break;
        case 'v': vflag = 1; break;
        case 'm': mflag = 1; break;
        case 'b': bflag = 1; break;
        case 'n': nflag = 1; break;
        case 's': sflag = 1; break;
        case 'h': hflag = 1; break;
        case '?': message(); break;
        }
    }
    if (argc <= 1) {
        message();
    }
    if (hflag != 1) {
        if (eflag == 1 | aflag == 1) {
            diff = absolute(e() - M_E);
            printf("e() = %16.15lf, M_E = %16.15lf, diff = %16.15lf\n", e(), M_E, diff);
            if (sflag == 1) {
                printf("e() terms = %d\n", e_terms());
            }
        }
        if (rflag == 1 | aflag == 1) {
            diff = absolute(pi_euler() - M_PI);
            printf("pi_euler() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_euler(), M_PI,
                diff);
            if (sflag == 1) {
                printf("pi_euler() terms = %d\n", pi_euler_terms());
            }
        }
        if (bflag == 1 | aflag == 1) {
            diff = absolute(pi_bbp() - M_PI);
            printf("pi_bbp() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_bbp(), M_PI, diff);
            if (sflag == 1) {
                printf("pi_bbp() terms = %d\n", pi_bbp_terms());
            }
        }
        if (mflag == 1 | aflag == 1) {
            diff = absolute(M_PI - pi_madhava());
            printf("pi_madhava() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_madhava(),
                M_PI, diff);
            if (sflag == 1) {
                printf("pi_madhava() terms = %d\n", pi_madhava_terms());
            }
        }
        if (vflag == 1 | aflag == 1) {
            diff = absolute(M_PI - pi_viete());
            printf("pi_viete() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_viete(), M_PI,
                diff);
            if (sflag == 1) {
                printf("pi_viete() terms = %d\n", pi_viete_factors());
            }
        }
        if (nflag == 1 | aflag == 1) {
            while (i <= 10.0) {
                diff = absolute(sqrt_newton(i) - sqrt(i));
                printf("sqrt_newton(%.6f) = %16.15lf, sqrt(%.6f) = %16.15lf, diff = %16.15lf\n", i,
                    sqrt_newton(i), i, sqrt(i), diff);
                i += 0.1;
                if (sflag == 1) {
                    printf("sqrt_newton() terms = %d\n", sqrt_newton_iters());
                }
            }
        }
    } else {
        message();
    }
    return 0;
}

/***********************************
 *Description:
    Prints the help message and shows
    users how to interact with the 
    program 
 ***********************************/
void message() {
    printf("SYNOPSIS\n    A test harness for the small numerical library.\n\n");
    printf("USAGE\n    ./mathlib-test [-aebmrvnsh]\n\n");
    printf("OPTIONS\n    -a   Runs all tests.\n    -e   Runs e test.\n    -b   Runs BBP pi test.\n "
           "   -m   Runs Madhava pi test.\n    -r   Runs Euler pi test.\n    -v   Runs Viete pi "
           "test.\n    -n   Runs Newton square root tests.\n    -s   Print verbose statistics.\n   "
           " -h   Display program synopsis and usage.\n");
}
