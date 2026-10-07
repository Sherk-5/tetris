#ifndef INPUT_H
#define INPUT_H

/*
typedef enum
{
    INPUT_NONE,
    INPUT_UP,
    INPUT_DOWN,
    INPUT_LEFT,
    INPUT_RIGHT,
    INPUT_QUIT
} InputAction;
*/

typedef struct
{
    int up;
    int down;
    int left;
    int right;
    int quit;
} InputState;

void input_init(void);
void input_update(InputState *input);

#endif 