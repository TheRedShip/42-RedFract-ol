/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:41:14 by ycontre           #+#    #+#             */
/*   Updated: 2023/11/30 10:52:19 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*string;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	string = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	j = 0;
	i = -1;
	while (s1[++i])
	{
		string[j] = s1[i];
		j++;
	}
	i = 0;
	while (s2[i])
	{
		string[j] = s2[i];
		i++;
		j++;
	}
	string[j] = '\0';
	return (string);
}
