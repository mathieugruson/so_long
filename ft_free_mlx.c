/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:40:38 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/28 11:41:04 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free_mlx(t_mlx *mlx)
{	
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_0);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_1);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_p);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_c);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_e);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_s);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	ft_free_tab(mlx->map);
	exit (1);
}
