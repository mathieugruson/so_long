/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:28:15 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/23 18:54:16 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fdir(int pos, char coor, char dir)
{
	if (dir == 'U' && coor == 'Y')
		return (pos - 1);
	if (dir == 'D' && coor == 'Y')
		return (pos + 1);
	if (dir == 'L' && coor == 'Y')
		return (pos);
	if (dir == 'R' && coor == 'Y')
		return (pos);
	if (dir == 'U' && coor == 'X')
		return (pos);
	if (dir == 'D' && coor == 'X')
		return (pos);
	if (dir == 'L' && coor == 'X')
		return (pos - 1);
	if (dir == 'R' && coor == 'X')
		return (pos + 1);
	return (0);
}

int	p_move(char ***map, int y, int x, char dir)
{
	if ((*map)[y][x] == 'P' && (*map)[fdir(y, 'Y', dir)][fdir(x, 'X', dir)] == '0')
	{
		(*map)[y][x] = '0';
		(*map)[fdir(y, 'Y', dir)][fdir(x, 'X', dir)] = 'P';
		return (1);
	}
	if ((*map)[y][x] == 'P' && (*map)[fdir(y, 'Y', dir)][fdir(x, 'X', dir)] == 'C')
	{
		(*map)[y][x] = '0';
		(*map)[fdir(y, 'Y', dir)][fdir(x, 'X', dir)] = 'S';
		return (1);
	}
	return (0);
}

int	s_move(char ***map, int y, int x, char dir)
{
	if ((*map)[y][x] == 'S' && (*map)[fdir(y, 'Y', dir)][fdir(x, 'X', dir)] == '0')
	{
		(*map)[y][x] = '0';
		(*map)[fdir(y, 'Y', dir)][fdir(x, 'X', dir)] = 'S';
		return (1);
	}
	if ((*map)[y][x] == 'S' && (*map)[fdir(y, 'Y', dir)][fdir(x, 'X', dir)] == 'C')
	{
		(*map)[y][x] = '0';
		(*map)[fdir(y, 'Y', dir)][fdir(x, 'X', dir)] = 'S';
		return (1);
	}
	if ((*map)[y][x] == 'S'&& (*map)[fdir(y, 'Y', dir)][fdir(x, 'X', dir)] == 'E')
	{
		(*map)[y][x] = '0';
		(*map)[fdir(y, 'Y', dir)][fdir(x, 'X', dir)] = 'W';
		return (1);
	}
	return (0);	
}	

int	update_map(char ***map, int y, int x, char dir)
{
	int	i;
	
	i = 0;
	i = p_move(map, y, x, dir) + i;
	i = s_move(map, y, x, dir) + i;
	return (i);
}
