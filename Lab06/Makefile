CC := g++
WARN := -Wall -Wextra -Wconversion

# optimization setting, uncomment when done with debugging
CCOPTS := $(WARN) -O3 -DNDEBUG

# link executable when an .o file is newer
output : StackMain.o Stack.o SList.o
	$(CC) -o $@ $^

# how to compile .c files
%.o : %.c
	$(CC) $(CCOPTS) -c -o $@ $<

# remove object files and executable
clean:
	rm -rf *.o output

# file dependencies
StackMain.o : StackMain.c Stack.c Stack.h SList.c SList.h
Stack.o : Stack.c Stack.h SList.c SList.h
Slist.o : SList.c SList.h
