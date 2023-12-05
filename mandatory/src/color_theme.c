/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_theme.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:06:27 by marvin            #+#    #+#             */
/*   Updated: 2023/12/05 15:06:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int c_frost_sand(double iteration)
{
	int max;

	max = 50;
	Color colors[6] = {
		{0, 7, 100},
		{32, 107, 203},
		{237, 255, 255},
		{255, 170, 0},
		{0, 2, 0},
		{0, 7, 100}
	};
	while (iteration > max)
		iteration -= max;
	Color color = lerp_color_list(colors, 6, iteration, max);
	return rgb_to_hex(0, color.r, color.g, color.b);
}

int c_fire(double iteration)
{
	int max;

	max = 100;
	Color colors[5] = {
		{20, 0, 0},
		{255, 20, 0},
		{255, 200, 0},
		{255, 20, 0},
		{20, 0, 0}
	};
	while (iteration > max)
		iteration -= max;
	Color color = lerp_color_list(colors, 5, iteration, max);
	return rgb_to_hex(0, color.r, color.g, color.b);
}
