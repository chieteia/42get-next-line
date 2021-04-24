/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:10:48 by ntoshihi          #+#    #+#             */
/*   Updated: 2021/04/24 09:00:36 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 42
# define FAILED -1
# define OK 1

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		find_newline(char *s);
int		make_line_and_set_stock(char **line, char **buff, char **stock);
void	safe_free(char **p);
int		make_buff(int fd, ssize_t *read_len, char **buff, char **stock);
int		make_stock(char **buff, char **stock);

#endif
