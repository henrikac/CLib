CC = gcc
CFLAGS = -ansi -pedantic -Wall -Werror -g
TARGET = main
INCLUDES = -I "./includes/"
SRC = $(filter-out src/main.c, $(wildcard src/*.c))
OBJ = $(SRC:.c=.o)

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) src/$(TARGET).c -o $(TARGET) $(INCLUDES)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm $(OBJ) $(TARGET)
