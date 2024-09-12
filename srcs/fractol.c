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

static int	ft_check_args(char *str, t_fractol fractol)
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
	if (ft_strncmp(str, "mandelbox", 10) == 0)
	{
		fractol->type = MANDELBOX;
		return (1);
	}
	else
	{
		fractol->type = -1;
		return (0);
	}
}

static void 	ft_process_args(int argc, char **argv)
{

}

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (argc < 2 || !ft_check_args(argv[1], fractol))
	{
		help_msg();
		// probably need to free the pointer here.
	}
	if (ft_check_args(fractol))
		ft_process_args(argc, argv);
	//mlx_loop_hook(mlx, ft_hook, mlx);
	//mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
