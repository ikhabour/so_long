/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <ikhabour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:44:47 by ikhabour          #+#    #+#             */
/*   Updated: 2023/02/17 04:16:59 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_pos(char **map, t_cords *crds)
{
	crds->y = 0;
	while (map[crds->y])
	{
		crds->x = 0;
		while (map[crds->y][crds->x] && map[crds->y][crds->x] != 'P')
			(crds->x)++;
		if (map[crds->y][crds->x] && map[crds->y][crds->x] == 'P')
			break ;
		(crds->y)++;
	}
}

void	check_path(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				(write(2, "error7\n", 6), exit(1));
			x++;
		}
		y++;
	}
}

int	check_map(char **map, t_map *data)
{
	int		x;
	t_cords	*crds;

	x = 0;
	data->line_count = 0;
	crds = malloc(sizeof(t_cords));
	if (!crds)
		return (0);
	crds->x = 0;
	crds->y = 0;
	data->line_length = ft_strlen(map[0]);
	while (map[data->line_count])
		data->line_count++;
	check_first_last(map[0], map[data->line_count - 1], data->line_length);
	check_middle(map, data->line_count, data->line_length, data);
	find_player_pos(map, crds);
	flood_fill(map, crds->x, crds->y);
	check_path(map);
	return (0);
}

char	**read_map(int fd)
{
	char	*temp;
	char	*str;
	char	*str1;
	char	**map;

	str = malloc(1);
	str[0] = '\0';
	temp = get_next_line(fd);
	if (!temp)
		(write(2, "error8\n", 7), exit(1));
	while (temp != NULL)
	{
		if (ft_strcmp(temp, "\n") == 0)
			(write(2, "error9\n", 7), exit(1));
		str1 = str;
		str = ft_strjoinn(str1, temp);
		free(str1);
		temp = get_next_line(fd);
	}
	if (str[ft_strlen(str) - 1] == '\n')
		(write(2, "error10\n", 7), exit(1));
	map = ft_split(str, '\n');
	return (free(str), close(fd), map);
}

t_map	validate_map(char *argv)
{
	t_map	data;
	char	**map;
	int		fd;

	fd = open(argv, O_RDWR);
	if (fd == -1)
		perror("Failed to open the map");
	data.c = 0;
	data.e = 0;
	data.p = 0;
	map = read_map(fd);
	close(fd);
	fd = open(argv, O_RDWR);
	if (fd == -1)
		perror("Failed to open the map");
	data.map = read_map(fd);
	check_map(map, &data);
	return (data);
}
