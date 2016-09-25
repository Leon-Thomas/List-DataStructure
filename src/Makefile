CC=gcc
HOME=..
HEADERS=-I$(HOME)/headers
LIBS=
CFLAGS=

libList.so:	List.o
	$(CC) -shared -o $@ List.o
List.o: List.c
	$(CC) -c -fpic List.c $(HEADERS)

clean:
	-rm *.o


