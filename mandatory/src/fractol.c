/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:12:57 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/01 19:18:15 by ycontre          ###   ########.fr       */
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
	fractol->img = create_window(&fractol->mlx, &fractol->mlx_win);
}

void	print_fractal(t_fractol *fractol)
{
	if (fractol->type == 1)
		mandelbrot(fractol);
	else if (fractol->type == 2)
		julia(fractol);
	else if (fractol->type == 3)
		burningship(fractol);
}

void	choose_fractol(t_fractol *fractol, char **argv)
{
	fractol->type = 0;
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		fractol->type = 1;
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		fractol->type = 2;
	}
	else if (ft_strcmp(argv[1], "burningship") == 0)
		fractol->type = 3;
	else
		ft_putstr_fd("Usage:\n\t./fractol mandelbrot\n\t./fractol julia <float> <float>\n\t./fractol burningship\n", 1);
	if (fractol->type != 0)
		print_fractal(fractol);
}

int	main(int argc, char **argv)
{
	t_fractol	*fractol;
	
	fractol = ft_calloc(1, sizeof(t_fractol));
	if (!fractol)
		return (-1);
	if (argc == 2 || argc == 4)
	{
		init_fractol(fractol);
		choose_fractol(fractol, argv);
		
		mlx_mouse_hook(fractol->mlx_win, mouse_hook, fractol);
		mlx_key_hook(fractol->mlx_win, key_hook, fractol);
		mlx_hook(fractol->mlx_win, 17, 1L << 2, destroy, fractol);
		mlx_loop(fractol->mlx);
		destroy(fractol);
	}
	else
		ft_putstr_fd("Usage:\n\t./fractol mandelbrot\n\t./fractol julia <float> <float>\n\t./fractol burningship\n", 1);
	free(fractol);
}
