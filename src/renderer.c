#include "renderer.h"

#include <unistd.h>

// o renderer só pode ler o framebuffer, nao pode mudificá-lo
void renderer_draw(const Framebuffer *fb)
{
    const char cursor_home[] = "\033[H"; // refresh posição do cursor no canto superior esquerdo
    write(STDOUT_FILENO , cursor_home , sizeof(cursor_home) - 1);

    for (int y = 0 ; y < fb->height ; y++)
    {
        int index = y * fb->width;

        write(STDOUT_FILENO ,  &fb->pixels[index], fb->width);
        write(STDOUT_FILENO , "\n" , 1);
    }
}