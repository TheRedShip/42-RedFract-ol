/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:12:57 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/07 17:09:02 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	destroy(t_fractol *fractol)
{
	mlx_clear_window(fractol->mlx, fractol->mlx_win);
	mlx_destroy_image(fractol->mlx, fractol->img.img);
	mlx_destroy_window(fractol->mlx, fractol->mlx_win);
	mlx_destroy_display(fractol->mlx);
	mlx_loop_end(fractol->mlx);
	free(fractol->mlx);
	free(fractol);
	exit(EXIT_SUCCESS);
	return (0);
}

void	init_fractol(t_fractol *fractol)
{
	fractol->zoom = 1;
	fractol->x_set = 0;
	fractol->y_set = 0;
	fractol->complex_x = 0;
	fractol->complex_y = 0;
	fractol->type = 0;
	fractol->is_julia_fixed = 0;
	fractol->pan = 0;
	fractol->color_type = 0;
	fractol->smoothing = 0;
	fractol->max_iter = 50;
	fractol->color_shift = 0;
	fractol->color_shift_v = 150;
	fractol->ratio = (double)WIDTH / (double)HEIGHT;
	fractol->img = create_window(&fractol->mlx, &fractol->mlx_win, fractol);
}

int	choose_fractol(t_fractol *fractol, char **argv, int argc)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		fractol->x_set -= 300;
		fractol->type = 1;
	}
	else if (ft_strcmp(argv[1], "julia") == 0 && argc == 4)
	{
		fractol->type = 2;
		fractol->complex_x = ft_atof(argv[2]);
		fractol->complex_y = ft_atof(argv[3]);
	}
	else if (ft_strcmp(argv[1], "burningship") == 0)
	{
		fractol->type = 3;
		fractol->color_type = 3;
	}
	else if (ft_strcmp(argv[1], "newton") == 0)
	{
		fractol->color_type = 3;
		fractol->type = 4;
	}
	else
		return (-1);
	print_fractal(fractol);
	return (1);
}

int	loop_hook(t_fractol *f)
{
	int	x;
	int	y;

	if (f->is_julia_fixed)
	{
		mlx_mouse_get_pos(f->mlx, f->mlx_win, &x, &y);
		f->complex_x = ((double)x - WIDTH / 2) * 2 / (WIDTH / 2) * f->ratio;
		f->complex_y = ((double)y - HEIGHT / 2) * 2 / (HEIGHT / 2);
		print_fractal(f);
	}
	else if (f->pan)
	{
		mlx_mouse_get_pos(f->mlx, f->mlx_win, &x, &y);
		f->x_set += (((x - WIDTH / 4) / f->zoom) - (x / (f->zoom * 1.5)));
		f->y_set += (((y - HEIGHT / 4) / f->zoom) - (y / (f->zoom * 1.5)));
		print_fractal(f);
	}
	else if (f->color_shift)
	{
		f->color_shift_v += 3;
		if (f->color_shift_v > 360)
			f->color_shift_v = 0;
		print_fractal(f);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (argc == 2 || argc == 4)
	{
		fractol = ft_calloc(1, sizeof(t_fractol));
		if (!fractol)
			return (-1);
		init_fractol(fractol);
		if (choose_fractol(fractol, argv, argc) == -1)
		{
			ft_putstr_fd("Usage:\n\t./fractol mandelbrot\n\t./fractol julia \
		<float> <float>\n\t./fractol burningship\n\t./fractol newton\n", 1);
			destroy(fractol);
		}
		mlx_mouse_hook(fractol->mlx_win, mouse_hook, fractol);
		mlx_key_hook(fractol->mlx_win, key_hook, fractol);
		mlx_hook(fractol->mlx_win, 17, 1L << 2, destroy, fractol);
		mlx_loop_hook(fractol->mlx, loop_hook, fractol);
		mlx_loop(fractol->mlx);
		destroy(fractol);
	}
	else
		ft_putstr_fd("Usage:\n\t./fractol mandelbrot\n\t./fractol julia \
		<float> <float>\n\t./fractol burningship\n\t./fractol newton\n", 1);
	return (0);
}
