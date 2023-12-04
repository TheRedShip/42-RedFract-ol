/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:12:41 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/04 17:44:50 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double calculate_julia_px(int x, int y, t_fractol *fractol)
{
	long double zx = (x / fractol->zoom + fractol->x_set);
	long double zy = (y / fractol->zoom + fractol->y_set);
	zx = ((zx / WIDTH) - 0.5) * 3.5 * ASPECT_RATIO;
	zy = ((zy / WIDTH) - 0.5) * 3.5;

	int iteration = 0;
	double smoothcolor = exp(-(zx * zx + zy * zy));
	while (zx * zx + zy * zy < 4 && iteration < (int)fractol->max_iter) 
	{
		double xtemp = zx * zx - zy * zy;
		zy = 2 * zx * zy + fractol->complex_y;
		zx = xtemp + fractol->complex_x;
		if (fractol->smoothing)
			smoothcolor += exp(-(zx * zx + zy * zy));
		iteration++;
	}
	if (iteration == (int)fractol->max_iter)
		return (-1);
	else
	{
		if (fractol->smoothing)
			return (smoothcolor);
		return (iteration);
	}
}

void julia(t_fractol *fractol)
{
	int y;
	int x;
	long double	iteration;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			iteration = calculate_julia_px(x, y, fractol);
			if (iteration == -1)
				put_pixel(&(fractol->img), x, y, 0);
			else
				put_pixel(&(fractol->img), x, y, color_smoothing(iteration, fractol));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img.img, 0, 0);
}
