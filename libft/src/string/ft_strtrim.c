/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:05:51 by ycontre           #+#    #+#             */
/*   Updated: 2023/11/30 10:51:26 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	is_in_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_verif(char **s1, char *set)
{
	if (!(*s1) || !set)
		return (NULL);
	while (is_in_set(**s1, set))
		(*s1)++;
	return (*s1);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		i;
	int		end;
	char	*string;

	if (ft_verif(&s1, set) == NULL)
		return (NULL);
	i = -1;
	end = -1;
	while (s1[++i])
	{
		if (is_in_set(s1[i], set) && end == -1)
			end = i;
		if (is_in_set(s1[i], set) == 0)
			end = -1;
	}
	if (end == -1)
		end = i;
	string = malloc((end + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	i = -1;
	while (++i < end)
		string[i] = s1[i];
	string[i] = '\0';
	return (string);
}
