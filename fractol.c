#include "fractol.h"

int capture_zoom(int keycode, int x, int y, t_data *data)
{
    if (keycode == 4)
        zoom_front(&(data->moves), x, y, &(data->fract));
    else if (keycode == 5)
        zoom_back(&(data->moves), x, y, &(data->fract));
    return (0);
}

int escape_window_m(t_data *data)
{
    if (data->win_ptr)
    {
        mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    }
    return (1);
}

int set_data(t_data *data, char *arg, char *arg1, char *arg2)
{
    data->mlx_ptr = mlx_init();
    if(!data->mlx_ptr)
        return (0);
    data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, arg);
    if (!data->win_ptr)
    {
        free(data->win_ptr);
        return (0);
    }
    data->moves = 0;
    data->arg = ft_atoi(arg);
    data->set[0] = ft_strtod(arg1);
    data->set[1] = ft_strtod(arg2);
}

void set_img(t_img *image, t_data *data)
{
        image->mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
        image->addr = mlx_get_data_addr(image->mlx_img, \
        &(image->bits_per_pix), &(image->line_len), &(image->endian));
}

void set_fract(t_fract *fract)
{
    fract->prec = 400;
    fract->x = 0;
    fract->y = 0;
    fract->born_i1 = -2.1;
    fract->born_i2 = 2.1;
    fract->born_r1 = -1.2;
    fract->born_r2 = 1.2;
    fract->scale = 500;
    fract->img_x = (fract->born_i2 - fract->born_i1) * fract->scale;
    fract->img_y = (fract->born_r2 - fract->born_r1) * fract->scale;
    fract->scale_z = 1;
    fract->i_zo = 1;
    fract->r_zo = 1;
    fract->ind = 0;
    fract->col[0] = &matrix;
    fract->col[1] = &cyber_punk;
    fract->col[2] = &retro;
    fract->col[3] = &black_white;
    fract->col[4] = &dont_know;    
}

int menu(t_data *data)
{
    if (data->win_ptr && !data->moves)
    {
        data->moves = 1;
        mandelbrot_algo(data);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
        return (0);
    }
    return (0);
}

int escape_window_k(int keysym, t_data *data)
{
    if (data->win_ptr)
    {
        if (keysym == XK_Escape)
        {
            mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
            mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        }
        else if (keysym == 65363)
        {
            data->moves = 0;
            (data->fract.ind) += (data->fract.ind < 4) - ((data->fract.ind == 4) * 4);
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    t_data data;

    if (ft_check_error(ac, av))
        return (0);
    if (!(ft_strncmp(*(av + 1), "julia1", 65)))
        set_data(&data, *(av + 1), *(av + 2), *(av + 3));
    else
        set_data(&data, *(av + 1), "0", "0");
    set_img(&(data.img), &data);
    set_fract(&(data.fract));
    mlx_loop_hook(data.mlx_ptr, &menu, &data);
    mlx_mouse_hook(data.win_ptr, &capture_zoom, &data);
    mlx_hook (data.win_ptr, 17, 1L<<24, &escape_window_m, &data);
    mlx_key_hook(data.win_ptr, &escape_window_k, &data);
    mlx_loop(data.mlx_ptr);
    mlx_loop_end(data.mlx_ptr);
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);
    return (0);
}