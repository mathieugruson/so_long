/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:47:09 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/17 20:21:20 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

s_info	find_character(char **map, s_info map_size, char c)
{
	s_info	character;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (j <= map_size.x - 1)
		{	
			if (map[i][j] == c)
			{	
				character.y = i;
				character.x = j;
			}
			j++;
		}
		i++;
	}
	return (character);
}

int	find_path_to(char c, char map, s_info m)
{
	int above;
	int	below;
	int	left;
	int	right;

	above = 0;
	below = 0;
	right = 0;
	left = 0;
	
	if (map[m.y][m.x] == 'E')
		return (1);
	if (map[m.y-1][m.x] == 'E' || map[m.y+1][m.x] == 'E'
		|| map[m.y][m.x-1] == 'E' || map[m.y][m.x+1] == 'E') 
		return (1);
	if (map[m.y-1][m.x] == '0') // au dessus
		above = find_path_to('E', map[m.y-1][m.x], m);
	if (map[m.y+1][m.x] == '0') // en dessous
		below = find_path_to('E', map[m.y+1][m.x], m);
	if (map[m.y][m.x-1] == '0') // a gauche 
		left = find_path_to('E', map[m.y-1][m.x], m);
	if (map[m.y][m.x+1] == '0') // a droite 
		right = find_path_to('E', map[m.y][m.x+1]);
	if (above == 1 || below == 1 || right == 1 || left == 1)
		return (1);
	return (0)
}

int	path_error(char **map)
{
	s_info	p;
	s_info	map_size;

	map_size = get_map_tab_size(map);
	p = find_character(map, map_size, 'P');
	if (find_path_to('E', map[p.y][p.x], p) != 'E')
		return (1);
	return (0);
	
}