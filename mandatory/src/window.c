/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:40:24 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/08 13:15:19 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_data	create_window(void **mlx, void **mlx_win, t_fractol *fractol)
{
	t_data	img;

	*mlx = mlx_init();
	if (!*mlx)
	{
		free(fractol);
		exit(1);
	}
	*mlx_win = mlx_new_window(*mlx, WIDTH, HEIGHT, "Fract'ol");
	if (!*mlx_win)
	{
		mlx_destroy_display(*mlx);
		free(*mlx);
		free(fractol);
		exit(EXIT_FAILURE);
	}
	img.img = mlx_new_image(*mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	return (img);
}

void	print_fractal(t_fractol *fractol)
{
	if (fractol->type == 1)
		mandelbrot(fractol);
	else if (fractol->type == 2)
		julia(fractol);
	else if (fractol->type == 3)
		burningship(fractol);
	else if (fractol->type == 4)
		newton(fractol);
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
