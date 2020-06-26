CC = gcc
CFLAGS = -ansi -pedantic -Wall -Werror -g
TARGET = main
INCLUDES = -I "./includes/"
SRC = $(filter-out src/main.c, $(wildcard src/*.c))
OBJ = $(SRC:.c=.o)
TESTSRC = $(wildcard tests/*.c)

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) src/$(TARGET).c -o $(TARGET) $(INCLUDES)

test: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(TESTSRC) -o test $(INCLUDES)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm $(OBJ) $(TARGET)
