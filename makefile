NAME = so_long
CC = gcc
flags = -Wall -Wextra
functions_c = *.c 
headers = *.h
functions_o = *.o
libx = -L mlx_linux -lmlx_Linux
libxflags = -lmlx -lXext -lX11

all : $(NAME) 

$(functions_o) : $(functions_c) $(headers)
	$(CC) $(flags) -c $(functions_c)

$(NAME) : $(functions_o)
	$(MAKE) --no-print-directory -C libft
	$(MAKE) --no-print-directory -C mlx_linux
	$(CC) $(flags) $(functions_o) libft/libft.a $(libx) $(libxflags) -o $(NAME) -g 

clean :
	$(MAKE) fclean -C libft
	rm -f $(functions_o) 

fclean : clean
	rm -f $(NAME)

re : clean
	make all

.PHONY : all clean fclean re