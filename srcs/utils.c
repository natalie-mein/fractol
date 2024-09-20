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
double	ft_abs(double x)
{
	if (x >= 0)
		return (x);
	return (-x);
}

// pixel_colors
int32_t	ft_pixel(int32_t red, int32_t green, int32_t blue, int32_t a)
{
	return (red << 24 | green << 16 | blue << 8 | a);
}

double	ft_atof(char *str)
{
	double	n;
	int	sign;
	int	dec;

	n = 0.0;
	sign = 1;
	dec = 1;
	if (str == NULL)
		return (0.0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
			sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		n = n * 10 + (*str++ - '0');
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str++ - '0');
		dec *= 10;
	}
	return (sign * (n / dec));
}
