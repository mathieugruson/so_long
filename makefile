NAME = so_long
CC = gcc
flags = -Wall -Wextra -Werror
functions_c =	display_map.c ft_free_mlx.c get_map_size.c \
				get_map.c get_xpm_file.c is_map_name_valid.c \
				is_path_in.c is_valid_functions.c is_valid.c \
				main.c move_map.c update_map.c \

headers = so_long.h
functions_o = *.o
libx = -L mlx_linux -lmlx_Linux
libxflags = -lmlx -lXext -lX11 -lmlx_Linux

all : $(NAME) 

$(functions_o) : $(functions_c) $(headers)
	$(CC) $(flags) -c $(functions_c)

$(NAME) : $(functions_o)
	$(MAKE) --no-print-directory -C libft
	$(MAKE) --no-print-directory -C mlx_linux
	$(CC) $(flags) $(functions_o) libft/libft.a $(libx) $(libxflags) -o $(NAME) -g
#	mkdir obj 
#	mv *.o obj/ 

clean :
	$(MAKE) fclean -C libft
	rm -f $(functions_o)
	rm so_long
# rm -dir -f obj 

fclean : clean
	rm -f $(NAME)

re : clean
	make all

.PHONY : all clean fclean re