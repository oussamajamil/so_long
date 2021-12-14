NAME = so_long.a

INCLUDE = so_long.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = 	Controllemaps.c\
		ft_function_libft.c\
		ft_split.c\
		game_mouvment.c\
		get_file.c\
		so_long.c

OBJECTS = $(SRC:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< 

all = $(NAME)


$(NAME): $(OBJECTS) $(INCLUDE)
	ar rc $(NAME) $^



clean:
	rm -rf $(OBJECTS) 

fclean: clean
	rm -rf $(NAME)