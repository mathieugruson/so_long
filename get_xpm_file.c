/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xpm_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:28:37 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/28 14:41:04 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_image_from_xpm_file(t_mlx *mlx)
{
	if (mlx->img_0 != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_0);
	if (mlx->img_1 != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_1);
	if (mlx->img_c != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_c);
	if (mlx->img_e != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_e);
	if (mlx->img_p != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_p);
	if (mlx->img_s != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_s);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	ft_free_tab(mlx->map);
	ft_printf("Problem in img loading\n");
	exit (1);
}

void	init_img_to_null(t_mlx *mlx)
{
	mlx->img_0 = NULL;
	mlx->img_1 = NULL;
	mlx->img_c = NULL;
	mlx->img_e = NULL;
	mlx->img_p = NULL;
	mlx->img_s = NULL;
}

int	convert_xpm_to_img(t_mlx *mlx)
{
	mlx->img_e = mlx_xpm_file_to_image(mlx->mlx_ptr, "./img/base.xpm",
			&mlx->img_size, &mlx->img_size);
	if (mlx->img_e == NULL)
		return (destroy_image_from_xpm_file(mlx), ERROR);
	mlx->img_0 = mlx_xpm_file_to_image(mlx->mlx_ptr, "./img/space_floor.xpm",
			&mlx->img_size, &mlx->img_size);
	if (mlx->img_0 == NULL)
		return (destroy_image_from_xpm_file(mlx), ERROR);
	mlx->img_p = mlx_xpm_file_to_image(mlx->mlx_ptr, "./img/ufo.xpm",
			&mlx->img_size, &mlx->img_size);
	if (mlx->img_p == NULL)
		return (destroy_image_from_xpm_file(mlx), ERROR);
	mlx->img_1 = mlx_xpm_file_to_image(mlx->mlx_ptr, "./img/tree.xpm",
			&mlx->img_size, &mlx->img_size);
	if (mlx->img_1 == NULL)
		return (destroy_image_from_xpm_file(mlx), ERROR);
	mlx->img_c = mlx_xpm_file_to_image(mlx->mlx_ptr, "./img/battery.xpm",
			&mlx->img_size, &mlx->img_size);
	if (mlx->img_c == NULL)
		return (destroy_image_from_xpm_file(mlx), ERROR);
	mlx->img_s = mlx_xpm_file_to_image(mlx->mlx_ptr, "./img/base_battery.xpm",
			&mlx->img_size, &mlx->img_size);
	if (mlx->img_s == NULL)
		return (destroy_image_from_xpm_file(mlx), ERROR);
	return (NO_ERROR);
}

int	get_xpm_file(t_mlx *mlx)
{
	init_img_to_null(mlx);
	return (convert_xpm_to_img(mlx));
}
