#include "fractol.h"

int img_pix_put(t_img *img, int x, int y, int color)
{
    char    *pixel;
    int     i;

    printf("coucou\n");

    i = img->bits_per_pix - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bits_per_pix / 8));
    while (i >= 0)
    {
        if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bits_per_pix - 8 - i)) & 0xFF;
		i -= 8;
    }
}

int mandelbrot_algo(t_data *data)
{
    t_fract *fract;
    double c_r;
    double c_i;
    double z_r;
    double z_i;
    double tmp;
    double i = 0;
    double precision = 100;

    /*a degager*/
    double img_x;
    double img_y;
    double x = 0;
    double y = 0;
    fract = &(data->fract);
    img_x = (fract->born_i2 - fract->born_i1) * fract->scale;
    img_y = (fract->born_r2 - fract->born_r1) * fract->scale;
    /*Tu rajoutera les deux variable img_x et img_y dans la struct afin de les initialiser
      directement dans la fonction  | set_fract(t_fract *fract) | */
    while (fract->x < img_x)
    {
        (fract->y) = 0;
        while (fract->y < img_y)
        {
            c_r = (fract->x / fract->scale) + fract->born_i1;
            c_i = (fract->x / fract->scale) + fract->born_r1;
            z_r = 0;
            z_i = 0;
            i = 0;
            while ((z_r*z_r + z_i*z_i) < 4 && i < precision)
            {
                tmp = z_r;
                z_r = z_r*z_r - z_i*z_i + c_r;
                z_i = 2*z_i*tmp + c_i;
                i++;
            }
            if (i == precision)
                img_pix_put(data->img.mlx_img, fract->x, fract->y, 0x001EFF);
            else
                img_pix_put(data->img.mlx_img, fract->x, fract->y, RED_COL);
            (fract->y)++;
        }
    (fract->x)++;
    }
}