/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:19:58 by smadie            #+#    #+#             */
/*   Updated: 2021/10/31 18:52:21 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static bool	ft_nlsrc(char *str)
{
	while (*str)
		if (*str++ == '\n')
			return (true);
	return (false);
}

static char	*save_buf(char *str, char *buffer)
{
	char	*temp;

	if (str)
	{
		temp = str;
		str = ft_strjoin(str, buffer);
		free(temp);
	}
	else
		str = ft_strdup(buffer);
	return (str);
}

static char	*ft_gtlremainder(char **str)
{
	char	*temp;
	size_t	count;
	char	*line;

	count = 0;
	if (!(*str))
		return (NULL);
	while ((*str)[count] != '\n' && (*str)[count])
		count++;
	if (count < ft_strlen(*str))
	{
		temp = *str;
		line = ft_substr(*str, 0, ++count);
		*str = ft_substr(*str, count, ft_strlen(*str));
		free(temp);
	}
	else
	{
		line = *str;
		*str = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buf;
	int			readed;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	readed = read(fd, buf, BUFFER_SIZE);
	while (readed > 0)
	{
		buf[readed] = '\0';
		str = save_buf(str, buf);
		if (ft_nlsrc(str))
			break ;
		readed = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (ft_gtlremainder(&str));
}
