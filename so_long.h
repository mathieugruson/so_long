/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:27:20 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/16 18:27:38 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H 

# include <string.h>
# include <strings.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <ctype.h>
# include <limits.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>

char	*get_next_line(int fd);
char	*get_work_line(int fd, char *line);
char	*get_print_line(char *src);
char	*stock_end_line(char *work_line, char *print_line);
char	*pull_end_line(char *work_line);

int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_memchr(char *s, int c, size_t n);

# ifndef BUFFER_SIZE
# define BUFFER_SIZE		5
# endif

#endif 