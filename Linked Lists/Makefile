CC = gcc
DEBUG = -g
CFLAGS = -c -Wall $(DEBUG)
DEP = node.h list.h

node.o: node.c node.h
	$(CC) $(CFLAGS) $^

list.o: list.c $(DEP)
	$(CC) $(CFLAGS) $^

main.o: main.c $(DEP)
	$(CC) $(CFLAGS) $^

main: main.o node.o list.o
	$(CC) -o $@ $^

clean:
	del *.o *.gch *.exe