CC = gcc
CFLAGS = -ansi -pedantic -Wall -Werror -g
OBJ = alloc.o node.o stack.o

alloc.o:
	$(CC) $(CFLAGS) -c alloc.c -o alloc.o

node.o:
	$(CC) $(CFLAGS) -c node.c -o node.o

stack.o: alloc.o node.o
	$(CC) $(CFLAGS) -c stack.c -o stack.o

clean:
	rm *.o
