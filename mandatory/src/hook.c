/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:08:19 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/01 19:01:37 by ycontre          ###   ########.fr       */
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
	else if (button == 1)
	{
		double aspect_ratio = (double)WIDTH / (double)HEIGHT;

		fractol->complex_x = ((double)x - WIDTH / 2) * 2 / (WIDTH / 2) * aspect_ratio;
		fractol->complex_y = ((double)y - HEIGHT / 2) * 2 / (HEIGHT / 2);
		// fractol->complex_x = (x - (double)WIDTH / 2) / (fractol->zoom);
		// fractol->complex_y = (y - (double)HEIGHT / 2) / (fractol->zoom);
		printf("x = %lf, y = %lf\n", fractol->complex_x, fractol->complex_y);
	}
	print_fractal(fractol);
	return (0);
}

int	key_hook(int key, t_fractol *f)
{
	ft_putnbr_fd(key, 1);
	ft_putstr_fd("\n", 1);
	if (key == 65307)
		destroy(f);
	print_fractal(f);
	return (0);
}