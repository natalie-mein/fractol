/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:33:36 by nmeintje          #+#    #+#             */
/*   Updated: 2024/09/02 14:49:42 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Mandelbrot initialization
void    mandelbrot_init(t_fractol *fractol)
{
    fractol->r_min = -2.0;
    fractol->r_max = 0.7;
    fractol->i_min = -1.2;
    fractol->i_max = 1.2;
}

// Julia function
void    julia_init(t_fractol *fractol)
{
    fractol->r_min = -1.7;
    fractol->r_max = 1.7;
    fractol->i_min = -1.7;
    fractol->i_max = 1.7;
}

void    julia_params(t_fractol *fractol, char **av)
{
    if (!av[2])
    {
        fractol->julia.x = -0.745429;
        fractol->julia.y = 0.05;
    }
    else if(!av[3])
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

// Burning ship function
void    burning_init(t_fractol *fractol)
{
    fractol->r_min = -1.0;
    fractol->r_max = 2.0;
    fractol->i_min = -1.0;
    fractol->i_max = 2.0;
}

// Mandelbox function
void    mandelbox_init(t_fractol *fractol)
{
    // scale
    // box_fold
    /*fractol->r_min = -2.0;
    fractol->r_max = 2.0;
    fractol->i_min = -2.0;
    fractol->i_max = 2.0; */
}
