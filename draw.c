#include "common.h"
#include "draw.h"

int posx = 1; int posy = 1; // posições do quadrado de teste

void clear_screen()
{
    printf("\033[2J"); // clears current visible terminal screen
    printf("\033[3J"); // clears scrollback buffer
    printf("\033[H"); // move cursor to top left;
    fflush(stdout);
}

void paint_bg_black()
{
    printf("\033[30m"); // preto
    for(int y = 0; y < HEIGHT; y++)
    {
        for(int x = 0 ; x < WIDTH; x++)
            printf("██");
        printf("\n");
    }
    printf("\033[0m"); // reset color
    fflush(stdout);
}

void draw_in_pos(int x, int y,char* s)
{
    int nx = x*2 - 1;
    printf("\033[%d;%dH", y, nx);
    printf("%s", s);
}

void draw_matrix_bg()
{
    printf("\033[37m"); // branco
    for(int y = 1 ; y <= 22 ; y++)
    {
        if (y == 1 || y == 22)
        {
            for(int x = 1 ; x <= 12 ; x++)
                draw_in_pos(x+1, y+1, "░░");
        }
        else
        {
            draw_in_pos(2, y+1, "░░");
            draw_in_pos(13, y+1, "░░");
        }    
    }
    printf("\033[0m"); // reset color

    fflush(stdout); // display this int this instant
}

void draw_frame()
{
    printf("\033[H"); // move cursor to top left

    paint_bg_black();
    draw_matrix_bg();

    draw_in_pos(posx+2, posy+2, "██"); // quadrado para testar input

    printf("\033[?25l"); fflush(stdout); // hides cursor
}