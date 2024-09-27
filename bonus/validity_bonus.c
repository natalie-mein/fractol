/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:43:45 by nmeintje          #+#    #+#             */
/*   Updated: 2024/09/27 12:11:30 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

// is_valid
int	ft_valid_arg(int ac, char **av, t_fractol *f)
{
	if (ac == 3 && (ft_strncmp(av[1], "julia", 6) == 0))
	{
		if (!ft_signed_dec(av[2]))
			help_msg();
		else
		{
			f->type = JULIA;
			return (1);
		}
	}
	else if (ac == 4 && (ft_strncmp(av[1], "julia", 6) == 0))
	{
		if ((!ft_signed_dec(av[2]) || (!ft_signed_dec(av[3]))))
			help_msg();
		else
		{
			f->type = JULIA;
			return (1);
		}
	}
	return (0);
}

// is signed decimal
int	ft_signed_dec(char *str)
{
	int	dec;
	int	num;

	dec = 0;
	num = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str == '.')
		{
			if (dec)
				return (0);
			dec = 1;
		}
		else if (ft_isdigit((unsigned char) *str))
			num = 1;
		else
			return (0);
		str++;
	}
	return (num);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
