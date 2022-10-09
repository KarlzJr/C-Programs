# Assignment 5 - Huffman Coding

### Usage

The make file will produce:
- encode or decode

-v:Print compression statistics.\
-i:Input File to Decompress.\
-o:Output of decompressed data.\
-h:Display a help message detailing program usage.

## Makefile
### Usage
- make:makes all .o files and links as well it makes the executable binary function **sorting** which is how the program is ran
- make format:formats all .c and .h(header files) that are in the directory
- make clean:removes all .o files and binary files

### Important files needed to run

- encode.c: This file will contain your implementation of the Huffman encoder.
- decode.c: This file will contain your implementation of the Huffman decoder.
- defines.h: This file will contain the macro definitions used throughout the assignment.
- header.h: This will will contain the struct definition for a file header.
- node.h: This file will contain the node ADT interface. This file will be provided.
- node.c: This file will contain your implementation of the node ADT.
- pq.h: This file will contain the priority queue ADT interface. This file will be provided. 
- pq.c: This file will contain your implementation of the priority queue ADT. You must define 
  your priority queue struct in this file.
- code.h: This file will contain the code ADT interface. This file will be provided. 
- code.c: This file will contain your implementation of the code ADT.
- io.h: This file will contain the I/O module interface. This file will be provided. 
- io.c: This file will contain your implementation of the I/O module.
- stack.h: This file will contain the stack ADT interface. This file will be provided.
- stack.c: This file will contain your implementation of the stack ADT. You must define 
  your stackstruct in this file.
- huffman.h specifies: This file will contain the Huffman coding module interface. This file 
  will be provided.
- huffman.c This file will contain your implementation of the Huffman coding module interface.
- Makefile


## Known Bugs
Code.c will pass pipeline most of the time just some ocassion it won't.
I have been struggling with the encode/decode and aswell as getting my pq.c to dequeue correctly.
I have decided to turn in what I have just to give me peace of mind and the ability to start the
next assignment on time. I appreaciate any points given for my working files besides encode/decode.
I will comment out what I have for encode so that it passes the valgrind tests. Thank you.
