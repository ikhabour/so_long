NAME = so_long
CC = cc
CFLAGS = -Wextra -Werror -Wall
SRCS = 	so_long.c\
		map_check.c\
		map_check1.c\
		moves.c\
		render_map.c\
		render_moves.c\
		ft_split.c\
		utils.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c

OBJECTS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(SRCS) -o so_long -fsanitize=address -g3

clean :
	rm -rf $(OBJECTS)

fclean : clean

	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re 