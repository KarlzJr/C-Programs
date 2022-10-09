# Assignment 3 - Sorting: Putting your affairs in order

This program uses different implementations of methods to sort elements in c. 

### Usage

The make file will produce:
- sorting

-a:Employs all sorting elements.\
-e:Enables Heap Sort.\
-i:Enables Insertion Sort.\
-s:Enables Shell Sort.\
-q:Enables Quicksort.\
-r seed :Set the random seed to seed.\
-n size : Set the array size to size.\
-p elements : Print out elements number of elements from the array.\
-h:Display a help message detailing program usage.

## Makefile
### Usage
- make:makes all .o files and links as well it makes the executable binary function **sorting** which is how the program is ran
- make format:formats all .c and .h(header files) that are in the directory
- make clean:removes all .o files and binary files

### Important files needed to run

- insert.c implements Insertion Sort.
- insert.h specifies the interface to insert.c.
- heap.c implements Heap Sort.
- heap.h specifies the interface to heap.c.
- quick.c implements recursive Quicksort.
- quick.h specifies the interface to quick.c.
- stats.c implements the statistics module. 
- stats.h specifies the interface to the statistics module.
- shell.c implements Shell Sort.
- shell.h specifies the interface to shell.c.
- sorting.c contains main()
- stack.c implements the stack ADT.
- stack.h specifies the interface to the stack ADT.
- Makefile

### Known Bugs
- It wont pass the pipeline but I believe the results for shell are pretty similar (as of 11:25 pm 10/19)
- Also when running on a Mac Terminal it will ask for %llu to print stats, but on Ubuntu it asks for %lu. I kept it at %lu since it was mentioned to always go with Ubuntu.
