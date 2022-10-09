EXEC = sorting
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:%.c=%.o)

CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra
LDFLAGS = -lm

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJECTS) $(EXEC)

format:
	clang-format -i -style=file *.c *.h
