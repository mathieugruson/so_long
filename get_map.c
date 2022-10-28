/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:07:06 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/28 14:36:32 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(char *map_name)
{
	int		i;
	char	*line_map;
	t_xy	map_size;
	int		fd;
	char	**map;

	fd = open(map_name, O_RDONLY);
	map_size = get_map_fd_size(map_name);
	i = 0;
	map = malloc(sizeof(char *) * (map_size.y + 1));
	if (!map)
		return (NULL);
	map[map_size.y] = NULL;
	while (i < map_size.y)
	{
		line_map = get_next_line(fd);
		map[i] = malloc(sizeof(char) * (map_size.x + 2));
		if (!map[i])
			return (ft_free_tab(map), NULL);
		ft_strlcpy(map[i], line_map, map_size.x + 2);
		free(line_map);
		i++;
	}
	close(fd);
	return (map);
}
