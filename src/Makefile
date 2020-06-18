CC = gcc
CFLAGS = -ansi -pedantic -Wall -Werror -g
OBJ = node.o stack.o utils.o

default: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) main.c -o main

utils.o:
	$(CC) $(CFLAGS) -c utils.c -o utils.o

node.o: utils.o
	$(CC) $(CFLAGS) -c node.c -o node.o

stack.o: node.o utils.o
	$(CC) $(CFLAGS) -c stack.c -o stack.o

clean:
	rm *.o main
