/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:41:40 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/22 17:34:34 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_dimension_valid(t_xy map_size)
{
	if (map_size.y < 3)
		return (ERROR);
	if (map_size.x < 3)
		return (ERROR);
	if (map_size.y / map_size.x == 1)
		return (ERROR);
	return (NO_ERROR);
}

int	are_map_character_valid(char **map, t_xy map_size)
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
				return (ERROR);
			if (map[i][j] == 'E' || map[i][j] == 'P' )
			{	
				if (++c > 2)
					return (ERROR);
			}
			j++;
		}
		i++;
	}
	return (NO_ERROR);
}

int	are_map_wall_valid(char **map, t_xy map_size)
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
				return (ERROR);
			j++;
		}
		i++;
	}
	return (NO_ERROR);
}

int	is_valid(char **map)
{
	t_xy	map_size;
	char	**map_cpy;

	map_size = get_map_tab_size(map);
	if (!is_map_dimension_valid(map_size))
		return (ERROR);
	if (!are_map_wall_valid(map, map_size))
		return (ERROR);
	if (!are_map_character_valid(map, map_size))
		return (ERROR);
	map_cpy = ft_tabcpy(map);
	if (!is_path_in(map_cpy))
	{
		ft_free_tab(map_cpy);
		return (ERROR);
	}
	printf("c1\n");
	ft_free_tab(map_cpy);
	return (NO_ERROR);
}
