/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <ikhabour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:50:46 by ikhabour          #+#    #+#             */
/*   Updated: 2023/03/09 14:48:23 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_left(t_map *data, t_cords *player_pos)
{
	if (data->map[player_pos->y][player_pos->x - 1] != '1')
	{
		before_move(data, player_pos);
		(player_pos->x)--;
		after_move(data, player_pos, "left");
		data->move_count++;
	}
}

void	move_down(t_map *data, t_cords *player_pos)
{
	if (data->map[player_pos->y + 1][player_pos->x] != '1')
	{
		before_move(data, player_pos);
		(player_pos->y)++;
		after_move(data, player_pos, "down");
		data->move_count++;
	}
}

void	move_right(t_map *data, t_cords *player_pos)
{
	if (data->map[player_pos->y][player_pos->x + 1] != '1')
	{
		before_move(data, player_pos);
		(player_pos->x)++;
		after_move(data, player_pos, "right");
		data->move_count++;
	}
}

void	move_up(t_map *data, t_cords *player_pos)
{
	if (data->map[(player_pos->y) - 1][player_pos->x] != '1')
	{
		before_move(data, player_pos);
		(player_pos->y)--;
		after_move(data, player_pos, "up");
		data->move_count++;
	}
}

void	render_player(t_map *data, t_cords *player_pos, char *move)
{
	if (ft_strcmp(move, "down") == 0)
		render_down(data, player_pos);
	else if (ft_strcmp(move, "left") == 0)
		render_left(data, player_pos);
	else if (ft_strcmp(move, "up") == 0)
		render_up(data, player_pos);
	else if (ft_strcmp(move, "right") == 0)
		render_right(data, player_pos);
}
