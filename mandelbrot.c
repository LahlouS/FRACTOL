/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahlou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:18:57 by slahlou           #+#    #+#             */
/*   Updated: 2022/06/21 16:18:59 by slahlou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

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

int	mandelbrot_algo(t_data *data)
{
	t_fract	*fr;
	double	tmp;
	int		i;

	fr = &(data->fract);
	fr->x = -1;
	while (++(fr->x) < fr->img_x)
	{
		(fr->y) = -1;
		while (++(fr->y) < fr->img_y)
		{
			init_formula(data, fr);
			i = 0;
			while ((fr->z_r * fr->z_r + fr->z_i * fr->z_i) \
			< 4 && i < fr->prec)
			{
				tmp = fr->z_r;
				fr->z_r = fr->z_r * fr->z_r - fr->z_i * fr->z_i + (fr->c_r);
				fr->z_i = 2 * fr->z_i * tmp + (fr->c_i);
				i++;
			}
			img_pix_put(&(data->img), (int)fr->x, \
			(int)fr->y, fr->col[fr->ind](i, fr->prec));
		}
	}
}
