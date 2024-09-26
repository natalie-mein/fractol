/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:48:21 by nmeintje          #+#    #+#             */
/*   Updated: 2024/09/23 15:49:07 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(fractol->mlx);
	if (keydata.key == MLX_KEY_TAB && keydata.action == MLX_PRESS)
		help_msg();
}

/* recalculates fractals viewing window to zoom in or out based on mouse scrolls
 uses the mouse position to control how the zoom is distributed across the screen
 mouse horizontal position relative to screen width
 vertical postion relative to screen height
 total range of the view
 ydelta < 0 == scroll up
 ydelta > 0 == scroll down
 how much range is reduced by zooming in
 expands range - zooms out
 update fractal view range for real parts
 update fractal view range for imaginary parts */
void	ft_scroll(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;

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

void	arrow_keys(void *param)
{
	t_fractol	*fractol;
	double		rdelta;
	double		idelta;

	fractol = (t_fractol *)param;
	rdelta = fractol->r_max - fractol->r_min;
	idelta = fractol->i_max - fractol->i_min;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT))
	{
		fractol->r_min -= 0.025 * rdelta;
		fractol->r_max -= 0.025 * rdelta;
	}
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_RIGHT))
	{
		fractol->r_min += 0.025 * rdelta;
		fractol->r_max += 0.025 * rdelta;
	}
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_UP))
	{
		fractol->i_min += 0.025 * idelta;
		fractol->i_max += 0.025 * idelta;
	}
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_DOWN))
	{
		fractol->i_min -= 0.025 * idelta;
		fractol->i_max -= 0.025 * idelta;
	}
}

void	julia_hook(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT_CONTROL))
	{
		if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT_SHIFT))
			fractol->julia.x *= 0.9;
		else
			fractol->julia.x *= 1.1;
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_RIGHT_CONTROL))
	{
		if (mlx_is_key_down(fractol->mlx, MLX_KEY_RIGHT_SHIFT))
			fractol->julia.y *= 0.9;
		else
			fractol->julia.y *= 1.1;
	}
}
