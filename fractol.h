#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 500
# define MLX_ERROR 1
# define RED_COL 0xFF0000
# define BLUE_COL 0x0000FF
# define GREEN_COL 0x00FF00

typedef struct s_data
{
    void *mlx_ptr;
    void *win_ptr;
}   t_data;

typedef struct s_rect
{
    int x;
    int y;
    int width;
    int height;
    int color;
}   t_rect;

#endif