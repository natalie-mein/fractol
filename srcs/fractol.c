/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:14:09 by nmeintje          #+#    #+#             */
/*   Updated: 2024/08/01 15:17:47 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_check_args(int argc, char **argv)
{
	if (argc >= 2)
	{
		if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0 
				|| ft_strncmp(argv[1], "Julia", 5) == 0)
			return (1);
	}
	else
		return (0);

}

static void 	ft_process_args(int argc, char **argv)
{

}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	// if no argv are given then go to error message and exit.
	// send to function for processing
	// exit
	if (argc < 2 || argc > 3 || !ft_check_args(argc, argv))
			help_msg();

	if (ft_check_args(fractal))
		ft_process_args(argc, argv);
	//mlx_loop_hook(mlx, ft_hook, mlx);
	//mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
