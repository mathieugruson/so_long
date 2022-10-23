/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:59:59 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/23 18:35:37 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

void	get_xpm_file(t_mlx *mlx)
{
	mlx->img_zero = mlx_xpm_file_to_image(mlx->mlx_ptr, "./img/orange_sand.xpm", &mlx->img_size, &mlx->img_size);
	mlx->img_one = mlx_xpm_file_to_image(mlx->mlx_ptr, "./img/sea.xpm", &mlx->img_size,&mlx->img_size);	
	mlx->img_p = mlx_xpm_file_to_image(mlx->mlx_ptr, "./img/player_cap.xpm", &mlx->img_size,&mlx->img_size);
	mlx->img_e = mlx_xpm_file_to_image(mlx->mlx_ptr, "./img/raft.xpm", &mlx->img_size,&mlx->img_size);	
	mlx->img_c = mlx_xpm_file_to_image(mlx->mlx_ptr, "./img/lifejacket.xpm", &mlx->img_size,&mlx->img_size);
	mlx->img_s = mlx_xpm_file_to_image(mlx->mlx_ptr, "./img/player_lifedraft_cap.xpm", &mlx->img_size,&mlx->img_size);	
	mlx->img_w = mlx_xpm_file_to_image(mlx->mlx_ptr, "./img/player_raft.xpm", &mlx->img_size,&mlx->img_size);
}

void get_map_display(char **map, t_mlx *mlx)
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
			if (map[y][x] == 'P')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_p, (IMG_DIMENSION * x), (IMG_DIMENSION * y));
			if (map[y][x] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_one, (IMG_DIMENSION * x), (IMG_DIMENSION * y));
			if (map[y][x] == 'C')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_c, (IMG_DIMENSION * x), (IMG_DIMENSION * y));
			if (map[y][x] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_e, (IMG_DIMENSION * x), (IMG_DIMENSION * y));
			if (map[y][x] == 'S')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_s, (IMG_DIMENSION * x), (IMG_DIMENSION * y));
			if (map[y][x] == 'W')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_w, (IMG_DIMENSION * x), (IMG_DIMENSION * y));
			x++;
		}
		y++;
	}
}

int	handle_keyrelease(int keysym, t_mlx *mlx)
{
	static int	i = 0;
	
	if (keysym == XK_Escape)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (keysym == XK_w)
		i = move_map(&mlx->map, mlx, 'U') + i;
	if (keysym == XK_s)
		i = move_map(&mlx->map, mlx, 'D') + i;
	if (keysym == XK_d)
		i = move_map(&mlx->map, mlx, 'R') + i;
	if (keysym == XK_a)
		i = move_map(&mlx->map, mlx, 'L') + i;
	ft_printf("Number of movement : %d\n", i);
	printf("Keypress: %d\n", keysym);
	return (0);
}

char	display_map(char **map, t_mlx *mlx)
{
	t_xy	map_size;
	int		KeySym;

	map_size = get_map_tab_size(map);
	mlx->img_size = IMG_DIMENSION;
	mlx->mlx_ptr = mlx_init();
	mlx->map = map;
	if (mlx->mlx_ptr == NULL)
		return ;
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
}