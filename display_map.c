/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:59:59 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/26 21:57:56 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(void *data)
{
	return (0);
}

int	get_filename(t_mlx	*mlx)
{
	mlx->f_0 = "./img/space_floor.xpm";
	if (mlx->f_0 == NULL)
		return (ft_printf("Error\nWrong file name\n"), ERROR);
	mlx->f_p = "./img/ufo.xpm";
	if (mlx->f_p == NULL)
		return (ft_printf("Error\nWrong file name\n"), ERROR);
	mlx->f_1 = "./img/tree.xpm";
	if (mlx->f_1 == NULL)
		return (ft_printf("Error\nWrong file name\n"), ERROR);
	mlx->f_e = "./img/base.xpm";
	if (mlx->f_e == NULL)
		return (ft_printf("Error\nWrong file name\n"), ERROR);
	mlx->f_c = "./img/battery.xpm";
	if (mlx->f_c == NULL)
		return (ft_printf("Error\nWrong file name\n"), ERROR);
	mlx->f_s = "./img/base_battery.xpm";
	if (mlx->f_s == NULL)
		return (ft_printf("Error\nWrong file name\n"), ERROR);
	return (NO_ERROR);
}

void	destroy_image_from_xpm_file(t_mlx *mlx)
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
}

int	get_xpm_file(t_mlx *mlx)
{
	mlx->img_0 = NULL;
	mlx->img_1 = NULL;
	mlx->img_c = NULL;
	mlx->img_e = NULL;
	mlx->img_p = NULL;
	mlx->img_s = NULL;
	
	mlx->img_e = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->f_e,
			&mlx->img_size, &mlx->img_size);
	if (mlx->img_e == NULL)
		return (destroy_image_from_xpm_file(mlx), ERROR);
	mlx->img_0 = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->f_0,
			&mlx->img_size, &mlx->img_size);
	if (mlx->img_0 == NULL)
		return (destroy_image_from_xpm_file(mlx), ERROR);
	mlx->img_p = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->f_p,
			&mlx->img_size, &mlx->img_size);
	if (mlx->img_p == NULL)
		return (destroy_image_from_xpm_file(mlx), ERROR);
	mlx->img_1 = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->f_1,
			&mlx->img_size, &mlx->img_size);
	if (mlx->img_1 == NULL)
		return (destroy_image_from_xpm_file(mlx), ERROR);
	mlx->img_c = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->f_c,
			&mlx->img_size, &mlx->img_size);
	if (mlx->img_c == NULL)
		return (destroy_image_from_xpm_file(mlx), ERROR);
	mlx->img_s = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->f_s,
			&mlx->img_size, &mlx->img_size);
	if (mlx->img_s == NULL)
		return (destroy_image_from_xpm_file(mlx), ERROR);
	return (NO_ERROR);
}

void	ft_put_image_to_window(int y, int x, t_mlx *mlx, char **map)
{
	int	x1;
	int	y2;

	x1 = x * IMG_DIMENSION;
	y2 = y * IMG_DIMENSION;
	if (map[y][x] == '0')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_0, x1, y2);
	if (map[y][x] == '1')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_1, x1, y2);
	if (map[y][x] == 'P')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_p, x1, y2);
	if (map[y][x] == 'C')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_c, x1, y2);
	if (map[y][x] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_e, x1, y2);
	if (map[y][x] == 'S')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_s, x1, y2);
}

int	get_map_display(char **map, t_mlx *mlx)
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
			ft_put_image_to_window(y, x, mlx, map);
			x++;
		}
		y++;
	}
	return (NO_ERROR);
}

int	handle_keyrelease(int keysym, t_mlx *mlx)
{
	static int	move;
	int			i;

	if (!move)
		move = 0;
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

int	handle_destroynotify(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	ft_free_tab(mlx->map);
	return (0);
}

void	destroy_mlx(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_0);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_1);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_p);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_c);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_e);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_s);
	mlx_destroy_display(mlx->mlx_ptr);

}

int	display_map(char **map, t_mlx *mlx)
{
	t_xy	map_size;
	int		keysym;

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
	if (get_xpm_file(mlx) == NULL)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		ft_free_tab(mlx->map);
		free(mlx->mlx_ptr);
		exit(EXIT_FAILURE);
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, (mlx->img_size * map_size.x), (mlx->img_size * map_size.y) , "Hello world!");
	if (mlx->win_ptr == NULL)
	{
		free(mlx->win_ptr);
		return ;
	}
	get_map_display(mlx->map, mlx);
	mlx_loop_hook(mlx->mlx_ptr, &handle_no_event, mlx);
	mlx_hook(mlx->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, mlx);
	mlx_hook(mlx->win_ptr, DestroyNotify, StructureNotifyMask, &handle_destroynotify, mlx);
	mlx_loop(mlx->mlx_ptr);
	destroy_mlx(mlx);
	free(mlx->mlx_ptr);
}
