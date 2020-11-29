
all: main
	
main:
	gcc -std=c99 -c main.c 

run: 
	main.o
clean: 
	rm -f main.o