# Assignment 2 - A Little Slice of π

This program uses different formulas to replicate the math library in c. 

### Usage

To see the library in action compared with the math.h c library run the make file.

The make file will produce:
- mathlib-test

When mathlib-test is ran you have options to see the option insert -h for the usage page.

-a:Runs all tests.\
-e:Runseapproximation test.\
-b:Runs Bailey-Borwein-Plouffe π approximation test.\
-m:Runs Madhava π approximation test.\
-r:Runs Euler sequence π approximation test.\
-v:Runs Viète π approximation test.\
-n:Runs Newton-Raphson square root approximation tests.\
-s:Enable printing of statistics to see computed terms and factors for each tested function.\
-h:Display a help message detailing program usage.

## Makefile
### Usage
- make:makes all .o files and links as well it makes the executable binary function *mathlib-test* which is how the program is ran
- make format:formats all .c and .h(header files) that are in the directory
- make clean:removes all .o files and binary files

### Important files needed to run

- mathlib.h
- mathlib-test.c
- bbp.c
- e.c
- euler.c
- madhava.c
- newton.c
- viete.c
- Makefile
