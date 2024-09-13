/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:04:14 by nmeintje          #+#    #+#             */
/*   Updated: 2024/08/01 15:12:13 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help_msg(void)
{
	ft_putendl_fd("~~~~~~~~Available Fractals~~~~~~~~~~", 1);
	ft_putendl_fd("\tPlease type:", 1);
	ft_putendl_fd("mandelbrot, julia, burning or mandelbox", 1);
	ft_putendl_fd("\n", 1);
	ft_putendl_fd("For Julia, you may specify starting values", 1);
	ft_putendl_fd("between -2.0 and 2.0. Remember to include", 1);
	ft_putendl_fd("one decimal place.", 1);
	exit (1);
}

// ft_abs

// pixel_colors

// ft_atof