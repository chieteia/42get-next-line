/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:57:01 by ntoshihi          #+#    #+#             */
/*   Updated: 2020/12/11 23:02:57 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	if (!s)
		return (0);
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*p;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(p = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i])
	{
		if (start <= i && j < len)
		{
			p[j] = s[i];
			j++;
		}
		i++;
	}
	p[j] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	char	*p_top;
	char	*s1_top;

	if (!s1 && !s2)
		return (NULL);
	if (!(p = (char *)malloc(sizeof(char)*(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	p_top = p;
	s1_top = s1;
	while (s1 && *s1)
		*p++ = *s1++;
	while (s2 && *s2)
		*p++ = *s2++;
	*p = '\0';
	free(s1_top);
	return (p_top);
}

int		find_newline(char *s)
{
	if (!s)
		return (1);
	while (*s)
	{
		if (*s == '\n')
			return (0);
		s++;
	}
	return (1);
}

int		all_free(char *stock, char *buff)
{
	free(stock);
	free(buff);
	return (-1);
}