CC := g++
WARN := -Wall -Wextra -Wconversion

# optimization setting, uncomment when done with debugging
CCOPTS := $(WARN) -O3 -DNDEBUG

# link executable when an .o file is newer
output : main.o string.o
	$(CC) -o $@ $^

# how to compile .c files
%.o : %.c
	$(CC) $(CCOPTS) -c -o $@ $<

# remove object files and executable
clean:
	rm -rf *.o output

# file dependencies
main.o : main.c string.c string.h
string.o : string.c string.h