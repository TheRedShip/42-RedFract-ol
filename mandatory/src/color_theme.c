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

int	c_frost_sand(double iteration)
{
	t_color	colors[6];
	t_color	color;

	colors[0].r = 0;
	colors[0].g = 7;
	colors[0].b = 100;
	colors[1].r = 32;
	colors[1].g = 107;
	colors[1].b = 203;
	colors[2].r = 237;
	colors[2].g = 255;
	colors[2].b = 255;
	colors[3].r = 255;
	colors[3].g = 170;
	colors[3].b = 0;
	colors[4].r = 0;
	colors[4].g = 2;
	colors[4].b = 0;
	colors[5].r = 0;
	colors[5].g = 7;
	colors[5].b = 100;
	while (iteration > 50)
		iteration -= 50;
	color = lerp_color_list(colors, 6, iteration, 50);
	return (rgb_to_hex(0, color.r, color.g, color.b));
}

int	c_fire(double iteration)
{
	t_color	colors[5];
	t_color	color;

	colors[0].r = 20;
	colors[0].g = 0;
	colors[0].b = 0;
	colors[1].r = 255;
	colors[1].g = 20;
	colors[1].b = 0;
	colors[2].r = 255;
	colors[2].g = 200;
	colors[2].b = 0;
	colors[3].r = 255;
	colors[3].g = 20;
	colors[3].b = 0;
	colors[4].r = 20;
	colors[4].g = 0;
	colors[4].b = 0;
	while (iteration > 100)
		iteration -= 100;
	color = lerp_color_list(colors, 5, iteration, 100);
	return (rgb_to_hex(0, color.r, color.g, color.b));
}
