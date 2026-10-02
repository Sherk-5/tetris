#include "terminal.h"
#include "input.h"
#include "framebuffer.h"

#include <signal.h>
#include <unistd.h>
#include <stdio.h> // pra debug : printfs

static volatile sig_atomic_t running = 1;

void handle_sigint(int signal)
{
    (void)signal;
    write(STDOUT_FILENO, "xau??? ", 7);
    running = 0;
}

int main(void)
{
/*
    signal(SIGINT, handle_sigint);

    terminal_init();
    terminal_enable_raw_mode();

    terminal_clear();
    terminal_hide_cursor();

    while(running)
    {
        InputAction action = input_update();

        if (action == INPUT_UP)
            write(STDOUT_FILENO, "cima ", 5);
        else if (action == INPUT_DOWN)
            write(STDOUT_FILENO, "baixo ", 6);
        else if (action == INPUT_LEFT)
            write(STDOUT_FILENO, "esquerda ", 9);
        else if (action == INPUT_RIGHT)
            write(STDOUT_FILENO, "direita ", 8);
        else if (action == INPUT_QUIT)
        {
            write(STDOUT_FILENO, "xau ", 4);
            break;
        }

        //usleep(16000); //16.67 ms ~= 60/fps
    }

    terminal_show_cursor();
    terminal_cleanup();
    write(STDOUT_FILENO, "até logo ", 10);

    return 0;
*/

    int width;
    int height;

    terminal_init();

    if (terminal_get_size(&width, &height) == 1)
    {
        printf("Erro ao obter tamanho do terminal. \n");
        terminal_cleanup();
        return 1;
    }

    printf("Terminal: %d x %d \n", width, height);
    terminal_cleanup();
    return 0;
}