/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:27:20 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/18 16:10:48 by mgruson          ###   ########.fr       */
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
}					t_info;

/* get_map.c */

char	**get_map(char *map_name);

/* get_map_size.c */

t_info	get_map_fd_size(char *map_name);
t_info	get_map_tab_size(char **map);

/* map_error.c */

int		map_error(char **map);
int		map_character_error(char **map, t_info map_size);
int		map_dimension_error(t_info map_size);
int		map_wall_error(char **map, t_info map_size);

/* path_error.c */

void	transform_zero(char **map_cpy, int y, int x);
int		p_growth(char **map_cpy);
int		find_path_to(char c, char **map_cpy);

#endif 