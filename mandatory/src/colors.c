/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:54:25 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/03 17:59:29 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"


int	rgb_to_hex(int t, int r, int g, int b)
{
	int final;

	final = b;
	final += g << 8;
	final += r << 16;
	final += t << 24;
	return (final);
}

int hsv_to_hex(int hue, int saturation, double value)
{
	int M;
	int m;
	
	M = 255 * value;
	m = M * (1 - saturation);
	double z = (M - m) * (1 - fabs(fmod(hue / 60.0, 2) - 1));
	int r, g, b;
	if (hue >= 0 && hue < 60) {
		r = M;
		g = z + m;
		b = m;
	} else if (hue >= 60 && hue < 120) {
		r = z + m;
		g = M;
		b = m;
	} else if (hue >= 120 && hue < 180) {
		r = m;
		g = M;
		b = z + m;
	} else if (hue >= 180 && hue < 240) {
		r = m;
		g = z + m;
		b = M;
	} else if (hue >= 240 && hue < 300) {
		r = z + m;
		g = m;
		b = M;
	} else {
		r = M;
		g = m;
		b = z + m;
	}
	return rgb_to_hex(0, r, g, b);
}

int color_smoothing(int iteration, t_fractol *fractol)
{
	int max = 50;
	long double test = (long double)iteration/(long double)max;
	int color = iteration * 360 / 100;
	color += 180;// + (log(fractol->zoom) * 40);
	color %= 360;
	if (fractol->color_type == 0)
		return rgb_to_hex(0, 0, 0, 255 * test);
	else if (fractol->color_type == 1)
		return (hsv_to_hex(iteration, 255, 1));
	else if (fractol->color_type == 2)
		return rgb_to_hex(0, 230 * test, 0, 30 * test);
	else if (fractol->color_type == 3)
		return rgb_to_hex(0, 230 * test, 0, 175 * test);
	else if (fractol->color_type == 4)
		return (hsv_to_hex(255 * (double)iteration / (double)(200), 1, 1));
	else
		return (hsv_to_hex(color, 1, 1));
}