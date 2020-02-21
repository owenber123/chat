CC=gcc
CFLAGS=-I.
OBJ=socket.o

socket: socket.c
	$(CC) -o socket.o socket.c $(CGLAGS)

clean:
	rm -f socket.o
