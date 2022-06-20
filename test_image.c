#include "fractol.h"

int img_pix_put(t_img *img, int x, int y, int color)
{
    char    *pixel;
    int     i;

    i = img->bits_per_pix - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bits_per_pix / 8));
    while (i >= 0)
    {
        if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bits_per_pix - 8 - i)) & 0xFF;
		i -= 8;
    }
}

int get_background(t_img *img, int color)
{
    int i;
    int j;

    i = 0;
    while (i < WINDOW_HEIGHT)
    {
        j = 0;
        while (j < WINDOW_WIDTH)
            img_pix_put(img, j++, i, color);
        i++;
    }
}

int get_rect(t_img *img, t_rect rect)
{
    int i;
    int j;

    i = (rect.y) - 1;
    while (++i < rect.y + rect.height)
    {
        j = (rect.x) - 1;
        while (++j < rect.x + rect.width)
            img_pix_put(img, j, i, rect.color);
    }
    return (0);
}

int no_event(void *data)
{
 //   printf("coucou no event\n");
    return (0);
}
int escape_window(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    return (0);
}
int render(t_data *data)
{
    if (data->win_ptr == NULL)
		return (1);
    get_background(&data->img, PURPLE_COL);
    get_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GREEN2_COL});
    get_rect(&data->img, (t_rect){0, 0, 100, 100, RED_COL});

    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
    return (0);
}

int main(void)
{
    t_data data;
    
    /*Initialisation du display*/
    data.mlx_ptr = mlx_init();
    if(!data.mlx_ptr)
        return (0); 
    /*Creation de la fenetre*/
    data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "window");
    if (!data.win_ptr)
    {
        free(data.win_ptr);
        return (0);
    }


    /*gestion des evenements*/
    data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT); //initialise une image de la taille de notre fenetre afin de de dessiner dedans
    data.img.addr = mlx_get_data_addr(data.img.mlx_img, \
    &data.img.bits_per_pix, &data.img.line_len, &data.img.endian); // set les infos de l'image afin de gerer pixels par pixels
    mlx_loop_hook(data.mlx_ptr, &render, &data); //affiche notre carre
    mlx_key_hook(data.win_ptr, &escape_window, &data); // permet de tuer la fenetre
    mlx_loop(data.mlx_ptr); // continue de boucler tant qu'elle trouve la fenetre ouverte


    /*sortie propre du programme*/
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);
    return (0);
}











