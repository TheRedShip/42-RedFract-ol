/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:40:28 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/06 20:14:37 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

typedef struct {
    double real;
    double imag;
} Complex;

Complex square_c(Complex z) {
    Complex result;
    result.real = z.real * z.real - z.imag * z.imag;
    result.imag = 2 * z.real * z.imag;
    return result;
}

Complex cube_c(Complex z) {
    Complex result;
    double a = z.real;
    double b = z.imag;

    result.real = a * (a * a - 3 * b * b);
    result.imag = b * (3 * a * a - b * b);

    return result;
}

Complex f(Complex z) {
	Complex temp;
	
	temp = cube_c(z);
	temp.real -= 1;
	return (temp);
}

Complex f_prime(Complex z) {
	Complex complex;

	complex.real = 3.0 * z.real * z.real - 3.0 * z.imag * z.imag;
	complex.imag = 6.0 * z.real * z.imag;
	return (complex);
}


Complex substract(Complex a, Complex b)
{
	Complex result;

	result.real = a.real - b.real;
	result.imag = a.imag - b.imag;
	return (result);
}

Complex divide(Complex numerator, Complex denominator)
{
	Complex result;

	result.real = (numerator.real * denominator.real + numerator.imag * denominator.imag) / \
	(denominator.real * denominator.real + denominator.imag * denominator.imag);
	result.imag = (numerator.imag * denominator.real - numerator.real * denominator.imag) / \
	(denominator.real * denominator.real + denominator.imag * denominator.imag);

	return (result);
}

int newton_method(int x, int y, t_fractol *fractol) {

	long double zx = (x / fractol->zoom + fractol->x_set);
	long double zy = (y / fractol->zoom + fractol->y_set);
	zx = ((zx / WIDTH) - 0.5) * 4 * ASPECT_RATIO;
	zy = ((zy / HEIGHT) - 0.5) * 4;
	
	Complex result;
	result.real = zx;
	result.imag = zy;
	Complex origin;
	origin.real = zx;
	origin.imag = zy;
	Complex ftemp;
	Complex fprimetemp;

    int iteration = 0;
    double dst = sqrt(result.real * result.real + result.imag * result.imag);

    double tolerance = 0.001;
    while (dst > tolerance && iteration < fractol->max_iter)
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

	double distanceorigin = 0;
	double distanceorigin2 = 0;
	double distanceorigin3 = 0;
	distanceorigin = sqrt((origin.real - 1)*(origin.real - 1) + (origin.imag*origin.imag)) / 8 - 0.5;
	distanceorigin2 = sqrt((origin.real - (-1/2))*(origin.real - (-1/2)) + (origin.imag - (sqrt(3)/2))*(origin.imag - (sqrt(3)/2))) / 8 - 0.5;
	distanceorigin3 = sqrt((origin.real - (-1/2))*(origin.real - (-1/2)) + (origin.imag - (-sqrt(3)/2))*(origin.imag - (-sqrt(3)/2))) / 8 - 0.5;
	if (distance < distance2 && distance < distance3)
		return hsv_to_hex(0, distanceorigin, 1);
	else if (distance2 < distance && distance2 < distance3)
		return hsv_to_hex(120, distanceorigin2, 1);
	else
		return hsv_to_hex(240, distanceorigin3, 1);
}

void newton(t_fractol *fractol)
{
	int y;
	int x;

	fractol->color_type = 1;
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