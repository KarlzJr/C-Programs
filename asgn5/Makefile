CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra
LDFLAGS = -lm
OBJECTS = code.o huffman.o io.o node.o pq.o stack.o

all: encode decode

encode: $(OBJECTS) encode.o
	$(CC) $(LDFLAGS) -o encode $(OBJECTS) encode.o
decode:	$(OBJECTS) decode.o
	$(CC) $(LDFLAGS) -o decode $(OBJECTS) decode.o

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJECTS) $(EXEC) encode encode.o decode decode.o

format:
	clang-format -i -style=file *.c *.h
