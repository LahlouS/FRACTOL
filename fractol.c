#include "fractol.h"

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

int main(void)
{
    t_data data;
    
    data.mlx_ptr = mlx_init();
    if(!data.mlx_ptr)
        return (0); 
    data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "window");
    if (!data.win_ptr)
    {
        free(data.win_ptr);
        return (0);
    }


    /*gestion des evenements*/
    mlx_loop_hook(data.mlx_ptr, &no_event, &data); //affiche notre carre
    mlx_key_hook(data.win_ptr, &escape_window, &data); // permet de tuer la fenetre
    mlx_loop(data.mlx_ptr); // continue de boucler tant qu'elle trouve la fenetre ouverte


    /*sortie propre du programme*/
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);
    return (0);
}