/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:59:59 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/28 11:42:53 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		ft_free_mlx(mlx);
	if (keysym == XK_w || keysym == XK_W)
		i = move_map(&mlx->map, mlx, 'U');
	if (keysym == XK_s || keysym == XK_S)
		i = move_map(&mlx->map, mlx, 'D');
	if (keysym == XK_d || keysym == XK_D)
		i = move_map(&mlx->map, mlx, 'R');
	if (keysym == XK_a || keysym == XK_A)
		i = move_map(&mlx->map, mlx, 'L');
	move = move + i;
	if (i == 1)
		ft_printf("Number of movement : %d\n", move);
	return (0);
}

void	display_map(char **map, t_mlx *mlx)
{
	t_xy	map_size;

	map_size = get_map_tab_size(map);
	mlx->img_size = IMG_DIMENSION;
	mlx->map = map;
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return ;
	get_xpm_file(mlx);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, (mlx->img_size * map_size.x), \
	(mlx->img_size * map_size.y), "SO_LONG");
	if (mlx->win_ptr == NULL)
	{
		ft_free_mlx(mlx);
		return ;
	}
	get_map_display(mlx->map, mlx);
	mlx_hook(mlx->win_ptr, KeyPress, KeyPressMask, &handle_keyrelease, mlx);
	mlx_hook(mlx->win_ptr, DestroyNotify, StructureNotifyMask, \
	&ft_free_mlx, mlx);
	mlx_loop(mlx->mlx_ptr);
}
