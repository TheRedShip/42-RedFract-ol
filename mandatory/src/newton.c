/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:40:28 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/07 16:58:19 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	calculate_color(t_complex result, int i, t_fractol *fractol)
{
	double	distance;
	double	distance2;
	double	distance3;

	distance = sqrt((result.real - 1) * (result.real - 1) + \
		(result.imag * result.imag));
	distance2 = sqrt((result.real - (-1 / 2)) * (result.real - (-1 / 2)) + \
		(result.imag - (sqrt(3) / 2)) * (result.imag - (sqrt(3) / 2)));
	distance3 = sqrt((result.real - (-1 / 2)) * (result.real - (-1 / 2)) + \
		(result.imag - (-sqrt(3) / 2)) * (result.imag - (-sqrt(3) / 2)));
	if (i == (int)fractol->max_iter)
		return (0);
	if (fractol->color_type == 3)
	{
		if (distance < distance2 && distance < distance3)
			return (rgb_to_hex(1, i, 0, 0.3 * (double)i) * 15);
		else if (distance2 < distance && distance2 < distance3)
			return (rgb_to_hex(1, 0, i, 0.3 * (double)i) * 15);
		else
			return (rgb_to_hex(1, 0.f, 0.3 * (double)i, i) * 15);
	}
	return (-1);
}

int	newton_method(int x, int y, t_fractol *fractol, int i)
{
	double		dst;
	t_complex	result;
	double		tolerance;
	int			color;

	result.real = (x / fractol->zoom + fractol->x_set);
	result.imag = (y / fractol->zoom + fractol->y_set);
	result.real = ((result.real / WIDTH) - 0.5) * 4 * fractol->ratio;
	result.imag = ((result.imag / HEIGHT) - 0.5) * 4;
	dst = sqrt(result.real * result.real + result.imag * result.imag);
	tolerance = 0.00000001;
	while (i == 0 || ((dst < 1 - tolerance || dst > 1 + tolerance) \
		&& i < (int)fractol->max_iter))
	{
		result = substract(result, divide(f(result), f_prime(result)));
		dst = sqrt(result.real * result.real + result.imag * result.imag);
		i++;
	}
	color = calculate_color(result, i, fractol);
	if (color == 0)
		return (0);
	else if (color == -1)
		return (color_smoothing(i, fractol));
	return (color);
}

void	newton(t_fractol *fractol)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(&(fractol->img), x, y, newton_method(x, y, fractol, 0));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, \
		fractol->img.img, 0, 0);
}
