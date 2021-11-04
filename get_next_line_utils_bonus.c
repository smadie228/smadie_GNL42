/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 19:41:22 by smadie            #+#    #+#             */
/*   Updated: 2021/10/31 18:50:57 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;

	if (!s || len <= 0 || start >= ft_strlen(s))
		return (NULL);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

char	*ft_strdup(const char *s1)
{
	char	*strdup;
	size_t	i;

	strdup = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (strdup)
	{
		i = 0;
		while (s1[i])
		{
			strdup[i] = s1[i];
			i++;
		}
		strdup[i] = '\0';
	}
	return (strdup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*str;

	if (s1 && s2)
	{
		s1_len = ft_strlen(s1);
		s2_len = ft_strlen(s2);
		str = (char *) malloc(sizeof(char) * (s1_len + s2_len + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[s1_len] = s2[i];
			s1_len++;
		}
		str[s1_len] = '\0';
		return (str);
	}
	return (NULL);
}
