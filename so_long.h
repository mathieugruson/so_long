/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:27:20 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/21 20:26:53 by mgruson          ###   ########.fr       */
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
typedef	struct struct_gps
{
	int		y;
	int		x;
}	t_xy;

typedef struct struct_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	int		img_size;
	void	*img_one;
	void	*img_zero;
	void	*img_p;
	void	*img_pc;
	void	*img_e;
	void	*img_ep;
	void	*img_c;	
	void	*filename_one;
	void	*filename_zero;
	void	*filename_p;
	void	*filename_pc;
	void	*filename_e;
	void	*filename_ep;
	void	*filename_c;		
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