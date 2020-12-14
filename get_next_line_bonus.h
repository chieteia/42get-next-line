/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:56:58 by ntoshihi          #+#    #+#             */
/*   Updated: 2020/12/15 03:32:29 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	char			*text;
	int				fd;
	struct s_list	*next;
}				t_list;

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		find_newline(char *s);
char	*skip_to_newline(char *s);
char	*add_stock_to_line(char *line, char *s);
int		all_free(t_list *lists, char *buff);
t_list	*find_list(int fd, t_list *lists);

#endif
