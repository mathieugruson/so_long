/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:59:59 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/23 22:46:11 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

int	get_filename(t_mlx	*mlx)
{
	mlx->filename_zero = "./img/space_floor.xpm";
	if (mlx->filename_zero == NULL)
		return(ft_printf("Error\nWrong file name\n"), ERROR);
	mlx->filename_p = "./img/ufo.xpm";
	if (mlx->filename_p == NULL)
		return(ft_printf("Error\nWrong file name\n"), ERROR);
	mlx->filename_one = "./img/tree.xpm";
	if (mlx->filename_one == NULL)
		return(ft_printf("Error\nWrong file name\n"), ERROR);
	mlx->filename_e = "./img/base.xpm";
	if (mlx->filename_e == NULL)
		return(ft_printf("Error\nWrong file name\n"), ERROR);
	mlx->filename_c = "./img/battery.xpm";
	if (mlx->filename_c == NULL)
		return(ft_printf("Error\nWrong file name\n"), ERROR);
	mlx->filename_s = "./img/base_battery.xpm";
	if (mlx->filename_s == NULL)
		return(ft_printf("Error\nWrong file name\n"), ERROR);
	return (NO_ERROR);
}

int	get_xpm_file(t_mlx *mlx)
{
	mlx->img_zero = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->filename_zero, &mlx->img_size, &mlx->img_size);
	mlx->img_p = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->filename_p, &mlx->img_size,&mlx->img_size);
	mlx->img_one = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->filename_one, &mlx->img_size,&mlx->img_size);
	mlx->img_e = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->filename_e, &mlx->img_size,&mlx->img_size);	
	mlx->img_c = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->filename_c, &mlx->img_size,&mlx->img_size);
	mlx->img_s = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->filename_s, &mlx->img_size,&mlx->img_size);
	return (NO_ERROR);
}

int get_map_display(char **map, t_mlx *mlx)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_zero, (IMG_DIMENSION * x), (IMG_DIMENSION * y));
			if (map[y][x] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_one, (IMG_DIMENSION * x), (IMG_DIMENSION * y));
			if (map[y][x] == 'P')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_p, (IMG_DIMENSION * x), (IMG_DIMENSION * y));
			if (map[y][x] == 'C')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_c, (IMG_DIMENSION * x), (IMG_DIMENSION * y));
			if (map[y][x] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_e, (IMG_DIMENSION * x), (IMG_DIMENSION * y));
			if (map[y][x] == 'S')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_s, (IMG_DIMENSION * x), (IMG_DIMENSION * y));

			x++;
		}
		y++;
	}
	return (NO_ERROR);
}

int	handle_keyrelease(int keysym, t_mlx *mlx)
{
	static move = 0;
	int i;

	i = 0;
	if (keysym == XK_Escape)
	{	
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_free_tab(mlx->map);
	}	
	if (keysym == XK_w)
		i = move_map(&mlx->map, mlx, 'U');
	if (keysym == XK_s)
		i = move_map(&mlx->map, mlx, 'D');
	if (keysym == XK_d)
		i = move_map(&mlx->map, mlx, 'R');
	if (keysym == XK_a)
		i = move_map(&mlx->map, mlx, 'L');
	move = move + i;
	if (i == 1)
		ft_printf("Number of movement : %d\n", move);
	return (0);
}

int	display_map(char **map, t_mlx *mlx)
{
	t_xy	map_size;
	int		KeySym;

	map_size = get_map_tab_size(map);
	mlx->img_size = IMG_DIMENSION;
	mlx->map = map;
	get_filename(mlx);
	if (!get_filename)
		return ;	
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return ("Error\nmlx_init function problem");
	get_xpm_file(mlx);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, (mlx->img_size * map_size.x) , (mlx->img_size * map_size.y) , "Hello world!");
	if (mlx->win_ptr == NULL)
	{
		free(mlx->win_ptr);
		return ;
	}
	get_map_display(mlx->map, mlx);
	mlx_loop_hook(mlx->mlx_ptr, &handle_no_event, mlx);
	mlx_hook(mlx->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, mlx);
	mlx_loop(mlx->mlx_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_zero);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_one);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_p);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_c);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_e);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_s);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
}