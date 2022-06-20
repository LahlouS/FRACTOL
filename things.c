#include "fractol.h"

int zoom_front(int *moves, t_fract *fract)
{
    *moves = 0;
    fract->scale_zoom += 0.1;
    fract->born_zoom += 0.05;
}