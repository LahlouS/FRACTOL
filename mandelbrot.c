#include "fractol.h"

int get_color(int i, int prec)
{
// 	if (i == prec)
// 		return (0x000000);
// 	else if (i < prec && i > 200)
// 		return (0x0000FF);
// 	else if (i <= 200 && i > 80)
// 		return (0xFF0000);
// 	else if (i <= 80 && i > 40)
// 		return (0xD600FF);
// 	else if (i <= 40 && i > 20)
// 		return (0x00B8FF);
// 	else if (i <= 20 && i > 17)
// 		return (0xFFFFFF);
// 	else if (i <= 17 && i > 14)
// 		return (0xB30000);
// 	else if (i <= 14 && i > 13)
// 		return (0x9C7EB8);
// 	else if (i <= 13 && i > 11)
// 		return (0x4C344C);
// 	else if (i <= 11 && i > 9)
// 		return (0x780C3D);
// 	else if (i <= 9 && i > 8)
// 		return (0xA8CBD3);
// 	else
// 		return (0x808080);

	if (i == prec)
		return (0x0D0208);
	else if (i < prec && i > 200)
		return (0x00FF41);
	else if (i <= 200 && i > 80)
		return (0x00FF41);
	else if (i <= 80 && i > 40)
		return (0x008711);
	else if (i <= 40 && i > 20)
		return (0xFFFFFF);
	else if (i <= 20 && i > 17)
		return (0x003B00);
	else if (i <= 17 && i > 14)
		return (0x008711);
	else if (i <= 14 && i > 13)
		return (0x00FF41);
	else if (i <= 13 && i > 11)
		return (0x0D0208);
	else if (i <= 11 && i > 9)
		return (0x003B00);
	else if (i <= 9 && i > 8)
		return (0x008711);
	else
		return (0xD0208);
}

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
	double tmp;
	int i = 0;

	fract = &(data->fract);
	fract->x = -1;
	while (++(fract->x) < fract->img_x)
	{
		(fract->y) = -1;
		while (++(fract->y) < fract->img_y)
		{
			fract->c_r = (((fract->x)) / (fract->scale * fract->scale_zoom)) + (fract->born_i1);
			fract->c_i = (((fract->y)) / (fract->scale * fract->scale_zoom)) + (fract->born_r1 * fract->born_zoom);
			fract->z_r = (((fract->x)) / (fract->scale * fract->scale_zoom)) + (fract->born_i1);
			fract->z_i = (((fract->y)) / (fract->scale * fract->scale_zoom)) + (fract->born_r1 * fract->born_zoom);
			i = 0;
			while ((fract->z_r*fract->z_r + fract->z_i*fract->z_i) < 4 && i < fract->prec)
			{
				tmp = fract->z_r;
				fract->z_r = fract->z_r*fract->z_r - fract->z_i*fract->z_i + (fract->c_r);
				fract->z_i = 2*fract->z_i*tmp + (fract->c_i);
				i++;
			}
			img_pix_put(&(data->img), (int)fract->x, (int)fract->y, get_color(i, fract->prec));
		}
	}
}