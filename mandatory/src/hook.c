/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:08:19 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/07 16:21:33 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mouse_hook(int button, int x, int y, t_fractol *f)
{
	double	zoom_num;

	zoom_num = 1.2;
	if (button == 4)
	{
		f->x_set = (x / f->zoom + f->x_set) - (x / (f->zoom * zoom_num));
		f->y_set = (y / f->zoom + f->y_set) - (y / (f->zoom * zoom_num));
		f->zoom *= zoom_num;
		if (f->max_iter < 150)
			f->max_iter += 0.5;
	}
	else if (button == 5)
	{
		f->x_set = (x / f->zoom + f->x_set) - (x / (f->zoom / zoom_num));
		f->y_set = (y / f->zoom + f->y_set) - (y / (f->zoom / zoom_num));
		f->zoom /= zoom_num;
		if (f->max_iter > 50)
			f->max_iter -= 0.5;
	}
	else if (button == 3)
		f->pan = !f->pan;
	print_fractal(f);
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

void	graphic_key(int key, t_fractol *fractol)
{
	if (key == 65451)
		fractol->max_iter += 5;
	else if (key == 65453)
		fractol->max_iter -= 5;
	else if (key == 65436)
	{
		fractol->color_type += 1;
		if (fractol->color_type > 4)
			fractol->color_type = 0;
	}
	else if (key == 65433)
		fractol->smoothing = !fractol->smoothing;
	else if (key == 65435)
		fractol->color_shift = !fractol->color_shift;
	else if (key == 32)
		fractol->is_julia_fixed = !fractol->is_julia_fixed;
}

int	key_hook(int key, t_fractol *fractol)
{
	if (key == 65307)
		destroy(fractol);
	graphic_key(key, fractol);
	movement_key(key, fractol);
	print_fractal(fractol);
	return (0);
}
