CC = gcc
CFLAGS = -c -std=c99
DEP = node.h

node.o: node.c node.h
	gcc -c node.c node.h

main.o: main.c node.h
	gcc -c main.c node.h

main: main.o node.o
	gcc -o main main.o node.o

clean:
	del *.o *.gch