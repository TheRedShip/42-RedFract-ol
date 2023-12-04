/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:32:54 by ycontre           #+#    #+#             */
/*   Updated: 2023/11/30 10:52:19 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static char	*after_comma(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	return str + i + 1;
}

int ft_power(int nb, int power)
{
	int result;

	result = 1;
	if (power < 0)
		return (0);
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}
#include <stdio.h>
double	ft_atof(char *str)
{
	double final_result;
	char *decimal;
	int	sign;

	if (!str)
		return (0);
	final_result = (double)ft_atoi(str);
	if (!ft_strchr(str, '.'))
		return (final_result);
	sign = 1;
	if (final_result < 0 || str[0] == '-')
		sign = -1;
	decimal = after_comma(str);
	final_result += sign * ((double)ft_atoi(decimal) / ft_power(10, ft_strlen(decimal)));
	return (final_result);
}
