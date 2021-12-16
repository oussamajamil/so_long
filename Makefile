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

SRCB = Controllemaps.c\
		ft_function_libft.c\
		ft_split.c\
		game_mouvement_bonus.c\
		get_file.c\
		ft_itoa.c\
		so_long_bonus.c\
		ft_annimation.c

OBJECTS = $(SRC:.c=.o)
OBJECTSB = $(SRCB:.c=.o)
%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< 

all = $(NAME)


$(NAME): $(OBJECTS) $(INCLUDE)
	ar rc $(NAME) $^

bonus :$(OBJECTSB) $(INCLUDE)
	ar rc $(NAME) $^

clean:
	rm -rf $(OBJECTS) $(OBJECTSB)

fclean: clean
	rm -rf $(NAME)