/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:14:57 by nmeintje          #+#    #+#             */
/*   Updated: 2024/08/01 15:27:17 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

# define WIDTH 1080
# define HEIGHT 1080
# define MAX_ITER 100
# define MANDELBROT 1
# define JULIA 2
# define BURNING 3
# define MANDELBOX 4
# define JULIA_SETS 5

typedef struct	s_fractol
{
	mlx_t		*mlx;
	mlt_image_t	*image;
	int			type;
}	t_fractol;

#endif
