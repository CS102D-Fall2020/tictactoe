# definition for consts
CC=gcc
CFLAGS=-I.

# Compile .o files and create final executable
make: tictactoe.o setup.o
	$(CC) $(CFLAGS) -o tictactoe tictactoe.o setup.o

setup.o: setup.c
	$(CC) $(CFLAGS) -c setup.c

tictactoe.o: tictactoe.c setup.h
	$(CC) $(CFLAGS) -c tictactoe.c

clean:
	rm -f *.o *.exe
