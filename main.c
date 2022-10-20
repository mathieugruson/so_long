/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:22:38 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/20 16:36:03 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define IMG_DIMENSION 34

typedef struct img_ptr
{
	void	*all;
	void	*zero;
	void	*p;
	void	*e;
	void	*c;	
}	t_img_ptr;

typedef struct mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img_ptr	img_ptr;
	t_img_ptr	img_relative_path;	
}	t_mlx;

t_info	get_window_size(t_info map_size, int img_dimension)
{
	t_info	window_size;
	
	window_size.x = img_dimension * map_size.x;
	window_size.y = img_dimension * map_size.y; 
	
	return (window_size);
}

void	display_at_window(char **map, t_info window_size)
{
	int		y;
	int		x;
	t_mlx	mlx;
	t_info	img_size;
	t_info	element_coordinates;

	y = 0;
	x = 0;
	img_size.x = IMG_DIMENSION;
	img_size.y = IMG_DIMENSION;

	mlx.mlx_ptr = mlx_init();	
	mlx.img_relative_path.all = "./img/grass.xpm";
	mlx.img_relative_path.p = "./img/character.xpm";
	
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, window_size.x, window_size.y, "Hello world!");
	mlx.img_ptr.all = mlx_xpm_file_to_image(mlx.mlx_ptr, mlx.img_relative_path.all, &img_size.x, &img_size.y);
	mlx.img_ptr.p = mlx_xpm_file_to_image(mlx.mlx_ptr, mlx.img_relative_path.p, &img_size.x, &img_size.y);

	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' || map[y][x] == 'P' )
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr.all, (IMG_DIMENSION * x), (IMG_DIMENSION * y));
			if (map[y][x] == 'P')
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr.p, (IMG_DIMENSION * x), (IMG_DIMENSION * y));
			x++;
		}
		y++;
	}
	mlx_loop(mlx.mlx_ptr);	
}


int	main(int argc, char **argv)
{
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_relative_path;
	t_info	map_size;
	t_info	window_size;
	t_info	img_size;

	if (argc != 2)
		return (0);
	map = NULL;
	map = get_map(argv[1]);
	map_size = get_map_tab_size(map);
	window_size = get_window_size(map_size, IMG_DIMENSION);
	if (map_error(map))
	{
		ft_printf("Error\n");
		return (0);	
	}
	display_at_window(map, window_size);
}