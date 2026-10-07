#ifndef GAME_H
#define GAME_H

#include "framebuffer.h"
#include "input.h"

typedef struct
{
    double player_x;
    double player_y;

    double player_speed;
} Game;

void game_init(Game *g, int width, int height);

void game_update( Game *g , double dt , const InputState *i , int width , int height );

void game_render( const Game *g , Framebuffer *fb );

#endif