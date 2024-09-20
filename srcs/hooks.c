/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:48:21 by nmeintje          #+#    #+#             */
/*   Updated: 2024/09/13 12:48:24 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_hook(mlx_key_data_t keydata, void* param)
{
    t_fractol   *fractol;

    fractol = (t_fractol *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(fractol->mlx);
    if (keydata.key == MLX_KEY_TAB && keydata.action == MLX_PRESS)
        help_msg();
}

/* recalculates fractals viewing window to zoom in or out based on mouse scrolls
 uses the mouse position to control how the zzom is distributed across the screen
 mouse horiz pos relatv to screen width
 vertical pos relativ to screen height
 total range of the view
 ydelta < 0 == scroll up
 ydelta > 0 == scroll down
 how much range is reduced by zooming in
 expands range - zooms out
 update fractal view range for real parts
 update fractal view range for imaginary parts */
void    ft_scroll(double xdelta, double ydelta, void* param)
{
    t_fractol   *fractol;

    (void) xdelta;
    fractol = (t_fractol *)param;
    fractol->x_pix = 0;
    fractol->y_pix = 0;
    mlx_get_mouse_pos(fractol->mlx, &fractol->x_pix, &fractol->y_pix);
    fractol->x_ratio = (double)fractol->x_pix / WIDTH; 
    fractol->y_ratio = (double)fractol->y_pix / HEIGHT; 
    fractol->diff = fractol->r_max - fractol->r_min; 
    if (ydelta < 0)  
        fractol->rdiff = (fractol->zoom * fractol->diff) - fractol->diff; 
    if (ydelta > 0) 
        fractol->rdiff = ((1 / fractol->zoom) * fractol->diff) - fractol->diff; 
    fractol->r_min = fractol->r_min - fractol->rdiff * fractol->x_ratio;
    fractol->r_max = fractol->r_max + fractol->rdiff * (1 - fractol->x_ratio);
    fractol->i_min = fractol->i_min - fractol->rdiff * (1 - fractol->y_ratio); 
    fractol->i_max = fractol->i_max + fractol->rdiff * fractol->y_ratio;
}

/* fix this */
void arrow_keys(void* param)
{
    t_fractol   *fractol;
    double      delta;

    fractol = (t_fractol*)param;
    delta = fractol->r_max - fractol->r_min;
    if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT))
    {
        fractol->r_min -= 0.025 * delta;
        fractol->r_max -= 0.025 * delta;
    }
    if (mlx_is_key_down(fractol->mlx, MLX_KEY_RIGHT))
    {
        fractol->r_min += 0.025 * delta;
        fractol->r_max += 0.025 * delta;
    }
    if (mlx_is_key_down(fractol->mlx, MLX_KEY_UP))
    {
        fractol->i_min -= 0.025 * delta;
        fractol->i_max -= 0.025 * delta;
    }
    if (mlx_is_key_down(fractol->mlx, MLX_KEY_DOWN))
    {
        fractol->i_min += 0.025 * delta;
        fractol->i_max += 0.025 * delta;
    }
}
/*void    colors_hook(void *params)
{

}

void    julia_hook(void *params)
{

} */