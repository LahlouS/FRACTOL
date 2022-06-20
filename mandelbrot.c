#include "fractol.h"

int img_pix_put(t_img *img, int x, int y, int color)
{
    char    *pixel;
    int     i;

    // printf("\tbpp = %d\n\tx = %d\n\ty = %d\n\tcolor = %d\n\timg->line_len = %d\n", \
    // img->bits_per_pix, x, y, color, img->line_len);

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
    int i = 0;
    double precision = 400;

    /*a degager*/
    double img_x;
    double img_y;
    double x = 0;
    double y = 0;
    fract = &(data->fract);
    img_x = (fract->born_i2 - fract->born_i1) * fract->scale;
    img_y = (fract->born_r2 - fract->born_r1) * fract->scale;
   // printf("img_x = %f\nimg_y = %f\n", img_x, img_y);
    /*Tu rajoutera les deux variable img_x et img_y dans la struct afin de les initialiser
      directement dans la fonction  | set_fract(t_fract *fract) | */
      fract->x = 0;
    while (fract->x < img_x)
    {
        (fract->y) = 0;
        while (fract->y < img_y)
        {
            c_r = (fract->x / fract->scale) + fract->born_i1;
            c_i = (fract->y / fract->scale) + fract->born_r1;
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
            //printf("z_r*z_r + z_i*z_i = %f\n", (z_r*z_r + z_i*z_i));
            if (i == precision && (z_r*z_r + z_i*z_i) < 1)
                img_pix_put(&(data->img), (int)fract->x, (int)fract->y, 0x000000);
            if (i == precision)
                img_pix_put(&(data->img), (int)fract->x, (int)fract->y, 0xFF8C00);
            else if (i < precision && i > 200)
                img_pix_put(&(data->img), (int)fract->x, (int)fract->y, GREEN2_COL);
            else if (i <= 200 && i > 80)
                img_pix_put(&(data->img), (int)fract->x, (int)fract->y, RED_COL);
            else if (i <= 80 && i > 40)
                img_pix_put(&(data->img), (int)fract->x, (int)fract->y, PURPLE2_COL);
            else if (i <= 40 && i > 20)
                img_pix_put(&(data->img), (int)fract->x, (int)fract->y, GREEN2_COL);
            else
                img_pix_put(&(data->img), fract->x, fract->y, 0x00B8FF);
            (fract->y)++;
        }
    (fract->x)++;
    }
}