# Makefile

CC = gcc
CFLAGS = -Wall -g
OBJ = main.o rod_cutting.o

all: rod_cutting_program

rod_cutting_program: $(OBJ)
	$(CC) $(OBJ) -o rod_cutting_program

main.o: main.c rod_cutting.h
	$(CC) $(CFLAGS) -c main.c

rod_cutting.o: rod_cutting.c rod_cutting.h
	$(CC) $(CFLAGS) -c rod_cutting.c

clean:
	rm -f *.o rod_cutting_program