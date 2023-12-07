/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:09:13 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/07 16:27:45 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	calculate_mandel_px(int x, int y, t_fractol *fractol, int i)
{
	long double	zx;
	long double	zy;
	long double	cx0;
	long double	cy0;
	long double	xtemp;

	zx = 0;
	zy = 0;
	cx0 = (x / fractol->zoom + fractol->x_set);
	cy0 = (y / fractol->zoom + fractol->y_set);
	cx0 = ((cx0 / WIDTH) - 0.5) * 2 * fractol->ratio;
	cy0 = ((cy0 / HEIGHT) - 0.5) * 2;
	while (zx * zx + zy * zy < 9 && i < (int)fractol->max_iter)
	{
		xtemp = zx * zx - zy * zy + cx0;
		zy = 2 * zx * zy + cy0;
		zx = xtemp;
		i++;
	}
	if (i == (int)fractol->max_iter || i == 0)
		return (-1);
	if (fractol->smoothing)
		return (i + 1 - log(log(sqrt(zx * zx + zy * zy))) / M_LN2);
	return (i);
}

void	mandelbrot(t_fractol *fractol)
{
	int		y;
	int		x;
	double	iteration;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			iteration = calculate_mandel_px(x, y, fractol, 0);
			if (iteration == -1)
				put_pixel(&(fractol->img), x, y, 0);
			else
				put_pixel(&(fractol->img), x, y, \
					color_smoothing(iteration, fractol));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, \
			fractol->img.img, 0, 0);
}
