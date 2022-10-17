/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:41:40 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/17 17:48:11 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	map_error(char **map)
{
	/*
	- une sortie 
	- un personnage
	- un passage
	- un mur
	- existe 
	*/
	
	// if (map_has_not_wall(map_name))
	// 	return (1);

	s_info	map_size;

	map_size = get_map_tab_size(map);
	if (map_size.y < 3)
		return (1);
	if (map_size.x < 3)
		return (1);
	printf("c1\n");
	if (map_size.y / map_size.x == 1)
		return (1);
	if (map_get_wall(map))
		return (1);
	if (map_get_characters(map))
		return (1);
		
	return (0);
}