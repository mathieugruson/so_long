/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:37:38 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/27 21:56:53 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	t_mlx	mlx;

	map = NULL;
	if (argc != 2)
		return (ERROR);
	if (!is_map_name_valid(argv))
		return (ERROR);
	map = get_map(argv[1]);
	if (!is_valid(map))
		return (ERROR);
	display_map(map, &mlx);
	ft_free_tab(map);
	free(argv[1]);
	return (0);	
}