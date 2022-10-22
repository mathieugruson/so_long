/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_path_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:47:09 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/22 18:17:22 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_growing(char c, char **map, char goal)
{
	int	y;
	int	x;

	x = 1;
	y = 1;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
			{
				if (map[y - 1][x] == '0' || map[y + 1][x] == '0'
					|| map[y][x - 1] == '0' || map[y][x + 1] == '0')
					return (NO_ERROR);
				if (map[y - 1][x] == goal || map[y + 1][x] == goal
					|| map[y][x - 1] == goal || map[y][x + 1] == goal)
					return (NO_ERROR);
			}
			x++;
		}
		y++;
	}
	return (ERROR);
}

void	transform_zero_to(char c, char **map, int y, int x)
{
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C')
		map[y - 1][x] = c;
	if (map[y + 1][x] == '0' || map[y - 1][x] == 'C')
		map[y + 1][x] = c;
	if (map[y][x - 1] == '0' || map[y - 1][x] == 'C')
		map[y][x - 1] = c;
	if (map[y][x + 1] == '0' || map[y - 1][x] == 'C')
		map[y][x + 1] = c;
}

int	is_path_to(char c, char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y] && can_growing('P', map, c))
	{
		x = 0;
		while (map[y][x] && can_growing('P', map, c))
		{
			if (map[y][x] == 'P')
			{
				if (map[y - 1][x] == c || map[y + 1][x] == c
					|| map[y][x - 1] == c || map[y][x + 1] == c)
					return (NO_ERROR);
				transform_zero_to('P', map, y, x);
			}
			x++;
		}
		y++;
		if (map[y] == NULL)
			y = 0;
	}
	return ;
}

int	are_accessible(char c, char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y] && can_growing('P', map, c))
	{
		x = 0;
		while (map[y][x] && can_growing('P', map, c))
		{
			if (map[y][x] == 'P')
			{
				transform_zero_to('P', map, y, x);
			}
			x++;
		}
		y++;
		if (map[y] == NULL)
			y = 0;
	}
	if (is_still(('C'), map))
		return (ERROR);
	return (NO_ERROR);
}

int	is_still(char c, char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if (map[y][x] == c)
				return (NO_ERROR);
			x++;
		}
		y++;
	}
	return (ERROR);
}

int	is_path_in(char **map)
{
	if (!are_accessible('C', map))
		return (ERROR);
	if (!is_path_to('E', map))
		return (ERROR);
	return (NO_ERROR);
}
