/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:48:59 by ntoshihi          #+#    #+#             */
/*   Updated: 2020/12/26 15:49:01 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_skip_to_newline(char *s)
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

char	*ft_free_and_get_line(char *line, char *s, char *buff)
{
	char	*tmp;
	size_t	len;

	free(buff);
	buff = NULL;
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

t_list	*ft_find_list(t_list *lists, int fd)
{
	while (lists)
	{
		if (lists->fd == fd)
			return (lists);
		lists = lists->next;
	}
	return (NULL);
}

t_list	*ft_make_lists(t_list *lists, int fd)
{
	t_list *new;
	t_list *head;

	if (!lists)
	{
		if (!(new = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		new->fd = fd;
		new->text = NULL;
		new->next = NULL;
		return (new);
	}
	head = lists;
	while (lists->fd != fd && lists->next)
		lists = lists->next;
	if (lists->fd != fd)
	{
		if (!(new = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		new->fd = fd;
		new->text = NULL;
		new->next = NULL;
		lists->next = new;
	}
	return (head);
}

int		get_next_line(int fd, char **line)
{
	static	t_list	*lists;
	t_list			*tmp;
	char			*buff;
	ssize_t			read_len;

	read_len = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0
		|| !(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!(lists = ft_make_lists(lists, fd)))
		return (ft_all_free(lists, buff));
	if (!(tmp = ft_find_list(lists, fd)))
		return (ft_all_free(lists, buff));
	while ((read_len > 0) && ft_find_newline(tmp->text))
	{
		if ((read_len = read(fd, buff, BUFFER_SIZE)) == -1)
			return (ft_all_free(lists, buff));
		buff[read_len] = '\0';
		if ((tmp->text = ft_strjoin(tmp->text, buff)) == NULL)
			return (ft_all_free(lists, buff));
	}
	if ((*line = ft_free_and_get_line(*line, tmp->text, buff)) == NULL
		|| (tmp->text = ft_skip_to_newline(tmp->text)) == NULL)
		return (ft_all_free(lists, buff));
	return (read_len == 0 ? 0 : 1);
}
