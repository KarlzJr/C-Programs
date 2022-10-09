# Assignment 6 - Public Key Cryptography

### Usage

The make file will produce:
- decrypt or encrypt or keygen

-i:Specifies the input file to encrypt (default: stdin).\
-o:Specifies the output file to encrypt (default: stdout).\
-n:Specifies the file containing the public key (default: rsa.pub)
-v:Enables verbose output.\
-h:Display a help message detailing program usage.

## Makefile
### Usage
- make:makes all .o files and links as well it makes the executable binary function
- make format:formats all .c and .h(header files) that are in the directory
- make clean:removes all .o files and binary files

### Important files needed to run
- decrypt.c: This contains the implementation and main() function for the decrypt program.
- encrypt.c: This contains the implementation and main() function for the encrypt program.
- keygen.c: This contains the implementation and main() function for the keygen program.
- numtheory.c: This contains the implementations of the number theory functions.
- numtheory.h: This specifies the interface for the number theory functions.
- randstate.c: This contains the implementation of the random state interface for the RSA library
  and number theory functions.
- randstate.h: This specifies the interface for initializing and clearing the random state.
- rsa.c: This contains the implementation of the RSA library.
- rsa.h: This specifies the interface for the RSA library.
- Makefile
