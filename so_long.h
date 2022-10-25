/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:27:20 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/25 23:16:25 by mgruson          ###   ########.fr       */
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
#define ERROR 0
#define ERROR_MALLOC -2
#define	ERROR_MLX -3
#define	ERROR_WIN -4 
#define	ERROR_IMG -5
#define	ERROR_R_PATH_IMG -6
#define ERROR_ARGC -7

/* dimension definition */

#define IMG_DIMENSION 48

typedef	struct struct_gps
{
	int		y;
	int		x;
}	t_xy;

typedef struct struct_mlx
{
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	int		img_size;
	void	*img_0;
	void	*img_1;
	void	*img_p;
	void	*img_e;
	void	*img_c;
	void	*img_s;
	void	*img_w;	
	void	*f_0;
	void	*f_1;
	void	*f_p;
	void	*f_e;
	void	*f_c;		
	void	*f_s;
}					t_mlx;

/* display map */

int		handle_no_event(void *data);
int		get_xpm_file(t_mlx *mlx);
int		get_map_display(char **map, t_mlx *mlx);
int		handle_keyrelease(int keysym, t_mlx *mlx);
int		display_map(char **map, t_mlx *mlx);

/* get_map.c */

char	**get_map(char *map_name);

/* get_map_size.c */

t_xy	get_map_fd_size(char *map_name);
t_xy	get_map_tab_size(char **map);

/* is_map_name_valid.c */

int	is_map_name_valid(char **argv);

/* is_valid.c */

int		is_map_dimension_valid(t_xy map_size);
int		are_map_character_valid(char **map, t_xy map_size);
int		are_map_wall_valid(char **map, t_xy map_size);
int		is_valid(char **map);
int		is_in_map(char c, char **map);
int		is_one(char c, char **map);


/* is_path_in.c */

void	transform_zero_to(char c, char **map, int y, int x);
int		can_growing(char c, char **map, char goal);
int		is_path_to(char c, char **map);
int		is_path_in(char **map);
int		are_accessible(char c, char **map);

/* move_map.c */

int		move_map(char ***map, t_mlx *mlx, char dir);

/* update_map.c */

int		fdir(int pos, char coor, char dir);
int		update_map(char ***map, int y, int x, char dir);

#endif 