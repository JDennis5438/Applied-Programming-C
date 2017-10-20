# declare the variable

SOURCE = TestDarray_hw.c DynamicArrays.c
PROG = TDA
RESULT = out.txt
CC = gcc
CFLAGS = -Wall -std=c99 -O1 -pedantic -g
LFLAGS = -lm

#Build a list of OBJ files from the source

OBJS = $(patsubst %.c, %.o, $(SOURCE))

#Don't print out each executed line

.SILENT:

#Building the app

all:$(PROG)

#Create test

.PHONY: test

test:$(PROG)
	echo "Testing us-eng-words.txt"
	./$(PROG) us-eng-words.txt > $(RESULT)
	@cat $(RESULT)

#Convert each .c file to a .o file

.c.o: echo "compile $<"
	$(CC) $(CFLAGS) -c $<

#Rebuild the solution if any .o file

$(PROG): $(OBJS)
	echo "linking $(PROG)"
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) -o $(PROG)

.PHONY: mem

mem:$(PROG)
	echo "Valgrind Memory Usage"
	valgrind --tool=memcheck --leak-check=yes ./$(PROG) us-eng-words.txt > mem.txt 2>&1
	@cat mem.txt

.PHONY: help

help:
	echo "make opitions: test, clean, mem, all, help"

#Remove build files

.PHONY: clean

clean:
	-rm -f $(PROG)
	-rm -f *.o
	-rm -f $(RESULT)
