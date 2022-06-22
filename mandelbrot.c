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

int	zoom_front(int *moves, int x, int y, t_fract *fract)
{
	*moves = 0;
	fract->scale_z += 0.04;
	if (y > ((WINDOW_HEIGHT / 2) - WINDOW_HEIGHT / 6))
		fract->i_zo += 0.02;
	else if (y < ((WINDOW_HEIGHT / 2) + WINDOW_HEIGHT / 6))
		fract->i_zo -= 0.02;
	if (x > ((WINDOW_WIDTH / 2) - WINDOW_WIDTH / 6))
		fract->r_zo += 0.02;
	if (x < ((WINDOW_WIDTH / 2) + WINDOW_WIDTH / 6))
		fract->r_zo -= 0.02;
}

int	zoom_back(int *moves, int x, int y, t_fract *fract)
{
	*moves = 0;
	fract->scale_z -= 0.04;
	if (y > ((WINDOW_HEIGHT / 2) - WINDOW_HEIGHT / 6))
		fract->i_zo += 0.02;
	else if (y < ((WINDOW_HEIGHT / 2) + WINDOW_HEIGHT / 6))
		fract->i_zo -= 0.02;
	if (x > ((WINDOW_WIDTH / 2) - WINDOW_WIDTH / 6))
		fract->r_zo += 0.02;
	if (x < ((WINDOW_WIDTH / 2) + WINDOW_WIDTH / 6))
		fract->r_zo -= 0.02;
}

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

void	init_formula(t_data *data, t_fract *fract)
{
	if (!data->set[0] && !data->set[1] && !data->arg)
	{
		fract->c_r = (((fract->x)) / (fract->scale * fract->scale_z)) \
		 + (fract->born_i1 * fract->r_zo);
		fract->c_i = (((fract->y)) / (fract->scale * fract->scale_z)) \
		 + (fract->born_r1 * fract->i_zo);
		fract->z_r = 0;
		fract->z_i = 0;
	}
	else if (data->arg == 1 && data->set[0])
	{
		fract->c_r = data->set[0];
		fract->c_i = data->set[1];
		fract->z_r = (((fract->x)) / (fract->scale * fract->scale_z)) \
		 + (fract->born_i1 * fract->r_zo);
		fract->z_i = (((fract->y)) / (fract->scale * fract->scale_z)) \
		 + (fract->born_r1 * fract->i_zo); 
	}
	else
	{
		if (write(1, "No set found\n", 13))
			;
		ft_man();
		exit(1);
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
