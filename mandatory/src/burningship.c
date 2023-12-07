/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:25:49 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/07 15:44:53 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	ab(double a)
{
	if (a < 0)
		return (a);
	return (-a);
}

double	calculate_ship_px(int x, int y, t_fractol *fractol, int i)
{
	long double	cx0;
	long double	cy0;
	long double	zx;
	long double	zy;
	long double	temp;

	cx0 = (x / fractol->zoom + fractol->x_set);
	cy0 = (y / fractol->zoom + fractol->y_set);
	cx0 = ((cx0 / WIDTH) * 3.5) - 2.5 * fractol->ratio;
	cy0 = ((cy0 / HEIGHT) * 3.5) - 2.5;
	zx = cx0;
	zy = cy0;
	while (zx * zx + zy * zy < 8 && i < (int)fractol->max_iter)
	{
		temp = zx * zx - zy * zy + cx0;
		zy = ab(2 * zx * zy) - cy0;
		zx = temp;
		i++;
	}
	if (i == (int)fractol->max_iter)
		return (-1);
	if (fractol->smoothing)
		return (i + 1 - log(log(sqrt(zx * zx + zy * zy))) / M_LN2);
	return (i);
}

void	burningship(t_fractol *fractol)
{
	int			y;
	int			x;
	long double	i;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			i = calculate_ship_px(x, y, fractol, 0);
			if (i == -1)
				put_pixel(&(fractol->img), x, y, 0);
			else
				put_pixel(&(fractol->img), x, y, color_smoothing(i, fractol));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, \
							fractol->img.img, 0, 0);
}
