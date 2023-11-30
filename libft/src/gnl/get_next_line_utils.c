/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:56:42 by ycontre           #+#    #+#             */
/*   Updated: 2023/11/30 10:55:37 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr_index(char *s, int c)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return (i);
	return (-1);
}

void	*f_calloc(int size, int nb)
{
	void	*ptr;
	int		i;

	i = 0;
	ptr = malloc(size * nb);
	if (!ptr)
		return (NULL);
	while (i < size * nb)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*string;
	int		i;
	int		j;

	string = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	j = 0;
	i = -1;
	while (s1 && s1[++i])
	{
		string[j] = s1[i];
		j++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		string[j] = s2[i];
		i++;
		j++;
	}
	string[j] = '\0';
	return (string);
}
