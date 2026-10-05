#ifndef TIMER_H
#define TIMER_H

#include <time.h>

typedef struct
{
    struct timespec last_time;

    double delta_time; // tempo entre frame atual e frame anterior
    double elapsed_time; // tempo total desde que o timer começou
} Timer;

void timer_init(Timer *t);
void timer_update(Timer *t);

double timer_get_delta(const Timer *t);
double timer_get_elapsed(const Timer *t);

#endif