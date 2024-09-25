/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:33:36 by nmeintje          #+#    #+#             */
/*   Updated: 2024/09/25 13:58:08 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Mandelbrot initialization
void	mandelbrot_init(t_fractol *fractol)
{
	fractol->r_min = -1.5;
	fractol->r_max = 1.0;
	fractol->i_min = -1.0;
	fractol->i_max = 1.0;
}

// Julia function
void	julia_init(t_fractol *fractol)
{
	fractol->r_min = -1.7;
	fractol->r_max = 1.7;
	fractol->i_min = -1.7;
	fractol->i_max = 1.7;
}

void	julia_params(t_fractol *fractol, char **av)
{
	if (!av[2])
	{
		fractol->julia.x = -0.745429;
		fractol->julia.y = 0.05;
	}
	else if (!av[3])
	{
		fractol->julia.x = ft_atof(av[2]);
		fractol->julia.y = 0.0;
	}
	else
	{
		fractol->julia.x = ft_atof(av[2]);
		fractol->julia.y = ft_atof(av[3]);
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
