#include "framebuffer.h"

#include <stdlib.h> // usado para mallocs e free

int framebuffer_init(Framebuffer *fb, int width, int height)
{
    fb->width = width;
    fb->height = height;
    fb->pixels = malloc(width * height * sizeof(char));

    if (fb->pixels == NULL)
        return -1;
    else
        return 0;
}

void framebuffer_destroy(Framebuffer *fb)
{
    free(fb->pixels);
    fb->pixels = NULL;
}

void framebuffer_clear(Framebuffer *fb, char character)
{
    int size = fb->width * fb->height;
    for (int i = 0; i < size; i++)
    {
        fb->pixels[i] = character;
    }
}

void framebuffer_put(Framebuffer *fb, int x, int y, char character)
{
    if (x < 0 || x >= fb->width)
        return;
    if (y < 0 || y >= fb->height)
        return;

    int index = y * fb->width + x;
    fb->pixels[index] = character;
}