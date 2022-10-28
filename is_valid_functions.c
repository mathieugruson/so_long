/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:50:50 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/28 11:54:07 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_in_map(char c, char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
				return (NO_ERROR);
			x++;
		}
		y++;
	}
	return (ERROR);
}

int	is_map_dimension_valid(t_xy map_size)
{
	if (map_size.y == 0 && map_size.x == -1)
		return (ft_printf("Error\nNo map\n"), ERROR);
	if (map_size.y < 3)
		return (ft_printf("Error\nOrdinate not enough big\n"), ERROR);
	if (map_size.x < 3)
		return (ft_printf("Error\nAbscissa not enough big\n"), ERROR);
	if (map_size.y / map_size.x == 1)
		return (ft_printf("Error\nMap is a square\n"), ERROR);
	if (map_size.y > 29)
		return (ft_printf("Error\nOrdinate too big\n"), ERROR);
	if (map_size.x > 49)
		return (ft_printf("Error\nAbscissa too big\n"), ERROR);
	return (NO_ERROR);
}

int	is_1(char c, char **map)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	x = 0;
	i = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
				i++;
			x++;
		}
		y++;
	}
	if (i != 1)
		return (ERROR);
	return (NO_ERROR);
}

int	are_map_character_valid(char **map, t_xy map_size)
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
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P')
				return (ft_printf("Error\nCheck map characters\n"), ERROR);
			j++;
		}
		i++;
	}
	if (is_1('E', map) == ERROR || is_1('P', map) == ERROR \
	|| is_in_map('C', map) == ERROR)
	{
		return (ft_printf("Error\nNot good character number\n"), ERROR);
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
				return (ft_printf("Error\nWall not valid\n"), ERROR);
			j++;
		}
		i++;
	}
	return (NO_ERROR);
}
