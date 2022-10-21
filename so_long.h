/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:27:20 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/21 14:55:43 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H 

# include "mlx_linux/mlx.h"
# include "libft/libft_cursus/libft.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/ft_printf/ft_printf.h"
#include <X11/X.h>
#include <X11/keysym.h>

/* error definition */

#define NO_ERROR 1
#define ERRO -1
#define ERROR_MALLOC -2
#define	ERROR_MLX -3
#define	ERROR_WIN -4 
#define	ERROR_IMG -5
#define	ERROR_R_PATH_IMG -6
#define ERROR_ARGC -7

/* dimension definition */

#define IMG_DIMENSION 200

typedef struct coordinates
{
	int			x;
	int			y;
}					t_xy;

typedef struct img_ptr
{
	t_xy	size;
	void	*one;
	void	*zero;
	void	*p;
	void	*pc;
	void	*e;
	void	*ep;
	void	*c;	
}					t_img;

typedef struct struct_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img_ptr;
	t_xy	img_size;
	t_img	filename;	
}					t_mlx;



/* get_map.c */

char	**get_map(char *map_name);

/* get_map_size.c */

t_xy	get_map_fd_size(char *map_name);
t_xy	get_map_tab_size(char **map);

/* map_error.c */

int		are_map_error(char **map);
int		map_character_error(char **map, t_xy map_size);
int		map_dimension_error(t_xy map_size);
int		map_wall_error(char **map, t_xy map_size);

/* path_error.c */

void	transform_zero(char **map_cpy, int y, int x);
int		p_growth(char **map_cpy);
int		find_path_to(char c, char **map_cpy);

#endif 