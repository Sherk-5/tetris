CC = gcc
CFLAGS = -Wall -Wextra -g

tetris: main.o draw.o
	$(CC) $(CFLAGS) -o tetris main.o draw.o

main.o: main.c common.h draw.h
	$(CC) $(CFLAGS) -c main.c

draw.o: draw.c common.h draw.h
	$(CC) $(CFLAGS) -c draw.c

clean:
	rm -f *.o tetris