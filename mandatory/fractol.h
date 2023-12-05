/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:11:53 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/05 16:47:35 by marvin           ###   ########.fr       */
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
	double	max_iter;
	double 	complex_x;
	double 	complex_y;
	double	zoom;
	double 	x_set;
	double 	y_set;
	int		pan;
	int		smoothing;
	int		color_type;
	int		color_shift;
	int		color_shift_v;
	int 	is_julia_fixed;
}				t_fractol;

typedef struct {
    int r;
	int	g;
	int	b;
}	Color;

# define WIDTH 1000
# define HEIGHT 1000
# define ASPECT_RATIO 1

# define M_LN2 0.30102999566

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <math.h>

void	mandelbrot(t_fractol *fractol);
void	julia(t_fractol *fractol);
void	burningship(t_fractol *fractol);

void	print_fractal(t_fractol *fractol);
t_data	create_window(void **mlx, void **mlx_win);
void	put_pixel(t_data *data, int x, int y, int color);

void	print_fractal(t_fractol *fractol);

int		mouse_hook(int button, int x, int y, t_fractol *f);
int		key_hook(int key, t_fractol *f);
int		destroy(t_fractol *fractol);

int		rgb_to_hex(int t, int r, int g, int b);
int		hsv_to_hex(double hue, double saturation, double value);
int		color_smoothing(double iteration, t_fractol *fractol);
Color 	lerp(Color start, Color end, double t);
Color	lerp_color_list(Color colors[], int num_colors, double step, int max_steps);

int		c_frost_sand(double iteration);
int		c_fire(double iteration);

#endif