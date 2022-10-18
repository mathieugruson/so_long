/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:42:18 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/18 15:42:16 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

s_info get_map_fd_size(char *map_name)
{
	int fd;
	char *tmp;
	int i;
	s_info	map;
	
	map.x = 0;
	map.y = 0;
	fd = 0;
	fd = open(map_name, O_RDONLY);
	tmp = get_next_line(fd);
	map.x = ft_strlen(tmp) - 1;
	free(tmp);
	i = 0;
	while (tmp)
	{
		tmp = get_next_line(fd);
		free(tmp);
		i++;
	}
	free(tmp);
	close(fd);
	map.y = i;	
	return (map);	
}

s_info get_map_tab_size(char **tab)
{
	int i;
	s_info	map;
	
	map.x = 0;
	map.y = 0;
	map.x = ft_strlen(tab[0]);
	i = 0;
	while (tab[i])
	{
		i++;
	}
	map.y = i;	
	return (map);	
}