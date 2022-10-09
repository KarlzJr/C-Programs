EXEC = tsp
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:%.c=%.o)

CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra
LDFLAGS = -lm

all: $(EXEC)
debug: CFLAGS += -g
debug: tsp
$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJECTS) $(EXEC)

format:
	clang-format -i -style=file *.c *.h
