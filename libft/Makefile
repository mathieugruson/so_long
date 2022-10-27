NAME = libft.a

cc = gcc
flags = -Wall -Wextra -Werror
functions_c = libft_cursus/*.c ft_printf/*.c get_next_line/*.c 
headers = libft_cursus/*.h ft_printf/*.h get_next_line/*.h
functions_o = *.o

all : $(NAME)

$(NAME) : $(functions_o)
	ar rc $(NAME) $^

$(functions_o) : $(functions_c) $(headers)
	$(CC) $(flags) -c $(functions_c) 

clean :
	rm $(NAME) $(functions_o)

fclean : clean
	rm -f $(NAME)
	rm -f $(BONUS)

re : fclean
	make all

.PHONY : all clean fclean re
