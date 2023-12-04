/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:25:49 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/04 14:28:38 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double calculate_ship_px(int x, int y, t_fractol *fractol) //not working
{
	double cx0 = (((double)x / WIDTH) * 3.5) - 2.5;
	double cy0 = (((double)y / HEIGHT) - 0.5) * 2;
	double zx = cx0;
	double zy = cy0;

	int iteration = 0;
	int max_iteration = 100;
	while (zx * zx + zy * zy < 4 && iteration < max_iteration)
	{
		double zxn1 = zx * zx - zy * zy + cx0;
		zy = ft_abs(2 * zx * zy) - cy0;
		zx = zxn1;
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

void burningship(t_fractol *fractol)
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
			iteration = calculate_ship_px(x, y, fractol);
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