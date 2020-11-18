/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:56:30 by ntoshihi          #+#    #+#             */
/*   Updated: 2020/11/15 17:07:40 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*skip_to_newline(char *s)
{
	char *tmp;

	tmp = s;
	while (*s != '\n' && *s)
		s++;
	if (*s == '\n')
		s++;
	s = ft_strdup(s);
	free(tmp);
	return (s);
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
	static	char	*keep;
	char			buffer[BUFFER_SIZE + 1];
	ssize_t			read_len;
	char			*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (keep)
		keep = skip_to_newline(keep);
	*line = ft_strdup("");
	while ((read_len = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_len] = '\0';
		if (!keep)
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