#include "timer.h"

#include <time.h>

//função auxiliar
static double timespec_to_seconds(struct timespec time)
{
    return (double)time.tv_sec + (double)time.tv_nsec / 1000000000.0; // segundos + nanosegundos
}

void timer_init(Timer *t)
{
    clock_gettime(CLOCK_MONOTONIC, &t->last_time); // função que obtem o tempo, MONOTONIC é usado para avançar intervalos de tempo continuamente, em vez e depender de calendario/hora do sistema
    t->delta_time = 0.0;
    t->elapsed_time = 0.0;
}

void timer_update(Timer *t)
{
    struct timespec current_time;
    clock_gettime(CLOCK_MONOTONIC, &current_time);
    double current_seconds = timespec_to_seconds(current_time);

    double last_seconds = timespec_to_seconds(t->last_time);

    t->delta_time = current_seconds - last_seconds;
    t->elapsed_time += t->delta_time;
    t->last_time = current_time;
}

double timer_get_delta(const Timer *t)
{
    return t->delta_time;
}

double timer_get_elapsed(const Timer *t)
{
    return t->elapsed_time;
}