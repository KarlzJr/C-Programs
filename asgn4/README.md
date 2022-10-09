# Assignment 4 - The Perambulations of Denver Long

Traveling Salesman Problem using DFS

### Usage

The make file will produce:
- tsp

-u:Use and undirected Graph.\
-v:Enable Program Verbose printing.\
-i:Input Containing Graph. (default: stdin)\
-o:output of computed path.(default: stdout)\
-h:Display a help message detailing program usage.

## Makefile
### Usage
- make:makes all .o files and links as well it makes the executable binary function **sorting** which is how the program is ran
- make format:formats all .c and .h(header files) that are in the directory
- make clean:removes all .o files and binary files

### Important files needed to run

- graph.h specifies the interface to the graph ADT
- graph.c implements the graph ADT.
- path.h specifies the interface of the path ADT
- path.c implements the path ADT
- stack.h specifies the interface to the stack ADT.
- stack.c implements the stack ADT.
- tsp.c contains main()
- vertices.h defines macros regarding vartices.
- Makefile

### Known Bugs
- wont pass the solarsystem test. my path starts at 30 and the resouce at 28.
