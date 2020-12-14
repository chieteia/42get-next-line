/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:56:30 by ntoshihi          #+#    #+#             */
/*   Updated: 2020/12/15 03:32:11 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

t_list	*find_list(int fd, t_list *lists)
{
	while (lists)
	{
		if (lists->fd == fd)
			return (lists);
		lists = lists->next;
	}
	lists = (t_list *)malloc(sizeof(t_list));
	lists->fd = fd;
	lists->text = NULL;
	lists->next = NULL;
	return (lists);
}

int		get_next_line(int fd, char **line)
{
	static	t_list	*lists;
	t_list			*list;
	char			*buff;
	ssize_t			read_len;

	read_len = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	list = find_list(fd, lists);
	while ((read_len > 0) && find_newline(list->text))
	{
		if ((read_len = read(fd, buff, BUFFER_SIZE)) == -1)
			return (all_free(lists, buff));
		buff[read_len] = '\0';
		if ((list->text = ft_strjoin(list->text, buff)) == NULL)
			return (all_free(lists, buff));
	}
	free(buff);
	*line = add_stock_to_line(*line, list->text);
	list->text = skip_to_newline(list->text);
	return (read_len == 0 ? 0 : 1);
}
