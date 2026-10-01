#ifndef INPUT_H
#define INPUT_H

typedef enum
{
    INPUT_NONE,
    INPUT_UP,
    INPUT_DOWN,
    INPUT_LEFT,
    INPUT_RIGHT,
    INPUT_QUIT
} InputAction;

/*
typedef struct
{
    bool up;
    bool down;
    bool left;
    bool right;
    bool quit;    
} InputState;
*/

void input_init(void);
InputAction input_update(void);

#endif 