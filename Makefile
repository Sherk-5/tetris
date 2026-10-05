CC = gcc

CFLAGS = -Wall -Wextra -std=c11 -D_POSIX_C_SOURCE=200809L -Iinclude

TARGET = tetris

SRC = src/main.c src/terminal.c src/input.c src/timer.c src/framebuffer.c src/renderer.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)