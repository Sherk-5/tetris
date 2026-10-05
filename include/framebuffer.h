#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

typedef struct framebuffer
{
    int width;
    int height;
    char *pixels;
} Framebuffer;

int framebuffer_init(Framebuffer *fb, int width, int height);
void framebuffer_destroy(Framebuffer *fb);

void framebuffer_clear(Framebuffer *fb, char charecter);
void framebuffer_put(Framebuffer *fb, int x, int y, char character);

#endif