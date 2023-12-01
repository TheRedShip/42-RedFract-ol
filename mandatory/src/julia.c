/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:12:41 by ycontre           #+#    #+#             */
/*   Updated: 2023/12/01 19:41:47 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int calculate_julia_px(int x, int y, t_fractol *fractol)
{
	(void) fractol;
	double R = 2;
	double aspect_ratio = (double)WIDTH / (double)HEIGHT;
	
	double zx = (x / fractol->zoom + fractol->x_set);
	double zy = (y / fractol->zoom + fractol->y_set);
	zx = (zx - WIDTH / 2) * R / (WIDTH / 2) * aspect_ratio;
	zy = (zy - HEIGHT / 2) * R / (HEIGHT / 2);

    int iteration = 0;
    int max_iteration = 50;
  
    while (zx * zx + zy * zy < R*R && iteration < max_iteration) 
    {
    	double xtemp = zx * zx - zy * zy;
        zy = 2 * zx * zy + fractol->complex_y;
        zx = xtemp + fractol->complex_x;
    
        iteration++;
    }
  
    if (iteration == max_iteration || iteration == 0)
        return (1);
    else
        return iteration;
}

void julia(t_fractol *fractol)
{
	int y = 0;
	int x = 0;

	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (calculate_julia_px(x, y, fractol) == 1)
				put_pixel(&(fractol->img), x, y, 0x00000000 + 5);
			else
				put_pixel(&(fractol->img), x, y, 0x000000FF + calculate_julia_px(x, y, fractol) * 20); //+ calculate_julia_px(x, y, fractol) * 1000000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img.img, 0, 0);
}
