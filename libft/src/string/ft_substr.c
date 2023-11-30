/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:19:18 by ycontre           #+#    #+#             */
/*   Updated: 2023/11/30 10:51:24 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s) + 1)
		return ((char *)ft_calloc(1, 1));
	if (ft_strlen(s) + 1 - start < len)
		len = ft_strlen(s) - start;
	substr = (char *)ft_calloc(len + 1, 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
