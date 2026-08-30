#ifndef DRAW_H
#define DRAW_H

// screen: 24 x 14
#define WIDTH 14
#define HEIGHT 24

extern int posx, posy;
extern char matrix[22][12];

void clear_screen(); // clears the terminal screen
void paint_bg_black(); // paints the screen in black
void draw_in_pos(int x, int y,char* s); // prints chars in a certain position
void draw_matrix(); // draws tetris matrix box
void draw_frame(); // draws entire frame


#endif