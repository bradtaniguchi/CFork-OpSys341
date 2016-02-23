# Makefile for CFork-OpSys341

all: cfork.o cthread.o

cfork.o: cfork.c 
	gcc cfork.c -o cfork.o

cthread.o: cthread.c
	gcc cthread.c -o cthread.o

clean:
	rm -f cfork.o
	rm -f cthread.o

