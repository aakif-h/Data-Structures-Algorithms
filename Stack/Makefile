CC = gcc
DEBUG = -g
CFLAGS = -c -Wall $(DEBUG)
DEP = node.h stack.h

node.o: node.c node.h
	$(CC) $(CFLAGS) $^

stack.o: stack.c $(DEP)
	$(CC) $(CFLAGS) $^

main.o: main.c $(DEP)
	$(CC) $(CFLAGS) $^

main: main.o node.o stack.o
	$(CC) -o $@ $^

clean:
	del *.o *.gch