/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <ikhabour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:22:41 by ikhabour          #+#    #+#             */
/*   Updated: 2023/02/17 04:19:05 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct crds
{
	int		x;
	int		y;
}			t_cords;

typedef struct map_data
{
	int		p;
	int		e;
	int		c;
	int		x;
	int		y;
	int		pixelx;
	int		pixely;
	int		line_length;
	int		line_count;
	int		move_count;
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	char	current_tile;
	t_cords	crds;
}			t_map;

char		*ft_strjoinn(char *str1, char *str2);
char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
char		**ft_split(const char *s, char c);
void		flood_fill(char **map, int x, int y);
t_map		validate_map(char *argv);
char		**read_map(int fd);
int			check_map(char **map, t_map *data);
void		check_path(char **map);
void		find_player_pos(char **map, t_cords *crds);
void		check_middle(char **map, int index, int len, t_map *data);
int			check_line(char *line);
void		check_first_last(char *first, char *last, int len);
int			ft_strcmp(char *s1, char *s2);
void		ft_putnbr_fd(int nb, int fd);
void		ft_putchar_fd(char c, int fd);
void		move_up(t_map *data, t_cords *player_pos);
void		move_down(t_map *data, t_cords *player_pos);
void		move_right(t_map *data, t_cords *player_pos);
void		move_left(t_map *data, t_cords *player_pos);
void		render_player(t_map *data, t_cords *player_pos, char *move);
void		render_up(t_map *data, t_cords *player_pos);
void		render_down(t_map *data, t_cords *player_pos);
void		render_right(t_map *data, t_cords *player_pos);
void		render_left(t_map *data, t_cords *player_pos);
void		put_image(t_map data, char *image, int x, int y);
void		render_walls(t_map data);
void		render_map(t_map data);
void		after_move(t_map *data, t_cords *player_pos, char *move);
void		before_move(t_map *data, t_cords *player_pos);
int			ft_strcmp(char *s1, char *s2);
void		flood_fill(char **map, int x, int y);
void		check_first_last(char *first, char *last, int len);
int			check_line(char *line);
void		check_map_details(t_map *data, char c);
void		validate_map_details(t_map *data);
void		check_middle(char **map, int index, int len, t_map *data);

#endif