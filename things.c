#include "fractol.h"

int zoom_front(int *moves, int x, int y, t_fract *fract)
{
    *moves = 0;
    fract->scale_z += 0;//.04;
    if (y > ((WINDOW_HEIGHT / 2) - WINDOW_HEIGHT / 6))
        fract->i_zo += 0.02;
    else if (y < ((WINDOW_HEIGHT / 2) + WINDOW_HEIGHT / 6))
        fract->i_zo -= 0.02;
    if (x > ((WINDOW_WIDTH / 2) - WINDOW_WIDTH / 6))
        fract->r_zo += 0.02;
    if (x < ((WINDOW_WIDTH / 2) + WINDOW_WIDTH / 6))
        fract->r_zo -= 0.02;
}

int zoom_back(int *moves, int x, int y, t_fract *fract)
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

void    init_formula(t_data *data, t_fract *fract)
{
    if (data->set == 0)
    {
        fract->c_r = (((fract->x)) / (fract->scale * fract->scale_z)) + (fract->born_i1 * fract->r_zo);
        fract->c_i = (((fract->y)) / (fract->scale * fract->scale_z)) + (fract->born_r1 * fract->i_zo);
        fract->z_r = 0;
        fract->z_i = 0;
    }
    else if (data->set == 1)
    {
        fract->c_r = 0.3;
        fract->c_i = 0.5;
        fract->z_r = (((fract->x)) / (fract->scale * fract->scale_z)) + (fract->born_i1 * fract->r_zo);
        fract->z_i = (((fract->y)) / (fract->scale * fract->scale_z)) + (fract->born_r1 * fract->i_zo); 
    }
    else if (data->set == 2)
    {
        fract->c_r = -0.038088;
        fract->c_i = 0.97546;
        fract->z_r = (((fract->x)) / (fract->scale * fract->scale_z)) + (fract->born_i1 * fract->r_zo);
        fract->z_i = (((fract->y)) / (fract->scale * fract->scale_z)) + (fract->born_r1 * fract->i_zo); 
    }
}

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*nptr && !(*nptr >= '0' && *nptr <= '9'))
		nptr++;
	while (*nptr <= '9' && *nptr >= '0')
	{
		res = res * 10 + ((*nptr) - 48);
		nptr++;
	}
	return (res * sign);
}