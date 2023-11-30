/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:33:20 by ycontre           #+#    #+#             */
/*   Updated: 2023/11/30 10:55:32 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *res, char *buf, int ret)
{
	char	*tmp;

	buf[ret] = '\0';
	tmp = ft_strjoin_gnl(res, buf);
	free(res);
	return (tmp);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = f_calloc(sizeof(char), (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = buffer[i];
	i++;
	line[i] = '\0';
	return (line);
}

char	*ft_next(char *buffer)
{
	char	*buf;
	int		start;
	int		i;

	start = 0;
	while (buffer[start] && buffer[start] != '\n')
		start++;
	if (!buffer[start++])
	{
		free(buffer);
		return (NULL);
	}
	buf = f_calloc(sizeof(char), (ft_strlen(buffer) - start + 1));
	if (!buf)
		return (NULL);
	i = 0;
	while (buffer[start])
	{
		buf[i] = buffer[start];
		start++;
		i++;
	}
	buf[i] = '\0';
	free(buffer);
	return (buf);
}

char	*ft_readfile(int fd, char *res, int ret)
{
	char	*buf;

	if (!res)
		res = f_calloc(1, sizeof(char));
	if (!res)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(res);
			free(buf);
			return (NULL);
		}
		res = ft_free(res, buf, ret);
		if (ft_strchr_index(buf, '\n') != -1)
			break ;
	}
	free(buf);
	return (res);
}

char	*get_next_line(int fd)
{
	static	char	*(buffer[1024]);
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_readfile(fd, buffer[fd], 1);
	if (!buffer[fd])
		return (NULL);
	line = ft_line(buffer[fd]);
	buffer[fd] = ft_next(buffer[fd]);
	if (buffer[fd] == NULL && line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
