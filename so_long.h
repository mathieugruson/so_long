/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:27:20 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/17 17:45:26 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H 

# include "libft/libft_cursus/libft.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct struct_info 
{
	int			x;
	int			y;
}					s_info;

/* map_info.c */

s_info get_map_fd_size(char *map_name);
s_info get_map_tab_size(char **map);


/* map_error.c */

int	map_error(char **map);

/* main.c */

char **get_map(char **map, char *map_name, int fd);

#endif 