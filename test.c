#include "fractol.h"

int	get_backgroud(t_data *data, int color)
{
	int i;
	int j;
	if (!data->win_ptr)
		return (0);
	else
	{
		i = -1;
		while (++i < WINDOW_HEIGHT)
		{
			j = -1;
			while (++j < WINDOW_WIDTH)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, j, i, color);
		}
	}
}

int	make_rect(t_data *data, t_rect *rect)
{
	int i = (rect->x - 1);
	int j = (rect->y - 1);
	while (++j < rect->x + rect->width)
	{
		i = (rect->y - 1);
		while (++i < rect->y + rect->height)
		{
			if (data->win_ptr)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, j, rect->color);
		}
	}
	return (0);
}

int	render(t_data *data)
{
	t_rect rect;

	get_backgroud(data, RED_COL);

	rect.x = WINDOW_WIDTH - 100;
	rect.y = WINDOW_HEIGHT - 100;
	rect.width = 100;
	rect.height = 100;
	rect.color = GREEN_COL;

	make_rect(data, &rect);

	rect.x = 0;
	rect.y = 0;
	rect.width = 100;
	rect.height = 100;
	rect.color = BLUE_COL;
	make_rect(data, &rect);
	return (0);
}

int	make_blue_line(t_data *data)
{
	static int i = 0;
	if (data->win_ptr)
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, (WINDOW_WIDTH / 2) - i, (WINDOW_HEIGHT / 2) - i, GREEN_COL);
	i++;
	return (0);
}

int	handle_input_pressed(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	printf("in handle_input_press, keysym presses: %d\n", keysym);
	return (0);
}

int	handle_input_released(int keysym, t_data *data)
{
	static int	i = 0;
	if (keysym == 114 && data->win_ptr)
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, (WINDOW_WIDTH / 2) + i, (WINDOW_HEIGHT / 2) + i, RED_COL);
	i++;
	printf("in handle_input, keysym released: %d\n", keysym);
	return (0);
}



int main(void)
{
	t_data data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		exit(MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
	if (!data.win_ptr)
	{
		free(data.win_ptr);
		exit(MLX_ERROR);
	}
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_input_pressed, &data);
	//mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_input_released, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}