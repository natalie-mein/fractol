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

typedef	struct s_map
{
	double	x;
	double	y;
}	t_map;


typedef struct	s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			type;
	double		r_min;
	double		r_max;
	double		i_min;
	double		i_max;
	t_map		c;
	t_map		z;
	t_map		julia;
	int32_t		x_pix;
	int32_t		y_pix;
}	t_fractol;

/* Initialization*/
void    mandelbrot_init(t_fractol *fractol);
void    julia_init(t_fractol *fractol);
void    burning_init(t_fractol *fractol);
void    mandelbox_init(t_fractol *fractol);

/* hooks*/
void	help_msg(void);
void	ft_hook(mlx_key_data_t keydata, void* param);
void	arrow_keys(mlx_key_data_t keydata, void* param);
void    ft_scroll(double xdelta, double ydelta, void* param);

/* colors */
float   mandel_color(t_fractol *fractol, int x, int y);
float   julia_color(t_fractol *fractol, int x, int y);
float   burning_color(t_fractol *fractol, int x, int y);
float   mandelbox_color(t_fractol *fractol, int x, int y);

#endif