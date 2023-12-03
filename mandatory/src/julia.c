/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:12:41 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/03 14:07:08 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double calculate_julia_px(int x, int y, t_fractol *fractol)
{
	long double aspect_ratio = (long double)WIDTH / (long double)HEIGHT;
	
	long double zx = (x / fractol->zoom + fractol->x_set);
	long double zy = (y / fractol->zoom + fractol->y_set);
	zx = (zx - WIDTH / 2) * 2 / (WIDTH / 2) * aspect_ratio;
	zy = (zy - HEIGHT / 2) * 2 / (HEIGHT / 2);

    int iteration = 0;
    int max_iteration = 200;

    while (zx * zx + zy * zy < 4 && iteration < max_iteration) 
    {
    	long double xtemp = zx * zx - zy * zy;
        zy = 2 * zx * zy + fractol->complex_y;
        zx = xtemp + fractol->complex_x;
    
        iteration++;
    }
  
    if (iteration == max_iteration || iteration == 0)
        return (0);
    else
		return (iteration);
}

int	rgb_to_hex(int t, int r, int g, int b)
{
	int final;

	final = b;
	final += g << 8;
	final += r << 16;
	final += t << 24;
	return (final);
}

int hsv_to_hex(int hue, int saturation, double value)
{
	int M;
	int m;
	
	M = 255 * value;
	m = M * (1 - saturation);
	double z = (M - m) * (1 - fabs(fmod(hue / 60.0, 2) - 1));

	int r, g, b;
	if (hue >= 0 && hue < 60) {
		r = M;
		g = z + m;
		b = m;
	} else if (hue >= 60 && hue < 120) {
		r = z + m;
		g = M;
		b = m;
	} else if (hue >= 120 && hue < 180) {
		r = m;
		g = M;
		b = z + m;
	} else if (hue >= 180 && hue < 240) {
		r = m;
		g = z + m;
		b = M;
	} else if (hue >= 240 && hue < 300) {
		r = z + m;
		g = m;
		b = M;
	} else {
		r = M;
		g = m;
		b = z + m;
	}

	return rgb_to_hex(0, r, g, b);
}

int color_smoothing(int iteration, t_fractol *fractol)
{
	int max = 50;
	long double test = (long double)iteration/(long double)max;
	if (fractol->color_type == 0)
		return rgb_to_hex(0, 0, 0, 255 * test);
		
	else if (fractol->color_type == 1)
		return (hsv_to_hex(iteration, 255, 1));
	else if (fractol->color_type == 2)
		return rgb_to_hex(0, 230 * test, 0, 30 * test);
	else if (fractol->color_type == 3)
		return rgb_to_hex(0, 230 * test, 0, 175 * test);
	else
		return (hsv_to_hex(255 * test, 1, 1));

}


void julia(t_fractol *fractol)
{
	int y;
	int x;
	int	iteration;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			iteration = calculate_julia_px(x, y, fractol);
			if (iteration == 0)
				put_pixel(&(fractol->img), x, y, rgb_to_hex(0, 0, 0, 0));
			else
				put_pixel(&(fractol->img), x, y, color_smoothing(iteration, fractol)); // 0x000000FF + iteration * 20
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img.img, 0, 0);
}
