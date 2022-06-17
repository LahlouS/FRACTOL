#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define MLX_ERROR 1
# define RED_COL 0xFF0000
# define BLUE_COL 0x0000FF
# define GREEN_COL 0x00FF00
# define GREEN2_COL 0x00FF9F
# define PURPLE_COL 0x800080
# define BLUE2_COL 0x001EFF
# define BLUE3_COL 0x00B8FF

typedef struct s_img
{
    void    *mlx_img;
    char    *addr;
    int     bits_per_pix;
    int     line_len;
    int     endian;
}   t_img;

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_img   img;
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