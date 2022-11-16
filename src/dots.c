#include "chaos_sim.c"
#include "chaos_sim.h"

// set current spot to black thn change color of next spot
void    sim_dot(t_dot *dot, t_render r)
{
    dot->x += cos(dot->d);
    dot->y += sin(dot->d);
}