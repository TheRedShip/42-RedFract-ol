/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:09:13 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/04 14:54:34 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double calculate_mandel_px(int x, int y, t_fractol *fractol)
{
	double zx = 0;
	double zy = 0;
	long double aspect_ratio = (long double)WIDTH / (long double)HEIGHT;
	long double cx0 = (x / fractol->zoom + fractol->x_set);
	long double cy0 = (y / fractol->zoom + fractol->y_set);
	cx0 = (cx0 - WIDTH / 2) * 1 / (WIDTH / 2) * aspect_ratio;
	cy0 = (cy0 - HEIGHT / 2) * 1 / (HEIGHT / 2);

	int iteration = 0;
	int max_iteration = 200;
	while (zx * zx + zy * zy < 9 && iteration < max_iteration)
	{
		double xtemp = zx * zx - zy * zy + cx0;
		zy = 2 * zx * zy + cy0;
		zx = xtemp;
		iteration++;
	}
	if (iteration == max_iteration || iteration == 0)
		return (0);
	else
	{
		if (fractol->smoothing)
		{
			double abs_z = zx * zx + zy * zy;
			double smooth = iteration + 1 - log(log(sqrt(abs_z))) / log(2);
			return (smooth);
		}
		return (iteration);
	}
}

void mandelbrot(t_fractol *fractol)
{
	int y;
	int x;
	double	iteration;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			iteration = calculate_mandel_px(x, y, fractol);
			if (iteration == 0)
				put_pixel(&(fractol->img), x, y, rgb_to_hex(0, 0, 0, 0));
			else
				put_pixel(&(fractol->img), x, y, color_smoothing(iteration, fractol)); // 0x000000FF + iteration * 20
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img.img, 0, 0);
}