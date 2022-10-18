/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:41:40 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/18 16:20:47 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_dimension_error(t_info map_size)
{
	if (map_size.y < 3)
		return (1);
	if (map_size.x < 3)
		return (1);
	if (map_size.y / map_size.x == 1)
		return (1);
	return (0);
}

int	map_character_error(char **map, t_info map_size)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (map[i])
	{
		j = 0;
		while (j <= map_size.x - 1)
		{	
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P')
				return (1);
			if (map[i][j] == 'E' || map[i][j] == 'P' )
			{	
				if (++c > 2)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	map_wall_error(char **map, t_info map_size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (j <= map_size.x - 1)
		{	
			if (map[0][j] != '1' || map[map_size.y - 1][j] != '1'
				|| map[i][0] != '1' || map[i][map_size.x - 1] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	map_error(char **map)
{
	t_info	map_size;
	char	**map_cpy;

	map_size = get_map_tab_size(map);
	if (map_dimension_error(map_size))
		return (1);
	if (map_wall_error(map, map_size))
		return (1);
	if (map_character_error(map, map_size))
		return (1);
	map_cpy = ft_tabcpy(map);
	if (!find_path_to('E', map_cpy))
	{
		ft_free_tab(map_cpy);
		return (1);
	}
	ft_free_tab(map_cpy);
	return (0);
}
