#include "input.h"

#include <unistd.h>

static char last_key;
//InputAction action;

void input_init(void)
{
}

void input_update(InputState *input)
{
    char c;

    input->up = 0;
    input->down = 0;
    input->left = 0;
    input->right = 0;
    input->quit = 0;

    ssize_t bytes_read = read( STDIN_FILENO , &c, 1 );
    if (bytes_read <= 0) // não houve input
        return;
    switch (c) // recebemos uma tecla //write(STDOUT_FILENO, &c, 1); last_key = c;
    {
        case 'w':
            input->up = 1;
            break;

        case 's':
            input->down = 1;
            break;

        case 'a':
            input->left = 1;
            break;

        case 'd':
            input->right = 1;
            break;

        case 'q':
            input->quit = 1;
            break;
    }
}

char input_get_key(void)
{
    return last_key;
}