/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <ikhabour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:55:50 by ikhabour          #+#    #+#             */
/*   Updated: 2023/03/10 18:22:28 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_move_right(t_map *data, t_list *tmp, t_cords *player_pos)
{
	static int	d;

	data->map[tmp->y][tmp->x] = '0';
	put_image(*data, "./textures/grass_path.xpm", tmp->x, tmp->y);
	tmp->x++;
	if (tmp->y == player_pos->y && tmp->x == player_pos->x)
	{
		you_lost();
		exit(0);
	}
	data->map[tmp->y][tmp->x] = 'X';
	if (d == 0)
	{
		put_image(*data, "./bonus/textures/enemy/right_flight1.xpm", tmp->x,
			tmp->y);
		d++;
	}
	else if (d == 1)
	{
		put_image(*data, "./bonus/textures/enemy/right_flight2.xpm", tmp->x,
			tmp->y);
		d = 0;
	}
}

void	enemy_move_left(t_map *data, t_list *tmp, t_cords *player_pos)
{
	static int	d;

	data->map[tmp->y][tmp->x] = '0';
	put_image(*data, "./textures/grass_path.xpm", tmp->x, tmp->y);
	tmp->x--;
	if (tmp->y == player_pos->y && tmp->x == player_pos->x)
	{
		you_lost();
		exit(0);
	}
	data->map[tmp->y][tmp->x] = 'X';
	if (d == 0)
	{
		put_image(*data, "./bonus/textures/enemy/left_flight1.xpm", tmp->x,
			tmp->y);
		d++;
	}
	else if (d == 1)
	{
		put_image(*data, "./bonus/textures/enemy/left_flight2.xpm", tmp->x,
			tmp->y);
		d = 0;
	}
	tmp->d = 1;
}

int	check_front(t_map *data, t_list *tmp)
{
	if (data->map[tmp->y][tmp->x + 1] != '1' && data->map[tmp->y][tmp->x
		+ 1] != 'X' && data->map[tmp->y][tmp->x + 1] != 'C'
		&& data->map[tmp->y][tmp->x + 1] != 'E' && data->map[tmp->y][tmp->x
		+ 1] != 'V')
		return (1);
	return (0);
}

int	check_back(t_map *data, t_list *tmp)
{
	if (data->map[tmp->y][tmp->x - 1] != '1' && data->map[tmp->y][tmp->x
		- 1] != 'X' && data->map[tmp->y][tmp->x - 1] != 'C'
		&& data->map[tmp->y][tmp->x - 1] != 'E' && data->map[tmp->y][tmp->x
		- 1] != 'V')
		return (1);
	return (0);
}

int	move_enemy(t_map *data)
{
	static int	c;
	t_cords		player_pos;
	t_list		*tmp;

	find_player_pos(data->map, &player_pos);
	while (c++ == 2000)
	{
		tmp = data->enemy_pos;
		while (tmp)
		{
			if (check_front(data, tmp) && tmp->d == 0)
				enemy_move_right(data, tmp, &player_pos);
			else if (check_back(data, tmp))
				enemy_move_left(data, tmp, &player_pos);
			else
				tmp->d = 0;
			tmp = tmp->next;
		}
		c = 0;
	}
	return (0);
}
