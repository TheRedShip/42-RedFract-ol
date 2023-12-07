/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:36:22 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/07 16:58:25 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_complex	cube_c(t_complex z)
{
	double		a;
	double		b;
	t_complex	result;

	a = z.real;
	b = z.imag;
	result.real = a * (a * a - 3 * b * b);
	result.imag = b * (3 * a * a - b * b);
	return (result);
}

t_complex	f(t_complex z)
{
	t_complex	temp;

	temp = cube_c(z);
	temp.real -= 1;
	return (temp);
}

t_complex	f_prime(t_complex z)
{
	t_complex	t_complex;

	t_complex.real = 3.0 * z.real * z.real - 3.0 * z.imag * z.imag;
	t_complex.imag = 6.0 * z.real * z.imag;
	return (t_complex);
}

t_complex	substract(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = a.real - b.real;
	result.imag = a.imag - b.imag;
	return (result);
}

t_complex	divide(t_complex n, t_complex d)
{
	t_complex	result;

	result.real = (n.real * d.real + n.imag * d.imag) / \
	(d.real * d.real + d.imag * d.imag);
	result.imag = (n.imag * d.real - n.real * d.imag) / \
	(d.real * d.real + d.imag * d.imag);
	return (result);
}
