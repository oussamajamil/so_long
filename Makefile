NAME = so_long

INCLUDE = so_long.h

CC = gcc
EXCUTE = main.c
EXCUTEBONUS = main_bonus.c
CFLAGS = -Wall -Wextra -Werror

MLXFLAGE =-lmlx -framework OpenGL -framework AppKit

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

all :$(NAME)

$(NAME) : $(OBJECTS) $(INCLUDE)
	$(CC) $(CFLAGS) $(EXCUTE) $(OBJECTS) $(MLXFLAGE) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

bonus : $(OBJECTSB) $(INCLUDE)
	$(CC) $(CFLAGS) $(EXCUTEBONUS) $(OBJECTSB) $(MLXFLAGE) -o so_long_bonus

clean:
	rm -rf $(OBJECTS) $(OBJECTSB)

fclean: clean
	rm -rf $(NAME) so_long_bonus so_long

re : fclean all