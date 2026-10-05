#include "terminal.h"
#include "input.h"
#include "framebuffer.h"
#include "renderer.h"
#include "timer.h"

#include <signal.h>
#include <unistd.h>
#include <stdio.h> // pra debug : printfs

/* GAME LOOP
    1 - update timer
    2 - update input
    3 - update game logic
    4 - clear framebuffer
    5 - render game
    6 - draw frame
    7 - repeat
*/

static volatile sig_atomic_t running = 1;

void handle_sigint(int signal)
{
    (void)signal;
    write(STDOUT_FILENO, "xau??? ", 7);
    running = 0;
}

int main(void)
{
    signal(SIGINT, handle_sigint);


    terminal_init();
    terminal_enable_raw_mode();

    terminal_clear();
    terminal_hide_cursor();


    int width;
    int height;

    if (terminal_get_size(&width, &height) == -1)
    {
        printf("Erro ao obter tamanho do terminal. \n");
        terminal_show_cursor();
        terminal_cleanup();
        return 1;
    }

    Framebuffer fb;
    if (framebuffer_init(&fb, width, height) == -1)
    {
        printf("erro ao criar framebuffer\n");
        terminal_show_cursor();
        terminal_cleanup();
        return 1;
    }

    Timer t;
    timer_init(&t);
    input_init();

    double player_x = 0.0;
    double player_speed = 30.0;

    while (running)
    {
        timer_update(&t);
        double dt = timer_get_delta(&t);

        input_update();

        player_x += player_speed * dt; // moviemneno em função do tempo do delta com valor de velocidade

        if (player_x >= width)
        {
            player_x = 0.0;
        }

        framebuffer_clear(&fb, '.');
        framebuffer_put(&fb, (int)player_x, height / 2, '#');

        renderer_draw(&fb);
    }

}