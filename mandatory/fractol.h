/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:11:53 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/07 17:08:07 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <math.h>

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
	double	complex_x;
	double	complex_y;
	double	zoom;
	double	x_set;
	double	y_set;
	int		pan;
	int		smoothing;
	int		color_type;
	int		color_shift;
	double	ratio;
	int		color_shift_v;
	int		is_julia_fixed;
}				t_fractol;

typedef struct s_color {
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_complex {
	double	real;
	double	imag;
}	t_complex;

# define WIDTH 1000
# define HEIGHT 800

void			mandelbrot(t_fractol *fractol);
void			julia(t_fractol *fractol);
void			burningship(t_fractol *fractol);
void			newton(t_fractol *fractol);

void			print_fractal(t_fractol *fractol);
t_data			create_window(void **mlx, void **mlx_win, t_fractol *fractol);
void			put_pixel(t_data *data, int x, int y, int color);

void			print_fractal(t_fractol *fractol);

int				mouse_hook(int button, int x, int y, t_fractol *f);
int				key_hook(int key, t_fractol *f);
int				destroy(t_fractol *fractol);

int				rgb_to_hex(int t, int r, int g, int b);
int				hsv_to_hex(double hue, double saturation, double value);
int				color_smoothing(double iteration, t_fractol *fractol);
t_color			lerp(t_color start, t_color end, double t);
t_color			lerp_color_list(t_color colors[], int num_colors,
					double step, int max_steps);

int				c_frost_sand(double iteration);
int				c_fire(double iteration);

t_complex		f(t_complex z);
t_complex		f_prime(t_complex z);
t_complex		substract(t_complex a, t_complex b);
t_complex		divide(t_complex n, t_complex d);

int				destroy(t_fractol *fractol);

#endif