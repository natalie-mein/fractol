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
# define MAX_ITER 50
# define MANDELBROT 1
# define JULIA 2
# define BURNING 3
# define MANDELBOX 4

typedef	struct s_map
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

typedef	struct s_box
{
	double	fx;
	double	sx;
	double	rx;
}	t_box;


typedef struct	s_fractol
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
	t_box		box;
	int32_t		x_pix;
	int32_t		y_pix;
	double		x_ratio;
	double		y_ratio;
	double		diff;
	double		rdiff;
}	t_fractol;

/* Initialization*/
void    mandelbrot_init(t_fractol *fractol);
void    julia_init(t_fractol *fractol);
void    julia_params(t_fractol *fractol, char **av);
void    burning_init(t_fractol *fractol);
void    mandelbox_init(t_fractol *fractol);

/* hooks*/
void	help_msg(void);
void 	ft_hook(mlx_key_data_t keydata, void* param);
void	arrow_keys(void* param);
void    ft_scroll(double xdelta, double ydelta, void* param);
void    julia_hook(void *params);

/* colors */
int32_t	mandel_color(t_fractol *fractol, double x, double y);
int32_t julia_color(t_fractol *fractol,  double x, double y);
int32_t	burning_color(t_fractol *fractol, double x, double y);
int32_t	mandelbox_color(t_fractol *fractol, double x, double y);
int32_t	ft_pixel(int32_t red, int32_t green, int32_t blue, int32_t a);
int32_t	compute_color(t_fractol *fractol, int i);

/* utils */
double	ft_atof(char *str);
double	ft_abs(double x);

/* mandelbox */
double box_fold(double v);
double ball_fold(double r, double m);
int mandelbox(t_fractol *fractol, double cr, double ci);

#endif