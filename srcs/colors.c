/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:05:43 by nmeintje          #+#    #+#             */
/*   Updated: 2024/09/13 13:05:45 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// mandelbrot color
int32_t   mandel_color(t_fractol *frac, double c_x, double c_y)
{
    double  pixel_size;
    double  temp;
    int     i;

    i = 0;
    frac->z.x = 0.0;
    frac->z.y = 0.0;
    pixel_size = (frac->r_max - frac->r_min) / WIDTH;
    c_x = frac->r_min + c_x * pixel_size;
    c_y = frac->r_max - (c_y * pixel_size);
    temp = 0;
    while (frac->z.x * frac->z.x + frac->z.y * frac->z.y < 4 && i < MAX_ITER)
    {
        temp = frac->z.x;
        frac->z.x = frac->z.x * frac->z.x - frac->z.y * frac->z.y + c_x;
        frac->z.y = 2 * temp * frac->z.y + c_y;
        i++;
    }
    if (i == MAX_ITER)
        return (ft_pixel(0, 0, 0, 255));
    else
        return (compute_color(frac, i));
}

// julia color
int32_t   julia_color(t_fractol *frac,  double z_x, double z_y)
{
    double  pixel_width;
    double  pixel_height;
    double  temp;
    int     i;

    i = 0;
    pixel_width = (frac->r_max - frac->r_min) / WIDTH;
    pixel_height = (frac->i_max - frac->i_min) / HEIGHT;
    z_x = frac->r_min + z_x * pixel_width;
    z_y = frac->i_max - (z_y * pixel_height);
    temp = 0;
    while ((z_x * z_x) + (z_y * z_y) < 4 && i < MAX_ITER)
    {
        temp = z_x;
        z_x = (z_x * z_x) - (z_y * z_y) + frac->julia.x;
        z_y = 2 * temp * z_y + frac->julia.y;
        i++;
    }
    if (i == MAX_ITER)
        return (ft_pixel(0, 0, 0, 255));
    else
        return (compute_color(frac, i));
}

int32_t   burning_color(t_fractol *frac, double c_x, double c_y)
{
    double  pixel_size;
    double  temp;
    int     i;

    i = 0;
    frac->z.x = 0.0;
    frac->z.y = 0.0;
    pixel_size = (frac->r_max - frac->r_min) / WIDTH;
    c_x = frac->r_min + c_x * pixel_size;
    c_y = frac->i_min + (c_y * pixel_size);
    temp = 0;
    while (frac->z.x * frac->z.x + frac->z.y * frac->z.y < 4 && i < MAX_ITER)
    {
        temp = frac->z.x;
        frac->z.x = frac->z.x * frac->z.x - frac->z.y * frac->z.y + c_x;
        frac->z.y = 2 * ft_abs(temp * frac->z.y) + c_y;
        i++;
    }
    if (i == MAX_ITER)
        return (ft_pixel(0, 0, 0, 255));
    else
        return (compute_color(frac, i));
}

/* int32_t   mandelbox_color(t_fractol *frac, double c_x, double c_y)
{
    double  pixel_size;
    double  distance;
    int     i;

    i = 0;
    frac->z.x = 0.0;
    frac->z.y = 0.0;
    pixel_size = (frac->r_max - frac->r_min) / WIDTH;
    c_x = frac->r_min + c_x * pixel_size;
    c_y = frac->r_max - (c_y * pixel_size);
    distance = 0;
    while (distance < 4 && i < MAX_ITER)
    {
        distance = sqrt(frac->z.x * frac->z.x + frac->z.y * frac->z.y);
        if (distance > 1.0)
        {
            frac->z.x = (frac->z.x / distance) * 1.0;
            frac->z.y = (frac->z.y / distance) * 1.0;
        }
        frac->z.x = frac->z.x * 2.0 + c_x;
        frac->z.y = frac->z.y * 2.0 + c_y;
        i++;
    }
    if (i == MAX_ITER)
        return (ft_pixel(0, 0, 0, 255));
    else
        return (compute_color(frac, i));
} */

int32_t mandelbox_color(t_fractol *fractol, double c_x, double c_y) 
{
    double cr;
    double ci;
    int     iterations;

    cr = fractol->r_min + c_x * (fractol->r_max - fractol->r_min) / WIDTH;
    ci = fractol->i_max - c_y * (fractol->i_max - fractol->i_min) / HEIGHT;
    iterations = mandelbox(fractol, cr, ci);
    if (iterations == MAX_ITER)
        return (ft_pixel(0, 0, 0, 255));
    else
        return (compute_color(fractol, iterations));
}


/* Normalize the iteration count to [0, 1]
Frequency multipliers for each color channel
Controls the "speed" of color oscillation
Use sine waves for smooth color transitions 
Shift to [0, 255]
Phase shift for variety 
Combine the colors into the final pixel value */
int32_t compute_color(t_fractol *fractol, int i)
{
    double  t;
    
    t = 1.0 * i / (MAX_ITER);
    if (fractol->color == 1)
    {
        fractol->rgb.red = 255 * 8.5 * (1 - t) * t * t * t;
        fractol->rgb.green = 9 * 255 * (1 - t) * (1 - t) * t * t;
        fractol->rgb.blue = 8.5 * 255 * ( 1 - t) * (1 - t) * (1 - t) * t;
    }
    if (fractol->color == 2)
    {
        fractol->rgb.red = 255 * 9 * (1 - t) * t * t * t;
        fractol->rgb.green = 15 * 255 * (1 - t) * (1 - t) * t * t;
        fractol->rgb.blue = 8.5 * 255 * (1 - t) * (1 - t) * (1 - t) * t;
    }
    if (fractol->color == 3)
    {
        fractol->rgb.red = 255 * 15 * (1 - t) * t * t * t;
        fractol->rgb.green = 8.5 * 255 * (1 - t) * (1 - t) * t * t;
        fractol->rgb.blue = 9 * 255 * (1 - t) * (1 - t) * (1 - t) * t;
    }
    return ft_pixel(fractol->rgb.red, fractol->rgb.green, fractol->rgb.blue, 255);
}
