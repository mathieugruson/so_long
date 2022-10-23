/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:37:38 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/23 17:59:44 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	t_mlx	mlx;

	map = NULL;
	// mlx = NULL;
	if (argc != 2)
		return (ERROR_ARGC);
	map = get_map(argv[1]);
	if (!is_valid(map))
		return (ft_printf("Error\nMap does not comply with subject\n"), ERROR);	
	display_map(map, &mlx);
	// if (are_mlx_error(&mlx))
	// 	return (ERROR_MLX);
	return (0);	
}