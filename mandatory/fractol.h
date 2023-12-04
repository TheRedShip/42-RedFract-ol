/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:11:53 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/04 13:59:19 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fractol {
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		type;
	double		zoom;
	double 	x_set;
	double 	y_set;
	double 	complex_x;
	double 	complex_y;
	int 	is_julia_fixed;
	int		pan;
	int		color_type;
	int		smoothing;
}				t_fractol;

# define WIDTH 1280
# define HEIGHT 960

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <math.h>

void	mandelbrot(t_fractol *fractol);
void	julia(t_fractol *fractol);
void	burningship(t_fractol *fractol);

t_data	create_window(void **mlx, void **mlx_win);
void	put_pixel(t_data *data, int x, int y, int color);

void	print_fractal(t_fractol *fractol);

int		mouse_hook(int button, int x, int y, t_fractol *f);
int		key_hook(int key, t_fractol *f);
int		destroy(t_fractol *fractol);

int		rgb_to_hex(int t, int r, int g, int b);
int		hsv_to_hex(double hue, double saturation, double value);
int		color_smoothing(double iteration, t_fractol *fractol);

#endif