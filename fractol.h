#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>

# define WINDOW_WIDTH 1350
# define WINDOW_HEIGHT 1200
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

typedef struct s_fract
{
    double x;
    double y;
    double born_i1;
    double born_i2;
    double born_r1;
    double born_r2;    
    double scale;
    int colors[3];
}   t_fract;

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_img   img;
    t_fract fract;
}   t_data;

int mandelbrot_algo(t_data *data);
int img_pix_put(t_img *img, int x, int y, int color);


#endif

