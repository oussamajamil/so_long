NAME = so_long.a

INCLUDE = so_long.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_strlen.c\
 ft_join.c\
 	get_file.c\
 	count_word.c\
 	ft_count_and_alloc.c\
 	ft_split_2.c\
	ft_width.c\
 	ft_height.c\
 	ft_designe_game.c\
 	get_map.c\
 	key_hook.c\
 	ft_strstr.c\
 	ft_mapfermer.c

OBJECTS = $(SRC:.c=.o)

all = $(NAME)

$(NAME): $(OBJECTS1) $(INCLUDES)
	ar rc $(NAME) $^

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< -lmlx -framework OpenGL -framework AppKit

clean:
	rm -rf $(OBJECTS) 

fclean: clean
	rm -rf $(NAME)