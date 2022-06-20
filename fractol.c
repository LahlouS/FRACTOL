#include "fractol.h"

int capture_zoom(int keycode, int x, int y, t_data *data)
{
    printf("keycode = %d\nx = %d\ny = %d\n", keycode, x, y);
    if (keycode == 4)
        zoom_front(&(data->moves), &(data->fract));
    // if (keycode == 5)
    //     zoom_back();
    return (0);
}

int escape_window_m(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    return (1);
}

int set_data(t_data *data)
{
    data->mlx_ptr = mlx_init();
    if(!data->mlx_ptr)
        return (0);
    data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "window");
    if (!data->win_ptr)
    {
        free(data->win_ptr);
        return (0);
    }
    data->moves = 0;
}

void set_img(t_img *image, t_data *data)
{
    image->mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT); //initialise une image de la taille de notre fenetre afin de de dessiner dedans
    image->addr = mlx_get_data_addr(image->mlx_img, \
    &(image->bits_per_pix), &(image->line_len), &(image->endian)); // set les infos de l'image afin de gerer pixels par pixels
}

void set_fract(t_fract *fract)
{
    fract->prec = 600;
    fract->x = 0;
    fract->y = 0;
    fract->born_i1 = -2.1;
    fract->born_i2 = 2.1;
    fract->born_r1 = -1.2;
    fract->born_r2 = 1.2;
    fract->scale = 500;
    fract->img_x = (fract->born_i2 - fract->born_i1) * fract->scale;
    fract->img_y = (fract->born_r2 - fract->born_r1) * fract->scale;
    fract->scale_zoom = 1;
    fract->born_zoom = 1;
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
            mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    }
    return (0);
}

int main(void)
{
    t_data data;
    
    set_data(&data);
    set_img(&(data.img), &data);
    set_fract(&(data.fract));
    mlx_loop_hook(data.mlx_ptr, &menu, &data);
    mlx_mouse_hook(data.win_ptr, &capture_zoom, &data);
    mlx_hook (data.win_ptr, 17, 1L<<24, &escape_window_m, &data);
    mlx_key_hook(data.win_ptr, &escape_window_k, &data); // permet de tuer la fenetre
    mlx_loop(data.mlx_ptr); // continue de boucler tant qu'elle trouve la fenetre ouverte
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);
    return (0);
}