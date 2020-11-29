
all: main
	
main:
	gcc -std=c99 -o main.exe main.c 

run: 
	main.o
clean: 
	rm -f main.o
	rm -f main.exe 