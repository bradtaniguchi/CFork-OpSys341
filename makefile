# Makefile for CFork-OpSys341

all: cfork.o cthread.o clean

commons.o: commons.c
	gcc -c commons.c -o commons.o

cfork.o: cfork.c commons.o
	gcc cfork.c commons.o -o cfork.o

cthread.o: cthread.c commons.o
	gcc cthread.c commons.o -o cthread.o

clean:
	rm -f commons.o

