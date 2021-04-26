/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:48:54 by ntoshihi          #+#    #+#             */
/*   Updated: 2021/04/26 18:20:25 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 42

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
int				ft_skip_to_newline(t_list **head, t_list **tmp);
char			*ft_free_and_get_line(char *line, char *s, char **buff);
int				ft_all_free(t_list *lists, char **buff);
t_list			*ft_make_lists(t_list **lists, int fd);
void			ft_rm_node(t_list **head, t_list *tmp);

#endif
