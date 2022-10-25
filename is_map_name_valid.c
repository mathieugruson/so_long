/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_name_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:57:35 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/25 22:34:29 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_name_valid(char **argv)
{
	int	len;

	len = ft_strlen(argv[1]);
	if (argv[1][len - 1] != 'r' || argv[1][len - 2] != 'e'
		|| argv[1][len - 3] != 'b' || argv[1][len - 4] != '.'
		|| !argv[1][len - 5])
		return (ft_printf("Error\nFile name invalid\n"), ERROR);
	return (NO_ERROR);
}
