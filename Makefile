# Target to build the executable
all: main

# Recipe to compile and link main.c and data_structures.c into main
main: main.c data_structures.c
	gcc -o main main.c data_structures.c

# Clean target to remove any compiled object files
clean:
	rm -f main *.o