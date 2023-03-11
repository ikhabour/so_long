NAME = so_long
NAME_BONUS = so_long_bonus
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
		utils2.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c

SRCS_BONUS = bonus/so_long_bonus.c\
			bonus/map_check_bonus.c\
			bonus/map_check1_bonus.c\
			bonus/moves_bonus.c\
			bonus/render_map_bonus.c\
			bonus/render_moves_bonus.c\
			bonus/ft_split_bonus.c\
			bonus/utils_bonus.c\
			bonus/gnl/get_next_line_bonus.c\
			bonus/gnl/get_next_line_utils_bonus.c\
			bonus/linked_lists.c\
			bonus/enemy_movements.c\
			bonus/utils2_bonus.c\
			bonus/ft_itoa.c

OBJECTS = $(SRCS:.c=.o)

OBJECTS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(SRCS) -o $(NAME)

bonus : $(OBJECTS_BONUS)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(SRCS_BONUS) -o $(NAME_BONUS)

clean :
	rm -rf $(OBJECTS)
	rm -rf $(OBJECTS_BONUS)

fclean : clean

	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re 