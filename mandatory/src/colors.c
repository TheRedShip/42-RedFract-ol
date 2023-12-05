/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:54:25 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/05 15:46:16 by marvin           ###   ########.fr       */
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

int hsv_to_hex(double hue, double saturation, double value)
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

int color_smoothing(double iteration, t_fractol *fractol)
{
	int max = 50;
	
	if (fractol->color_type == 0)
		return c_frost_sand(iteration);
	else if (fractol->color_type == 1)
		return (hsv_to_hex((int)(iteration * 15 + fractol->color_shift_v) % 360, 0.5, 1));
	else if (fractol->color_type == 2)
		return (hsv_to_hex((int)(iteration * 3.6 + 180) % 360, 1, 1));
	else if (fractol->color_type == 3)
		return c_fire(iteration);
	else
		return (hsv_to_hex(iteration / max, 255, 1));
}

Color lerp(Color start, Color end, double t) {
    Color result;
    result.r = start.r + t * (end.r - start.r);
    result.g = start.g + t * (end.g - start.g);
    result.b = start.b + t * (end.b - start.b);
    return result;
}

Color lerp_color_list(Color colors[], int num_colors, double step, int max_steps) {
	double t = (double)step / (double)max_steps;
	double segment = 1.0f / (double)(num_colors - 1);
	int i = step / (max_steps / (num_colors - 1));
	return lerp(colors[i], colors[i + 1], (t - (segment * i)) / segment);
}