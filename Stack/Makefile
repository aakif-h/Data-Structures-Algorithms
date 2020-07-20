CC = gcc
CFLAGS = -c -std=c99
DEP = node.h

node.o: node.c node.h
	gcc $(CFLAGS) node.c node.h

stack.o: stack.c stack.h node.h
	gcc $(CFLAGS) stack.c stack.h node.h

main.o: main.c node.h stack.h
	gcc $(CFLAGS) main.c node.h stack.h

main: main.o node.o stack.o
	gcc -o main main.o node.o stack.o

clean:
	del *.o *.gch