bag: main.c bow.c
	gcc -ansi -Wall -pedantic -Iinclude main.c bow.c -o bag

bow.o: bow.c
	gcc -ansi -Wall -pedantic -c bow.c -o bow.o

clean:
	rm -i bag bow.o main.o
	