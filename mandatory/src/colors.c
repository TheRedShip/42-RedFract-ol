/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:16:26 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/07 16:19:53 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	color_smoothing(double iteration, t_fractol *fractol)
{
	int	max;

	max = 50;
	if (fractol->color_type == 0)
		return (c_frost_sand(iteration));
	else if (fractol->color_type == 1)
		return (hsv_to_hex((int)(iteration * 15 + \
				fractol->color_shift_v) % 360, 0.5, 1));
	else if (fractol->color_type == 2)
		return (hsv_to_hex((int)(iteration * 3.6 + 180) % 360, 1, 1));
	else if (fractol->color_type == 3)
		return (c_fire(iteration));
	else
		return (hsv_to_hex(iteration / max, 255, 1));
}

t_color	lerp(t_color start, t_color end, double t)
{
	t_color	result;

	result.r = start.r + t * (end.r - start.r);
	result.g = start.g + t * (end.g - start.g);
	result.b = start.b + t * (end.b - start.b);
	return (result);
}

t_color	lerp_color_list(t_color colors[], int ncol, double step, int max_steps)
{
	int		i;
	double	t;
	double	segment;

	t = (double)step / (double)max_steps;
	segment = 1.0 / (double)(ncol - 1);
	i = step / (max_steps / (ncol - 1));
	return (lerp(colors[i], colors[i + 1], (t - (segment * i)) / segment));
}
