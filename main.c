// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/10/16 18:22:38 by mgruson           #+#    #+#             */
// /*   Updated: 2022/10/21 17:32:50 by mgruson          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

int	handle_keyrelease(int keysym, t_mlx *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);

	printf("Keypress: %d\n", keysym);
	return (0);
}

void	get_filename(t_mlx	*mlx)
{
	mlx->filename_zero = "./img/orange_sand.xpm";
	mlx->filename_p = "./img/player_cap.xpm";
	mlx->filename_one = "./img/sea.xpm";
	mlx->filename_e = "./img/raft.xpm";
	mlx->filename_c = "./img/lifejacket.xpm";
}

void	get_xpm_file(t_mlx *mlx)
{
	mlx->img_zero = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->filename_zero, &mlx->img_size, &mlx->img_size);
	mlx->img_p = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->filename_p, &mlx->img_size,&mlx->img_size);
	mlx->img_one = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->filename_one, &mlx->img_size,&mlx->img_size);
	mlx->img_e = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->filename_e, &mlx->img_size,&mlx->img_size);	
	mlx->img_c = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->filename_c, &mlx->img_size,&mlx->img_size);
}

void display_map(char **map, t_mlx *mlx)
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
			x++;
		}
		y++;
	}
}

void move_up_p(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if (map[y][x] == 'P')
			{
				map[y + 1][x] = 'P';
				map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}
int	move_up(int keysym, t_mlx *mlx, char **map, t_xy map_size)
{
	if (keysym == XK_w)
	{
		// map[3][2] = 'C';
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		display_map(map, mlx);
	}
	printf("Keypress: %d\n", keysym);
	return (0);
}

void	display_at_window(char **map, t_mlx *mlx)
{
	t_xy	map_size;
	int		KeySym;

	map_size = get_map_tab_size(map);
	mlx->img_size = IMG_DIMENSION;
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return ;
	get_filename(mlx);	
	get_xpm_file(mlx);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, (mlx->img_size * map_size.x) , (mlx->img_size * map_size.y) , "Hello world!");
	if (mlx->win_ptr == NULL)
	{
		free(mlx->win_ptr);
		return ;
	}
	display_map(map, mlx);
	mlx_loop_hook(mlx->mlx_ptr, &handle_no_event, mlx);
	mlx_hook(mlx->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, mlx);
	mlx_hook(mlx->win_ptr, KeyRelease, KeyReleaseMask, &move_up, mlx);
	// map[3][2] = 'C';
	// display_map(map, mlx);
	mlx_loop(mlx->mlx_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_mlx	mlx;

	map = NULL;
	// mlx = NULL;
	if (argc != 2)
		return (ERROR_ARGC);
	map = get_map(argv[1]);
	if (are_map_error(map))
		return (ft_printf("Error\nMap does not comply with subject\n"), 0);	
	display_at_window(map, &mlx);
	// if (are_mlx_error(&mlx))
	// 	return (ERROR_MLX);
	return (0);	
}