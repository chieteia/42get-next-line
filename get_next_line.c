/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:10:40 by ntoshihi          #+#    #+#             */
/*   Updated: 2021/04/24 09:39:55 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

int	make_line_and_set_stock(char **line, char **buff, char **stock)
{
	char	*tmp;
	size_t	len;

	len = 0;
	tmp = *stock;
	while (*tmp != '\n' && *tmp)
	{
		len++;
		tmp++;
	}
	*line = ft_substr(*stock, 0, len);
	if (*tmp == '\n')
		tmp++;
	tmp = ft_substr(tmp, 0, ft_strlen(tmp));
	safe_free(stock);
	*stock = tmp;
	if (!line || !stock)
	{
		safe_free(buff);
		safe_free(stock);
		return (FAILED);
	}
	return (OK);
}

int	make_buff(int fd, ssize_t *read_len, char **buff, char **stock)
{
	*read_len = read(fd, *buff, BUFFER_SIZE);
	if (*read_len == -1)
	{
		safe_free(buff);
		safe_free(stock);
		return (FAILED);
	}
	*buff[(*read_len)] = '\0';
	return (OK);
}

int	make_stock(char **buff, char **stock)
{
	*stock = ft_strjoin(*stock, *buff);
	if (*stock == NULL)
	{
		safe_free(buff);
		safe_free(stock);
		return (FAILED);
	}
	return (OK);
}

int	get_next_line(int fd, char **line)
{
	static char	*stock;
	char		*buff;
	ssize_t		read_len;

	read_len = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	while ((read_len > 0) && find_newline(stock))
	{
		if (make_buff(fd, &read_len, &buff, &stock) == FAILED)
			return (-1);
		if (make_stock(&buff, &stock) == FAILED)
			return (-1);
	}
	if (make_line_and_set_stock(line, &buff, &stock) == FAILED)
		return (-1);
	if (read_len == 0)
		safe_free(&stock);
	safe_free(&buff);
	return (!!read_len);
}

/*
char	*skip_to_newline(char *s)
{
	char	*tmp;

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

int make_line_and_set_stock(char **line, char **stock)
{
	char	*tmp;
	size_t	len;

	len = 0;
	tmp = *stock;
	while (*tmp != '\n' && *tmp)
	{
		len++;
		tmp++;
	}
	line = ft_substr(*stock, 0, len);
	if (*tmp == '\n')
		tmp++;
	tmp = ft_substr(tmp, 0, ft_strlen(tmp));
	safe_free(stock);
	*stock = tmp;
	if (!line || !stock)
	{
		safe_free(buff);
		safe_free(stock);
		return (FAILED);
	}
	return (OK);
}

*/