/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:14:57 by nmeintje          #+#    #+#             */
/*   Updated: 2024/09/23 16:04:28 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

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

typedef struct s_map
{
	double	x;
	double	y;
}	t_map;

typedef struct s_color
{
	double	red;
	double	green;
	double	blue;
}	t_color;

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			type;
	char		*set;
	double		r_min;
	double		r_max;
	double		i_min;
	double		i_max;
	double		zoom;
	int			color;
	t_color		rgb;
	t_map		c;
	t_map		z;
	t_map		julia;
	int32_t		x_pix;
	int32_t		y_pix;
	double		x_ratio;
	double		y_ratio;
	double		diff;
	double		rdiff;
}	t_fractol;

/* Initialization*/
void	mandelbrot_init(t_fractol *fractol);
void	julia_init(t_fractol *fractol);
void	julia_params(t_fractol *fractol, char **av);
void	burning_init(t_fractol *fractol);

/* hooks*/
void	help_msg(void);
void	ft_hook(mlx_key_data_t keydata, void *param);
void	arrow_keys(void *param);
void	ft_scroll(double xdelta, double ydelta, void *param);
void	julia_hook(void *param);
void	colors_hook(void *param);

/* colors */
int32_t	mandel_color(t_fractol *fractol, double x, double y);
int32_t	julia_color(t_fractol *fractol, double x, double y);
int32_t	burning_color(t_fractol *fractol, double x, double y);
int32_t	ft_pixel(int32_t red, int32_t green, int32_t blue, int32_t a);
int32_t	compute_color(t_fractol *fractol, int i);

/* utils */
double	ft_atof(char *str);
double	ft_abs(double x);

#endif
