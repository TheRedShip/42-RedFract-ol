/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:08:19 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/03 17:49:31 by ycontre          ###   ########.fr       */
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
	}
	else if (button == 5)
	{
		fractol->x_set = (x / fractol->zoom + fractol->x_set) - (x / (fractol->zoom / zoom_num));
		fractol->y_set = (y / fractol->zoom + fractol->y_set) - (y / (fractol->zoom / zoom_num));
		fractol->zoom /= zoom_num;
	}
	else if (button == 3)
		fractol->pan = !fractol->pan;
	print_fractal(fractol);
	return (0);
}

int	key_hook(int key, t_fractol *fractol)
{
	ft_putnbr_fd(key, 1);
	ft_putstr_fd("\n", 1);
	if (key == 65307)
		destroy(fractol);
	if (key == 65436)
	{
		fractol->color_type += 1;
		if (fractol->color_type > 5)
			fractol->color_type = 0;
		print_fractal(fractol);
	}
	else if (key == 32)
		fractol->is_julia_fixed = !fractol->is_julia_fixed;
	return (0);
}