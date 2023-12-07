/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:54:25 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/07 16:16:16 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	rgb_to_hex(int t, int r, int g, int b)
{
	int	final;

	final = b;
	final += g << 8;
	final += r << 16;
	final += t << 24;
	return (final);
}

t_color	calculate_rgb_component_b(double m, double z, double hue, int M)
{
	t_color	rgb;

	if (hue >= 180 && hue < 240)
	{
		rgb.r = m;
		rgb.g = z + m;
		rgb.b = M;
	}
	else if (hue >= 240 && hue < 300)
	{
		rgb.r = z + m;
		rgb.g = m;
		rgb.b = M;
	}
	else
	{
		rgb.r = M;
		rgb.g = m;
		rgb.b = z + m;
	}
	return (rgb);
}

int	calculate_rgb_component_a(double m, double z, double hue, int m1)
{
	t_color	rgb;

	if (hue >= 0 && hue < 60)
	{
		rgb.r = m1;
		rgb.g = z + m;
		rgb.b = m;
	}
	else if (hue >= 60 && hue < 120)
	{
		rgb.r = z + m;
		rgb.g = m1;
		rgb.b = m;
	}
	else if (hue >= 120 && hue < 180)
	{
		rgb.r = m;
		rgb.g = m1;
		rgb.b = z + m;
	}
	else
		rgb = calculate_rgb_component_b(m, z, hue, m1);
	return (rgb_to_hex(0, rgb.r, rgb.g, rgb.b));
}

int	hsv_to_hex(double hue, double saturation, double value)
{
	int		m1;
	int		m;
	double	z;

	m1 = 255 * value;
	m = m1 * (1 - saturation);
	z = (m1 - m) * (1 - fabs(fmod(hue / 60.0, 2) - 1));
	return (calculate_rgb_component_a(m, z, hue, m1));
}
