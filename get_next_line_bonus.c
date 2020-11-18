/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:05:23 by ntoshihi          #+#    #+#             */
/*   Updated: 2020/11/18 15:49:20 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_lstnew(int fd)
{
	t_list *lst_new;

	if (!(lst_new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	lst_new->key = fd;
	lst_new->value = NULL;
	lst_new->next = NULL;
	return (lst_new);
}

t_list	*skip_to_newline(t_list *list, int fd)
{
	t_list *tmp;

}

int		add_keep_to_line(char **line, char *s, ssize_t read_len)
{
	char	*tmp;
	size_t	len;

	len = 0;
	tmp = s;
	if (read_len < 0)
		return (-1);
	if (!*s)
		return (0);
	while (*s != '\n' && *s)
	{
		len++;
		s++;
	}
	free(*line);
	*line = ft_substr(tmp, 0, len);
	return (*s == '\0' ? 0 : 1);
}

int		get_next_line(int fd, char **line)
{
	static	t_list	*queen_ant = ft_lstnew(fd);
	t_list			*ant;
	ssize_t			read_len;
	char			buffer[BUFFER_SIZE + 1];
	char			*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	ant = skip_to_newline(queen_ant);
	*line = ft_strdup("");
	while ((read_len = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_len] = '\0';
		if (!)
			keep = ft_strdup(buffer);
		else
		{
			tmp = keep;
			keep = ft_strjoin(keep, buffer);
			free(tmp);
		}
		if (find_newline(keep))
			break ;
	}
	return (add_keep_to_line(line, keep, read_len));
}