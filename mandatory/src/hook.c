/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:08:19 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/04 17:32:35 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	double zoom_num;
	
	zoom_num = 1.2;
	if (button == 4)
	{
		fractol->x_set = (x / fractol->zoom + fractol->x_set) - (x / (fractol->zoom * zoom_num));
		fractol->y_set = (y / fractol->zoom + fractol->y_set) - (y / (fractol->zoom * zoom_num));
		fractol->zoom *= zoom_num;
		if (fractol->max_iter < 150)
			fractol->max_iter += 0.5;
	}
	else if (button == 5)
	{
		fractol->x_set = (x / fractol->zoom + fractol->x_set) - (x / (fractol->zoom / zoom_num));
		fractol->y_set = (y / fractol->zoom + fractol->y_set) - (y / (fractol->zoom / zoom_num));
		fractol->zoom /= zoom_num;
		if (fractol->max_iter > 50) 
			fractol->max_iter -= 0.5;
	}
	else if (button == 3)
		fractol->pan = !fractol->pan;
	print_fractal(fractol);
	return (0);
}

void	movement_key(int key, t_fractol *fractol)
{
	if (key == 65361)
		fractol->x_set -= 10 / fractol->zoom;
	else if (key == 65362)
		fractol->y_set -= 10 / fractol->zoom;
	else if (key == 65363)
		fractol->x_set += 10 / fractol->zoom;
	else if (key == 65364)
		fractol->y_set += 10 / fractol->zoom;
}

int	key_hook(int key, t_fractol *fractol)
{
	printf("%f\n", fractol->max_iter);
	if (key == 65307)
		destroy(fractol);
	if (key == 65451)
		fractol->max_iter += 5;
	else if (key == 65453)
		fractol->max_iter -= 5;
	else if (key == 65436)
	{
		fractol->color_type += 1;
		if (fractol->color_type > 5)
			fractol->color_type = 0;
	}
	else if (key == 65433)
		fractol->smoothing = !fractol->smoothing;
	else if (key == 65435)
		fractol->color_shift = !fractol->color_shift;
	else if (key == 32)
		fractol->is_julia_fixed = !fractol->is_julia_fixed;
	movement_key(key, fractol);
	print_fractal(fractol);
	return (0);
}
