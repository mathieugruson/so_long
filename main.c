/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:22:38 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/18 15:37:03 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **get_map(char *map_name)
{
	int	i;
	char *line_map;
	s_info	map_size;
	int	fd;
	char **map;
	
	fd = open(map_name, O_RDONLY);
	map_size = get_map_fd_size(map_name);
	i = 0;
	map = malloc(sizeof(char *) * (map_size.y + 1));
	if (!map)
		return (NULL);
	map[map_size.y] = NULL;	
	while(i < map_size.y)
	{
		line_map = get_next_line(fd);
		map[i] = malloc(sizeof(char) * (map_size.x + 2));
		if (!map[i])
			return (NULL);
		map[i][map_size.x + 1] = '\0';
		ft_strlcpy(map[i], line_map, map_size.x + 2);
		free(line_map);
		i++;	
	}
	close(fd);
	return (map);
}

int	main()
{
	char **map;	
	map = NULL;
	map = get_map("map.ber");
	ft_puttab(map);
	ft_free_tab(map);	
	
	// if (map_error(map))
	// {
	// 	ft_printf("Error\n");
	// 	return (0);	
	// }
	// printf("No error\n");
	return (0);
}