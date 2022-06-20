#include "fractol.h"

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
}

void set_img(t_img *image, t_data *data)
{
    image->mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT); //initialise une image de la taille de notre fenetre afin de de dessiner dedans
    image->addr = mlx_get_data_addr(image->mlx_img, \
    &(image->bits_per_pix), &(image->line_len), &(image->endian)); // set les infos de l'image afin de gerer pixels par pixels
}

void set_fract(t_fract *fract)
{
    fract->x = 0;
    fract->y = 0;
    fract->born_i1 = -2.1;
    fract->born_i2 = 0.6;
    fract->born_r1 = -1.2;
    fract->born_r2 = 1.2;
    fract->colors[0] = 0x800080;
    fract->colors[1] = 0x00B8FF;
    fract->colors[2] = 0xFF0000;
    fract->scale = 500;
    
}

int menu(t_data *data)
{
    printf("image->bits_per_pix = %d\nimage->line_len = %d\nimage->endian = %d\n", data->img.bits_per_pix, data->img.line_len, data->img.endian);

    if (data->win_ptr)
    {
        mandelbrot_algo(data);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
        return (0);
    }
    return (0);
}

int escape_window(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    return (0);
}

int main(void)
{
    t_data data;
    
    set_data(&data);
    set_img(&(data.img), &data);
    set_fract(&(data.fract));


    /*gestion des evenements*/
    mlx_loop_hook(data.mlx_ptr, &menu, &data); //affiche notre carre
    mlx_key_hook(data.win_ptr, &escape_window, &data); // permet de tuer la fenetre
    mlx_loop(data.mlx_ptr); // continue de boucler tant qu'elle trouve la fenetre ouverte


    /*sortie propre du programme*/
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);
    return (0);
}