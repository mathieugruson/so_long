// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   move_map.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/10/22 14:07:59 by mgruson           #+#    #+#             */
// /*   Updated: 2022/10/22 17:23:07 by mgruson          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "so_long.h"

// void move_up(char ***map)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	x = 0;
// 	while ((*map)[y])
// 	{
// 		x = 0;
// 		while((*map)[y][x])
// 		{
// 			if ((*map)[y][x] == 'P')
// 			{
// 				(*map)[y][x] = '0';
// 				(*map)[y-1][x] = 'P';
// 				return ;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void move_down(char ***map)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	x = 0;
// 	while ((*map)[y])
// 	{
// 		x = 0;
// 		while((*map)[y][x])
// 		{
// 			if ((*map)[y][x] == 'P')
// 			{
// 				(*map)[y][x] = '0';
// 				(*map)[y+1][x] = 'P';
// 				return ;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void move_left(char ***map)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	x = 0;
// 	while ((*map)[y])
// 	{
// 		x = 0;
// 		while((*map)[y][x])
// 		{
// 			if ((*map)[y][x] == 'P')
// 			{
// 				(*map)[y][x] = '0';
// 				(*map)[y][x-1] = 'P';
// 				return ;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void move_right(char ***map)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	x = 0;
// 	while ((*map)[y])
// 	{
// 		x = 0;
// 		while((*map)[y][x])
// 		{
// 			if ((*map)[y][x] == 'P')
// 			{
// 				(*map)[y][x] = '0';
// 				(*map)[y][x+1] = 'P';
// 				return ;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }