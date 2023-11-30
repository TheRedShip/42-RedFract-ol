/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:34:05 by ycontre           #+#    #+#             */
/*   Updated: 2023/11/30 10:52:19 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (dst && dst[i] && i < size)
		i++;
	while (src && src[j] && size != 0 && i + j < size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = 0;
	j = ft_strlen(src);
	return (j + i);
}
