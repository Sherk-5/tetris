#include "game.h"

void game_init(Game *g, int width, int height)
{
    g->player_x = width / 2.0;
    g->player_y = height / 2.0;

    g->player_speed = 30.0;
}

void game_update( Game *g , double dt , const InputState *i , int width , int height )
{
    if (i->left)
    {
        g->player_x -= g->player_speed * dt;
    }
    if (i->right)
    {
        g->player_x += g->player_speed * dt;
    }
    if (i->up)
    {
        g->player_y -= g->player_speed * dt;
    }
    if (i->down)
    {
        g->player_y += g->player_speed * dt;
    }

    if (g->player_x < 0)
    {
        g->player_x = 0;
    }
    if (g->player_x >= width)
    {
        g->player_x = width - 1;
    }
    if (g->player_y < 0)
    {
        g->player_y = 0;
    }
    if (g->player_y >= height)
    {
        g->player_y = height - 1;
    }
}

void game_render( const Game *g , Framebuffer *fb )
{
    framebuffer_put( fb , (int)g->player_x , (int)g->player_y , '@' );
}