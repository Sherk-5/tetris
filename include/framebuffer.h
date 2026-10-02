#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

typedef struct framebuffer
{
    int width;
    int height;
    char *pixels;
} Framebuffer;

int framebuffer_init(Framebuffer *framebuffer, int width, int height);
void framebuffer_destroy(Framebuffer *framebuffer);

void framebuffer_clear(Framebuffer *framebuffer, char charecter);
void framebuffer_put(Framebuffer *framebuffer, int x, int y, char character);

#endif