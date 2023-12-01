/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:08:19 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/01 20:08:23 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	if (button == 4)
	{
		fractol->x_set = (x / fractol->zoom + fractol->x_set) - (x / (fractol->zoom * 1.5));
		fractol->y_set = (y / fractol->zoom + fractol->y_set) - (y / (fractol->zoom * 1.5));
		fractol->zoom *= 1.5;
	}
	else if (button == 5)
	{
		fractol->x_set = (x / fractol->zoom + fractol->x_set) - (x / (fractol->zoom / 1.5));
		fractol->y_set = (y / fractol->zoom + fractol->y_set) - (y / (fractol->zoom / 1.5));
		fractol->zoom /= 1.5;
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
	else if (key == 32)
		fractol->is_julia_fixed = !fractol->is_julia_fixed;
	return (0);
}