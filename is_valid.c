/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:41:40 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/28 11:51:16 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	ft_free_tab(map_cpy);
	return (NO_ERROR);
}
