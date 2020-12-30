/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:48:59 by ntoshihi          #+#    #+#             */
/*   Updated: 2020/12/30 08:47:21 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_rm_node(t_list **head, t_list *tmp)
{
	t_list *start;
	t_list *alt;

	start = (*head);
	if ((*head)->fd == tmp->fd)
	{
		(*head) = (*head)->next;
		free(start->text);
		start->text = NULL;
		free(start);
		return ;
	}
	while ((*head)->next->fd != tmp->fd)
		(*head) = (*head)->next;
	alt = (*head)->next;
	(*head)->next = (*head)->next->next;
	free(alt->text);
	alt->text = NULL;
	free(alt);
	(*head) = start;
}

int		ft_skip_to_newline(t_list **head, t_list **tmp)
{
	char *alt;
	char *s;

	alt = (*tmp)->text;
	s = (*tmp)->text;
	while (*s != '\n' && *s)
		s++;
	if (*s)
	{
		s++;
		if (!((*tmp)->text = ft_substr(s, 0, ft_strlen(s))))
			return (-1);
		free(alt);
		alt = NULL;
	}
	else
		ft_rm_node(head, *tmp);
	return (1);
}

char	*ft_free_and_get_line(char *line, char *s, char **buff)
{
	char	*tmp;
	size_t	len;

	free(*buff);
	*buff = NULL;
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

t_list	*ft_make_lists(t_list **lists, int fd)
{
	t_list *head;
	t_list *res;

	if (!(*lists))
	{
		if (!((*lists) = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		(**lists) = (t_list){.text = NULL, .fd = fd, .next = NULL};
	}
	head = (*lists);
	while ((*lists)->fd != fd && (*lists)->next)
		(*lists) = (*lists)->next;
	if ((*lists)->fd != fd)
	{
		if (!(res = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		*res = (t_list){.text = NULL, .fd = fd, .next = NULL};
		(*lists)->next = res;
		(*lists) = head;
		return (res);
	}
	return ((*lists));
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
	if (!(tmp = ft_make_lists(&lists, fd)))
		return (ft_all_free(lists, &buff));
	while ((read_len > 0) && ft_find_newline(tmp->text))
	{
		if ((read_len = read(fd, buff, BUFFER_SIZE)) == -1)
			return (ft_all_free(lists, &buff));
		buff[read_len] = '\0';
		if ((tmp->text = ft_strjoin(tmp->text, buff)) == NULL)
			return (ft_all_free(lists, &buff));
	}
	if ((*line = ft_free_and_get_line(*line, tmp->text, &buff)) == NULL
		|| (ft_skip_to_newline(&lists, &tmp) == -1))
		return (ft_all_free(lists, &buff));
	return (read_len == 0 ? 0 : 1);
}
