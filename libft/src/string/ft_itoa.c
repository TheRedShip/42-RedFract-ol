/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:27:22 by ycontre           #+#    #+#             */
/*   Updated: 2023/11/30 10:52:25 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_count_num(int num)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	while (num >= 1)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static void	ft_rev_char_tab(char *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = temp;
		i++;
	}
}

static char	*fill_int(void)
{
	char	*string;
	int		i;

	string = malloc(sizeof(char) * 12);
	if (string == NULL)
		return (NULL);
	i = 0;
	while ("-2147483648"[i])
	{
		string[i] = "-2147483648"[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	int		sign;
	char	*string;

	sign = (n < 0);
	if (n == -2147483648)
		return (fill_int());
	else if (n < 0)
		n *= -1;
	len = ft_count_num(n);
	string = malloc(sizeof(char) * (len + 1 + sign));
	if (string == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		string[i] = 48 + (n % 10);
		n /= 10;
		i++;
	}
	string[i] = '-';
	ft_rev_char_tab(string, len + sign);
	string[i + sign] = '\0';
	return (string);
}
