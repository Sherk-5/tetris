#include "terminal.h"
#include "input.h"
#include "framebuffer.h"
#include "renderer.h"

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

    if (terminal_get_size(&width, &height) == -1)
    {
        printf("Erro ao obter tamanho do terminal. \n");
        terminal_cleanup();
        return 1;
    }

    Framebuffer fb;
    if (framebuffer_init(&fb, width, height) == -1)
    {
        printf("erro ao criar framebuffer\n");
        terminal_cleanup();
        return 1;
    }

    for(int x = 0 ; x < width ; x++)
    {
        framebuffer_clear(&fb, '.');
        framebuffer_put(&fb, x, height/2, '#'); // █

        terminal_clear();
        
        renderer_draw(&fb);
        usleep(50000);
    }

    framebuffer_destroy(&fb);
    terminal_cleanup();

    return 0;
}