CC=gcc
HOME=..
HEADERS=-I$(HOME)/headers
LIBS=
CFLAGS=

List.o: List.c
	$(CC) -c -o $@ List.c $(HEADERS)

clean:
	-rm *.o


