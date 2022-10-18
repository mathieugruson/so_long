/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:22:38 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/18 16:13:37 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main()
{
	char **map;	
	map = NULL;
	map = get_map("map.ber");
	if (map_error(map))
	{
		ft_printf("Error\n");
		return (0);	
	}
	printf("No error\n");
	return (0);
}
