/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:42:18 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/18 16:20:38 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_info	get_map_fd_size(char *map_name)
{
	int		fd;
	char	*tmp;
	int		i;
	t_info	map;

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

t_info	get_map_tab_size(char **tab)
{
	int		i;
	t_info	map;

	map.x = 0;
	map.y = 0;
	map.x = ft_strlen(tab[0]) - 1;
	i = 0;
	while (tab[i])
	{
		i++;
	}
	map.y = i;
	return (map);
}
