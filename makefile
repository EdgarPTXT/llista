all: llista

llista: main.o llista.o

main.o: main.c llista.h
	gcc main.c -g -Wall -Wextra -ggdb

llista.o: llista.c llista.h
	gcc llista.c -g -Wall -Wextra -ggdb

clean:
	rm -rf *.o