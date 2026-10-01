#include "input.h"

#include <unistd.h>

static char last_key;
InputAction action;

void input_init(void)
{
}

InputAction input_update(void)
{
    char c;

    ssize_t bytes_read = read(STDIN_FILENO, &c, 1);

    if (bytes_read <= 0) // não houve input
        return INPUT_NONE;
    switch (c) // recebemos uma tecla //write(STDOUT_FILENO, &c, 1); last_key = c;
    {
        case 'w':
            return INPUT_UP;
        
        case 's':
            return INPUT_DOWN;

        case 'a':
            return INPUT_LEFT;

        case 'd':
            return INPUT_RIGHT;

        case 'q':
            return INPUT_QUIT;

        default:
            return INPUT_NONE;
    }
}

char input_get_key(void)
{
    return last_key;
}