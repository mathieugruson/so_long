/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:22:38 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/21 15:02:08 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_xy	get_window_size(t_xy map_size, int img_dimension)
{
	t_xy	window_size;
	
	window_size.x = img_dimension * map_size.x;
	window_size.y = img_dimension * map_size.y; 
	
	return (window_size);
}

int	handle_keyrelease(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	printf("KeyRelease: %d\n", keysym);
	return (0);
}


// void move_up()
// {
	
// 	tabfind_character();	
// }

// int	move_up_keyrelease
// {
// 	if (key == XK_w)
// 		move_up()
// }

void	display_at_window(char **map, t_mlx *mlx)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	mlx->img_size.x = IMG_DIMENSION;
	mlx->img_size.y = IMG_DIMENSION;

	
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return ;	
	mlx->filename.zero = "./img/orange_sand.xpm";
	mlx->filename.p = "./img/player_cap.xpm";
	mlx->filename.one = "./img/sea.xpm";
	mlx->filename.e = "./img/raft.xpm";
	mlx->filename.c = "./img/lifejacket.xpm";

	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->img_size.x * IMG_DIMENSION, mlx->img_size.y * IMG_DIMENSION, "Hello world!");
	if (mlx->win_ptr == NULL)
	{
		free(mlx->win_ptr);
		return ;
	}
	
	mlx->img_ptr.zero = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->filename.zero, &mlx->img_size.x, &mlx->img_size.y);
	mlx->img_ptr.p = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->filename.p, &mlx->img_size.x,&mlx->img_size.y);
	mlx->img_ptr.one = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->filename.one, &mlx->img_size.x,&mlx->img_size.y);
	mlx->img_ptr.e = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->filename.e, &mlx->img_size.x,&mlx->img_size.y);	
	mlx->img_ptr.c = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->filename.c, &mlx->img_size.x,&mlx->img_size.y);
	
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr.zero, (IMG_DIMENSION * x), (IMG_DIMENSION * y));
			if (map[y][x] == 'P')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr.p, (IMG_DIMENSION * x), (IMG_DIMENSION * y));
			if (map[y][x] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr.one, (IMG_DIMENSION * x), (IMG_DIMENSION * y));
			if (map[y][x] == 'C')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr.c, (IMG_DIMENSION * x), (IMG_DIMENSION * y));
			if (map[y][x] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr.e, (IMG_DIMENSION * x), (IMG_DIMENSION * y));
			x++;
		}
		y++;
	}
	mlx_hook(mlx->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &mlx);
	// mlx_hook(mlx->win_ptr, KeyRelease, KeyReleaseMask, &move_up_keyrelease, &mlx);

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