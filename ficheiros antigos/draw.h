#ifndef DRAW_H
#define DRAW_H

// screen: 24 x 14
#define WIDTH 14
#define HEIGHT 24

extern int posx, posy;
extern char matrix[22][12];

typedef enum
{
    WHITE, // etc.
    BLACK, // bg
    YELLOW, // O
    CYAN, // I
    RED, // Z
    GREEN, // S
    BLUE, // J
    ORANGE, // L
    PURPLE // T
} BColor;

typedef enum
{
    O,
    I,
    Z,
    S,
    J,
    L,
    T
} Tetromino;

typedef enum
{
    EMPTY, // "  "
    T_HALF, // "▀▀"
    B_HALF, // "▄▄"
    CENTER, // c = "■■"
    OUTLINE, // o = "□□"
    SIDE, // l = "▌▐"
    S_LIGHT, // l = "░░"
    S_MEDIUM, // m = "▒▒"
    S_DARK, // d = "▓▓"
    FULL, // f = "██"
    THREE_Q, // 3 = "▆"
    ONE_Q // 1 = "▂"
} BType;

typedef struct
{
    int x,
    int y,
    BType type,
    Bcolor color,
} Block;

void clear_screen(); // clears the terminal screen
void paint_bg_black(); // paints the screen in black
void draw_in_pos(int x, int y,char* s); // prints chars in a certain position
void draw_matrix(); // draws tetris matrix box
void draw_frame(); // draws entire frame


#endif