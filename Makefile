CC = gcc
CFLAGS = -Wall -g

OBJ_LRU = rodcut.o rodfunctions.o lru_cache.o
OBJ_FIFO = rodcut.o rodfunctions.o fifo_cache.o

all: rodcut_program rodcut_fifo_program

rodcut_lru_program: $(OBJ_LRU)
	$(CC) $(OBJ) -o rodcut_lru_program

rodcut_fifo_program: $(OBJ_FIFO)
	$(CC) $(OBJ_FIFO) -o rodcut_fifo_program

rodcut.o: rodcut.c rodcut.h
	$(CC) $(CFLAGS) -c rodcut.c

rodfunctions.o: rodfunctions.c rodcut.h
	$(CC) $(CFLAGS) -c rodfunctions.c

lru_cache.o: lru_cache.c lru_cache.h
	$(CC) $(CFLAGS) -c lru_cache.c

fifo_cache.o: fifo_cache.c fifo_cache.h
	$(CC) $(CFLAGS) -c fifo_cache.c

clean:
	rm -f *.o rodcut_program rodcut_fifo_program
