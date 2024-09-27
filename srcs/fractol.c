/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:14:09 by nmeintje          #+#    #+#             */
/*   Updated: 2024/09/27 12:03:19 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!n)
		return (0);
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	ft_check_args(int ac, char **av, t_fractol *fractol)
{
	if (ac == 2)
	{
		if (ft_strncmp(av[1], "mandelbrot", 11) == 0)
		{
			fractol->type = MANDELBROT;
			return (1);
		}
		if (ft_strncmp(av[1], "julia", 6) == 0)
		{
			fractol->type = JULIA;
			return (1);
		}
	}
	else
	{
		fractol->type = -1;
		return (0);
	}
	return (0);
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
	if (!fractol)
		return (0);
	if (argc < 2 || !ft_check_args(argc, argv, fractol))
	{
		free(fractol);
		help_msg();
	}
	if (argc > 2)
		ft_valid_arg(argc, argv, fractol);
	fractol_init(fractol, argv);
	mlx_loop_hook(fractol->mlx, &ft_fractal, fractol);
	mlx_key_hook(fractol->mlx, &ft_hook, fractol);
	mlx_loop_hook(fractol->mlx, &arrow_keys, fractol);
	mlx_loop_hook(fractol->mlx, &julia_hook, fractol);
	mlx_scroll_hook(fractol->mlx, &ft_scroll, fractol);
	mlx_loop(fractol->mlx);
	mlx_terminate(fractol->mlx);
	free(fractol);
	return (0);
}
