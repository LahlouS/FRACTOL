#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>

# define WINDOW_WIDTH 2100
# define WINDOW_HEIGHT 1200
# define MLX_ERROR 1

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
    double img_x;
    double img_y;    
    double born_i1;
    double born_i2;
    double born_r1;
    double born_r2;    
    double scale;
    double prec;
    double c_r;
    double c_i;
    double z_r;
    double z_i;
    double  scale_z;
    double  i_zo;
    double  r_zo;
    int ind;
    int (*col[5])(int, int);
}   t_fract;

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    int     moves;
    int     set;
    t_img   img;
    t_fract fract;
}   t_data;

int     mandelbrot_algo(t_data *data);
int     matrix(int i, int prec);
int     cyber_punk(int i, int prec);
int     retro(int i, int prec);
int     black_white(int i, int prec);
int     dont_know(int i, int prec);
int     img_pix_put(t_img *img, int x, int y, int color);
int     zoom_front(int *moves, int x, int y, t_fract *fract);
int     zoom_back(int *moves, int x, int y, t_fract *fract);
void    init_formula(t_data *data, t_fract *fract);
int     ft_atoi(const char *nptr);
#endif

