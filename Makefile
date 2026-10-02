CC = gcc

CFLAGS = -Wall -Wextra -std=c11 -Iinclude

TARGET = tetris

SRC = src/main.c src/terminal.c src/input.c src/timer.c src/framebuffer.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)