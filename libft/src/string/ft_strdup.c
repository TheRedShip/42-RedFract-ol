/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:01:16 by ycontre           #+#    #+#             */
/*   Updated: 2023/11/30 10:52:19 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strdup(char *s)
{
	char	*new_string;
	int		i;
	int		str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	new_string = malloc(sizeof(char) * (str_len + 1));
	if (new_string == NULL)
		return (NULL);
	i = -1;
	while (++i < str_len)
		new_string[i] = s[i];
	new_string[i] = '\0';
	return (new_string);
}
