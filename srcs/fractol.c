/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:14:09 by nmeintje          #+#    #+#             */
/*   Updated: 2024/08/01 13:16:19 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_check_args(t_fractol fractol)
{

}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	// error check
	// if no argv are given then go to error message and exit.
	// send to function for processing
	// exit
	if (argc < 2 || !ft_check_args(fractol))
			help_msg();

	if (ft_check_args(fractal))
		ft_process_args(fractal);
	//mlx_loop_hook(mlx, ft_hook, mlx);
	//mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
