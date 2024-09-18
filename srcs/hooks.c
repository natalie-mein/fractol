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
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(param);
    if (keydata.key == MLX_KEY_TAB && keydata.action == MLX_PRESS)
        help_msg();
}

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
        fractol->mdiff = (fractol->zoom * fractol->diff) - fractol->diff;
    if (ydelta > 0)
        fractol->mdiff = ((1 / fractol->zoom) * fractol->diff) - fractol->diff;
    fractol->r_min = fractol->r_min - fractol->mdiff * fractol->x_ratio;
    fractol->r_max = fractol->r_max + fractol->mdiff * (1 - fractol->x_ratio);
    fractol->i_min = fractol->i_min - fractol->mdiff * (1 - fractol->y_ratio);
    fractol->i_max = fractol->i_max + fractol->mdiff * fractol->y_ratio;
}

void arrow_keys(mlx_key_data_t keydata, void* param)
{

}
void    colors_hook(void *params)
{

}

void    julia_hook(void *params)
{

}