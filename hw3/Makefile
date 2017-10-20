# declare the variable

CSOURCE = hw3t.c 
CPPSOURCE = hw3t.cpp
COPSOURCE = hw3opt.c

CPROG = hw3t_c 
CPPPROG = hw3t_cpp
COPPROG = hw3opt_c
CPP = 		$(wildcard *.cpp)

TEST = 		data.txt
OUT = 		out.txt

CC =		gcc
PP =		g++


CFLAGS =	-std=c99 -Wall -Wextra -pedantic -DEN_TIME
CPPFLAGS = 	-Wall -Wextra -pedantic -DEN_TIME

CPO = $(patsubst %.cpp, %_cpp, $(CPP))

#Building the app

.PHONY: all
all:	$(CPROG) $(COPPROG) $(CPO)

#Create test

.PHONY: test
test:	hw3t_c hw3t_cpp hw3opt_c
	@echo "Timing result for hw3t_c" >> $(OUT)
	./hw3t_c $(TEST) >> $(OUT) 2>&1
	@cat $(OUT)
	@echo >> $(OUT)
	@echo "Timing result for hw3t_cpp" >> $(OUT)
	./hw3t_cpp $(TEST) >> $(OUT) 2>&1
	@cat $(OUT)
	@echo >> $(OUT)
	@echo "Timing result for hw3opt_c" >> $(OUT)
	./hw3opt_c $(TEST) >> $(OUT) 2>&1
	@cat $(OUT)

$(CPROG):	$(CSOURCE)
	$(CC) $(CFLAGS) $< -o $@

$(COPPROG):	$(COPSOURCE)
	$(CC) $(CFLAGS) -O3 $< -o $@

%_cpp:  %.cpp
	$(PP) $(CPPFLAGS) $< -o $@

.PHONY: help

help:
	echo "make opitions: test, clean, all, help"

#Remove build files

.PHONY: clean

clean:
	-rm -f $(CPROG)
	-rm -f $(CPPPROG)
	-rm -f $(COPPROG)
	-rm -f $(CPO)
	-rm -f *.o
	-rm -f $(RESULT)