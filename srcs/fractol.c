/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:14:09 by nmeintje          #+#    #+#             */
/*   Updated: 2024/09/02 14:33:16 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_check_args(char *str, t_fractol *fractol)
{
	if (ft_strncmp(str, "mandelbrot", 11) == 0)
	{
		fractol->type = MANDELBROT;
		return (1);
	}
	if (ft_strncmp(str, "julia", 6) == 0)
	{
		fractol->type = JULIA;
		return (1);
	}
	if (ft_strncmp(str, "burning", 9) == 0)
	{
		fractol->type = BURNING;
		return (1);
	}
	else
	{
		fractol->type = -1;
		return (0);
	}
}

static void	fractol_init(t_fractol *fractol, char **av)
{
	if (fractol->type == MANDELBROT)
		mandelbrot_init(fractol);
	else if (fractol->type == JULIA)
	{
		julia_init(fractol);
		julia_params(fractol, av);
	}
	else if (fractol->type == BURNING)
		burning_init(fractol);
	fractol->zoom = 1.05;
	fractol->color = 1;
	fractol->set = av[1];
	fractol->rgb.red = 0.0;
	fractol->rgb.green = 0.0;
	fractol->rgb.blue = 0.0;
	fractol->mlx = mlx_init(WIDTH, HEIGHT, fractol->set, false);
	fractol->image = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(fractol->mlx, fractol->image, 0, 0);
}

void	ft_fractal(void *param)
{
	t_fractol	*fractol;
	uint32_t	y;
	uint32_t	x;
	int			color;

	fractol = (t_fractol *)param;
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (fractol->type == MANDELBROT)
				color = mandel_color(fractol, x, y);
			else if (fractol->type == JULIA)
				color = julia_color(fractol, x, y);
			else if (fractol->type == BURNING)
				color = burning_color(fractol, x, y);
			mlx_put_pixel(fractol->image, x, y, color);
			y++;
		}
		x++;
	}
}

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (argc < 2 || !ft_check_args(argv[1], fractol))
		help_msg();
	fractol_init(fractol, argv);
	mlx_loop_hook(fractol->mlx, &ft_fractal, fractol);
	mlx_key_hook(fractol->mlx, &ft_hook, fractol);
	mlx_loop_hook(fractol->mlx, &arrow_keys, fractol);
	mlx_loop_hook(fractol->mlx, &colors_hook, fractol);
	mlx_loop_hook(fractol->mlx, &julia_hook, fractol);
	mlx_scroll_hook(fractol->mlx, &ft_scroll, fractol);
	mlx_loop(fractol->mlx);
	mlx_terminate(fractol->mlx);
	return (0);
}
