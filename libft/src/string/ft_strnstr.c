/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:26:41 by ycontre           #+#    #+#             */
/*   Updated: 2023/11/30 10:51:31 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little && !little[0])
		return ((char *)(big));
	while (big && big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] != '\0' && i + j < len)
			j++;
		if (!little[j])
			return ((char *)(&big[i]));
		i++;
	}
	return (0);
}
