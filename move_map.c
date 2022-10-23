/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:07:59 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/23 17:33:05 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_up(char ***map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while ((*map)[y])
	{
		x = 0;
		while((*map)[y][x])
		{
			// if ((*map)[y][x] == 'P' && (*map)[y-1][x] != '1')
			// {
			// 	(*map)[y][x] = '0';
			// 	(*map)[y-1][x] = 'P';
			// 	return ;
			// }
			if ((*map)[y][x] == 'P' || (*map)[y][x] == 'S')
			{
				update_map(map, y, x, 'U');	
				return ;
			} 
			x++;
		}
		y++;
	}
}

void move_down(char ***map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while ((*map)[y])
	{
		x = 0;
		while((*map)[y][x])
		{
			// if ((*map)[y][x] == 'P' && (*map)[y+1][x] != '1')
			// {
			// 	(*map)[y][x] = '0';
			// 	(*map)[y+1][x] = 'P';
			// 	return ;
			// } ici on appelle une void function qui fait les cas
			if ((*map)[y][x] == 'P' || (*map)[y][x] == 'S')
			{
				update_map(map, y, x, 'D');	
				return ;
			} 
			x++;
		}
		y++;
	}
}

void move_left(char ***map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while ((*map)[y])
	{
		x = 0;
		while((*map)[y][x])
		{
			// if ((*map)[y][x] == 'P' && (*map)[y][x-1] != '1')
			// {
			// 	(*map)[y][x] = '0';
			// 	(*map)[y][x-1] = 'P';
			// 	return ;
			// }
			if ((*map)[y][x] == 'P' || (*map)[y][x] == 'S')
			{
				update_map(map, y, x, 'L');	
				return ;
			} 
			x++;
		}
		y++;
	}
}

void move_right(char ***map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while ((*map)[y])
	{
		x = 0;
		while((*map)[y][x])
		{
			// if ((*map)[y][x] == 'P' && (*map)[y][x+1] != '1')
			// {
			// 	(*map)[y][x] = '0';
			// 	(*map)[y][x+1] = 'P';
			// 	return ;
			// }
			if ((*map)[y][x] == 'P' || (*map)[y][x] == 'S')
			{
				update_map(map, y, x, 'R');	
				return ;
			}
  
			x++;
		}
		y++;
	}
}