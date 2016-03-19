# By  and Patrick Russell
#      || pcrussel@ucsc.edu
#
# Makefile for programing assignment 2
# compiles store executable

store : store.o list.o
	gcc -ansi -Wall -Wextra -pedantic -o store store.o list.o

store.o : store.c list.h
	gcc -c -ansi -Wall -Wextra -pedantic store.c

list.o : List.h List.c
	gcc -c -ansi -Wall -Wextra -pedantic List.c

clean :
	rm list listdr.o list.o store.o
