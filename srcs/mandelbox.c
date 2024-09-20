/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:40:15 by nmeintje          #+#    #+#             */
/*   Updated: 2024/09/19 13:40:18 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* int32_t mandelbox_color(t_fractol *fractol, double c_x, double c_y)
{
    double scale = 2.0;
    double fixed_radius = 1.0;
    double min_radius = 0.5;
    double x_r = c_x;
    double y_r = c_y;
    double z_r = 0;
    double distance;
    int i = 0;
    while (i < MAX_ITER)
    {
        distance = sqrt(x_r * x_r + y_r * y_r + z_r * z_r);
        if (distance > fixed_radius) {
            x_r = (x_r / distance) * fixed_radius;
            y_r = (y_r / distance) * fixed_radius;
            z_r = (z_r / distance) * fixed_radius;
        }
        if (distance < min_radius) {
            x_r = (x_r / distance) * min_radius;
            y_r = (y_r / distance) * min_radius;
            z_r = (z_r / distance) * min_radius;
        }
        x_r = x_r * scale + c_x;
        y_r = y_r * scale + c_y;
        z_r = z_r * scale;        
        i++;
    }
    if (i == MAX_ITER)
        return ft_pixel(0, 0, 0, 255);
    else
        return compute_color(fractol, i);
} */

// Function to apply box folding

double box_fold(double v) {
    if (v > 1)
        return 2 - v;
    else if (v < -1)
        return -2 - v;
    return v;
}

// Function to apply ball folding
double ball_fold(double r, double m) {
    if (m < r)
        return m / (r * r);
    else if (m < 1)
        return 1 / (m * m);
    return m;
}

// Main Mandelbox function
int mandelbox(t_fractol *fractol, double cr, double ci) {
    int n = 0;
    double vr = cr;
    double vi = ci;
    double mag = 0;

    while (n < MAX_ITER) {
        vr = fractol->box.fx * box_fold(vr);
        vi = fractol->box.fx * box_fold(vi);
        mag = vr * vr + vi * vi; // Use squared magnitude to avoid sqrt

        vr = vr * fractol->box.sx * ball_fold(fractol->box.rx, mag) + cr;
        vi = vi * fractol->box.sx * ball_fold(fractol->box.rx, mag) + ci;

        if (mag > 4) // Check for escape using squared magnitude
            break;
        n++;
    }
    return n; // Return the number of iterations
}
