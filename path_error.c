/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:47:09 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/18 15:47:01 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	transform_zero(char **map_cpy, int y, int x)
{
	if (map_cpy[y - 1][x] == '0')
		map_cpy[y - 1][x] = 'P';
	if (map_cpy[y + 1][x] == '0')
		map_cpy[y + 1][x] = 'P';
	if (map_cpy[y][x - 1] == '0')
		map_cpy[y][x - 1] = 'P';
	if (map_cpy[y][x + 1] == '0')
		map_cpy[y][x + 1] = 'P';
}

int	p_growth(char **map_cpy)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (map_cpy[y])
	{
		x = 0;
		while (map_cpy[y][x])
		{
			if (map_cpy[y][x] == 'P')
			{
				if (map_cpy[y - 1][x] == '0' || map_cpy[y + 1][x] == '0'
					|| map_cpy[y][x - 1] == '0' || map_cpy[y][x + 1] == '0')
					return (1);
				if (map_cpy[y - 1][x] == 'E' || map_cpy[y + 1][x] == 'E'
					|| map_cpy[y][x - 1] == 'E' || map_cpy[y][x + 1] == 'E')
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	find_path_to(char c, char **map_cpy)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map_cpy[y] && p_growth(map_cpy))
	{
		x = 0;
		while (map_cpy[y][x])
		{
			if (map_cpy[y][x] == 'P')
			{
				transform_zero(map_cpy, y, x);
				if (map_cpy[y - 1][x] == c || map_cpy[y + 1][x] == c
					|| map_cpy[y][x - 1] == c || map_cpy[y][x + 1] == c)
					return (1);
			}
			x++;
		}
		y++;
		if (map_cpy[y] == NULL)
			y = 0;
	}
	return (0);
}
