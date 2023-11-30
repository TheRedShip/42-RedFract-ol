/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mult.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:02:57 by ycontre           #+#    #+#             */
/*   Updated: 2023/11/26 15:10:23 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_is_a_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_usep(char *str, char *sep)
{
	int	i;

	i = 1;
	while (ft_is_a_sep(str[i], sep) == 0 && str[i])
		i++;
	return (i);
}

static int	ft_count_malloc(char *str, char *sep)
{
	int	num_sep;
	int	i;
	int	verification;

	num_sep = 0;
	verification = 1;
	i = 0;
	while (str[i])
	{
		if (verification == 0 && ft_is_a_sep(str[i], sep))
			verification = 1;
		if (verification == 1 && ft_is_a_sep(str[i], sep) == 0)
			verification = 2;
		if (verification == 2 && (ft_is_a_sep(str[i], sep)
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

static void	*ft_free(char **strs, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(strs[i]);
		i++;
	}
	free(strs[i]);
	return (NULL);
}

char	**ft_split_mult(char *str, char *charset)
{
	char	**strs;
	int		num_sep;
	int		i;
	int		j;
	int		k;

	num_sep = ft_count_malloc(str, charset);
	strs = malloc(sizeof(char *) * (num_sep + 1));
	i = 0;
	k = -1;
	while (++k < num_sep)
	{
		j = -1;
		while (ft_is_a_sep(str[i], charset) == 1 && str[i])
			i++;
		strs[k] = malloc(sizeof(char) * (ft_usep(str + i, charset) + 1));
		if (strs[k] == NULL)
			return (ft_free(strs, k));
		while (str[i] && ft_is_a_sep(str[i], charset) == 0 && ++j > -10)
			strs[k][j] = str[i++];
		strs[k][j + 1] = '\0';
		i++;
	}
	strs[k] = 0;
	return (strs);
}
