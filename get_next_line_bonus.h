/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:48:54 by ntoshihi          #+#    #+#             */
/*   Updated: 2020/12/26 15:53:38 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_list
{
	char			*text;
	int				fd;
	struct s_list	*next;
}				t_list;

int				get_next_line(int fd, char **line);
size_t			ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
int				ft_find_newline(char *s);
char			*ft_skip_to_newline(char *s);
char			*ft_free_and_get_line(char *line, char *s, char *buff);
int				ft_all_free(t_list *lists, char *buff);
t_list			*ft_make_lists(t_list *lists, int fd);
t_list			*ft_find_list(t_list *lists, int fd);

#endif
