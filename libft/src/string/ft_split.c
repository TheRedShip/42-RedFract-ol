/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:54:24 by ycontre           #+#    #+#             */
/*   Updated: 2023/11/30 10:52:19 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_usep(char *str, char sep)
{
	int	i;

	i = 1;
	while (str[i] != sep && str[i])
		i++;
	return (i);
}

static int	ft_count_malloc(char *str, char sep)
{
	int	num_sep;
	int	i;
	int	verification;

	num_sep = 0;
	verification = 1;
	i = 0;
	while (str[i])
	{
		if (verification == 0 && str[i] == sep)
			verification = 1;
		if (verification == 1 && str[i] != sep)
			verification = 2;
		if (verification == 2 && (str[i] == sep
				|| str[i + 1] == '\0'))
		{
			verification = 0;
			num_sep++;
		}
		else
			i++;
	}
	return (num_sep);
}

char	**ft_split(char *s, char c)
{
	int		num_sep;
	char	**strs;
	int		tab[3];

	num_sep = ft_count_malloc(s, c);
	strs = malloc((num_sep + 1) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	tab[0] = -1;
	tab[1] = 0;
	while (++tab[0] < num_sep)
	{
		tab[2] = -1;
		while (s[tab[1]] == c && s[tab[1]])
			tab[1]++;
		strs[tab[0]] = malloc(sizeof(char) * (ft_usep(s + tab[1], c) + 1));
		if (strs[tab[0]] == NULL)
			return (NULL);
		while (s[tab[1]] && s[tab[1]] != c && ++tab[2] > -10)
			strs[tab[0]][tab[2]] = s[tab[1]++];
		strs[tab[0]][tab[2] + 1] = '\0';
		tab[1]++;
	}
	strs[tab[0]] = 0;
	return (strs);
}
