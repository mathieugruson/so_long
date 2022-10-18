/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:18:35 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/18 15:23:42 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_free_tab(char **tab)
{
	int	tablen;
	int	y;
	
	tablen = ft_tablen(tab);
	y = 0;
	while (y < tablen)
	{
		free(tab[y]);
		y++;
	}	
	free(tab);
}