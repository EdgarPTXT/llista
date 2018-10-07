all: llista

llista: main.o llista.o

main.o: main.c llista.h
	gcc -c main.c -o main.o -g -Wall -Wextra -ggdb

llista.o: llista.c llista.h
	gcc -c llita.c -o llista.o -g -Wall -Wextra -ggdb

clean:
	rm -rf *.o