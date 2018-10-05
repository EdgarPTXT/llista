all: llista

llista: main.o LlistaBIO.o

main.o: main.c LlistaBIO.h
	gcc main.c -g -Wall -Wextra -ggdb

LlistaBIO.o: LlistaBIO.c LlistaBIO.h
	gcc LlistaBIO.c -g -Wall -Wextra -ggdb

clean:
	rm -rf *.o