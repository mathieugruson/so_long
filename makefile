NAME = so_long
CC = gcc
flags = -Wall -Wextra -Werror
functions_c = *.c 
headers = *.h
functions_o = *.o

all : $(NAME) 

$(functions_o) : $(functions_c) $(headers)
	$(CC) $(flags) -c $(functions_c)

$(NAME) : $(functions_o)
	$(MAKE) --no-print-directory -C libft
	$(CC) $(flags) $(functions_o) libft/libft.a -o $(NAME) 

clean :
	$(MAKE) fclean -C libft
	rm -f $(functions_o) 

fclean : clean
	rm -f $(NAME)

re : clean
	make all

.PHONY : all clean fclean re