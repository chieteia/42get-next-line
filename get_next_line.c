/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:10:40 by ntoshihi          #+#    #+#             */
/*   Updated: 2020/12/30 06:15:30 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

void	safe_free(char **p)
{
	if (*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}

char	*skip_to_newline(char *s)
{
	char *tmp;

	tmp = s;
	while (*s != '\n' && *s)
		s++;
	if (*s == '\n')
		s++;
	s = ft_substr(s, 0, ft_strlen(s));
	free(tmp);
	return (s);
}

char	*add_stock_to_line(char *line, char *s)
{
	char	*tmp;
	size_t	len;

	len = 0;
	tmp = s;
	while (*s != '\n' && *s)
	{
		len++;
		s++;
	}
	line = ft_substr(tmp, 0, len);
	return (line);
}

int		get_next_line(int fd, char **line)
{
	static	char	*stock;
	char			*buff;
	ssize_t			read_len;

	read_len = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((read_len > 0) && find_newline(stock))
	{
		if ((read_len = read(fd, buff, BUFFER_SIZE)) == -1)
			return (all_free(&stock, &buff));
		buff[read_len] = '\0';
		if ((stock = ft_strjoin(stock, buff)) == NULL)
			return (all_free(&stock, &buff));
	}
	safe_free(&buff);
	*line = add_stock_to_line(*line, stock);
	stock = skip_to_newline(stock);
	if (read_len == 0)
		safe_free(&stock);
	return (read_len == 0 ? 0 : 1);
}
//readの長さが0　&& 改行なし
