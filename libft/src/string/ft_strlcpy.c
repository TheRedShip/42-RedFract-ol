/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:29:27 by ycontre           #+#    #+#             */
/*   Updated: 2023/11/30 10:52:19 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	int	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (size > 0)
	{
		size--;
		while (size > 0 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
			size--;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}
