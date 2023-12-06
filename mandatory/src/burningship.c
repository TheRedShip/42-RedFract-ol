/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:25:49 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/06 15:51:54 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double ab(double a)
{
	if (a < 0)
		return (a);
	return (-a);
}

double calculate_ship_px(int x, int y, t_fractol *fractol)
{
	long double cx0 = (x / fractol->zoom + fractol->x_set);
	long double cy0 = (y / fractol->zoom + fractol->y_set);
	cx0 = ((cx0 / WIDTH) * 3.5) - 2.5 * ASPECT_RATIO;
	cy0 = ((cy0 / HEIGHT) * 3.5) - 2.5;
	long double zx = cx0;
	long double zy = cy0;

	int iteration = 0;
	while (zx * zx + zy * zy < 8 && iteration < (int)fractol->max_iter)
	{
		long double zxn1 = zx * zx - zy * zy + cx0;
		zy = ab(2 * zx * zy) - cy0;
		zx = zxn1;
		iteration++;
	}
	if (iteration == (int)fractol->max_iter)
		return (-1);
	else
	{
		if (fractol->smoothing)
		{
			double abs_z = zx * zx + zy * zy;
			double smooth = iteration + 1 - log(log(sqrt(abs_z))) / M_LN2;
			return (smooth);
		}
		return (iteration);
	}
}

void burningship(t_fractol *fractol)
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
			iteration = calculate_ship_px(x, y, fractol);
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
