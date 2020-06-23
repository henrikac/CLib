CC = gcc
CFLAGS = -ansi -pedantic -Wall -Werror -g
OBJ = node.o nully.o stack.o vector.o utils.o

default: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) main.c -o main

node.o: utils.o
	$(CC) $(CFLAGS) -c node.c -o node.o

nully.o:
	$(CC) $(CFLAGS) -c nully.c -o nully.o

stack.o: node.o nully.o utils.o
	$(CC) $(CFLAGS) -c stack.c -o stack.o

vector.o: nully.o utils.o
	$(CC) $(CFLAGS) -c vector.c -o vector.o

utils.o:
	$(CC) $(CFLAGS) -c utils.c -o utils.o

clean:
	rm *.o main
