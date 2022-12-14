/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:07:59 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/28 11:55:22 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_map(char ***map, t_mlx *mlx, char dir)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	x = 0;
	i = 0;
	while ((*map)[y])
	{
		x = 0;
		while ((*map)[y][x])
		{
			if ((*map)[y][x] == 'P')
			{
				i = update_map(map, y, x, dir);
				get_map_display((*mlx).map, mlx);
				return (i);
			}
			x++;
		}
		y++;
	}
	return (i);
}
