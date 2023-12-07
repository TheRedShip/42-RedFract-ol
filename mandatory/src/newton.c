/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:40:28 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/07 14:44:07 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_complex square_c(t_complex z) {
    t_complex result;
    result.real = z.real * z.real - z.imag * z.imag;
    result.imag = 2 * z.real * z.imag;
    return result;
}

t_complex cube_c(t_complex z) {
    t_complex result;
    double a = z.real;
    double b = z.imag;

    result.real = a * (a * a - 3 * b * b);
    result.imag = b * (3 * a * a - b * b);

    return result;
}

t_complex f(t_complex z) {
	t_complex temp;
	
	temp = cube_c(z);
	temp.real -= 1;
	return (temp);
}

t_complex f_prime(t_complex z) {
	t_complex t_complex;

	t_complex.real = 3.0 * z.real * z.real - 3.0 * z.imag * z.imag;
	t_complex.imag = 6.0 * z.real * z.imag;
	return (t_complex);
}

t_complex substract(t_complex a, t_complex b)
{
	t_complex result;

	result.real = a.real - b.real;
	result.imag = a.imag - b.imag;
	return (result);
}

t_complex divide(t_complex numerator, t_complex denominator)
{
	t_complex result;

	result.real = (numerator.real * denominator.real + numerator.imag * denominator.imag) / \
	(denominator.real * denominator.real + denominator.imag * denominator.imag);
	result.imag = (numerator.imag * denominator.real - numerator.real * denominator.imag) / \
	(denominator.real * denominator.real + denominator.imag * denominator.imag);

	return (result);
}

int	newton_method(int x, int y, t_fractol *fractol) {

	long double zx = (x / fractol->zoom + fractol->x_set);
	long double zy = (y / fractol->zoom + fractol->y_set);
	zx = ((zx / WIDTH) - 0.5) * 4 * ASPECT_RATIO;
	zy = ((zy / HEIGHT) - 0.5) * 4;
	
	// zx = 0;
	// zy = 1;
	t_complex result;
	result.real = zx;
	result.imag = zy;
	t_complex ftemp;
	t_complex fprimetemp;

    int iteration = 0;
    double dst = sqrt(result.real * result.real + result.imag * result.imag);

    double tolerance = 0.00000001;
    while (iteration == 0 || ((dst < 1-tolerance|| dst > 1+tolerance) && iteration < (int)fractol->max_iter))
	{
		ftemp = f(result);
		fprimetemp = f_prime(result);
		result = substract(result, divide(ftemp, fprimetemp));
		dst = sqrt(result.real * result.real + result.imag * result.imag);
		iteration++;
    }
	
	double distance = 0;
	double distance2 = 0;
	double distance3 = 0;
	distance = sqrt((result.real - 1)*(result.real - 1) + (result.imag*result.imag));
	distance2 = sqrt((result.real - (-1/2))*(result.real - (-1/2)) + (result.imag - (sqrt(3)/2))*(result.imag - (sqrt(3)/2)));
	distance3 = sqrt((result.real - (-1/2))*(result.real - (-1/2)) + (result.imag - (-sqrt(3)/2))*(result.imag - (-sqrt(3)/2)));

	if (iteration == (int)fractol->max_iter)
		return (0);
	if (fractol->color_type == 3)
	{
		if (distance < distance2 && distance < distance3)
			return rgb_to_hex(1, iteration, 0, 0.3 * (double)iteration) * 15;
		else if (distance2 < distance && distance2 < distance3)
			return rgb_to_hex(1, 0, iteration, 0.3 * (double)iteration) * 15;
		else
			return rgb_to_hex(1, 0.f, 0.3 * (double)iteration, iteration) * 15;
	}
	return color_smoothing(iteration, fractol);
}

void newton(t_fractol *fractol)
{
	int y;
	int x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(&(fractol->img), x, y, newton_method(x, y, fractol));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img.img, 0, 0);
}