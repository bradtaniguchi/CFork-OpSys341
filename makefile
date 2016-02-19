# Makefile for CFork-OpSys341

all: app

app: main.c 
	gcc main.c -o main.o

clean:
	rm -f main.o
