/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <ikhabour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:57:14 by ikhabour          #+#    #+#             */
/*   Updated: 2023/02/17 01:03:00 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_map data, char *image, int x, int y)
{
	int		k;
	int		l;
	void	*img;

	img = mlx_xpm_file_to_image(data.mlx_ptr, image, &k, &l);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img, x * 64, y * 64);
	mlx_destroy_image(data.mlx_ptr, img);
}

void	render_walls(t_map data)
{
	if (data.y == 0 || data.y == data.line_count - 1)
	{
		put_image(data, "./textures/grass_path.xpm", data.x, data.y);
		put_image(data, "./textures/plant.xpm", data.x, data.y);
	}
	else if (data.x == 0 || data.x == (data.line_length - 1))
	{
		put_image(data, "./textures/grass_path.xpm", data.x, data.y);
		put_image(data, "./textures/plant.xpm", data.x, data.y);
	}
	else
		put_image(data, "./textures/walls.xpm", data.x, data.y);
}

void	render_map(t_map data)
{
	data.y = 0;
	while (data.map[data.y])
	{
		data.x = 0;
		while (data.map[data.y][data.x])
		{
			if (data.map[data.y][data.x] == '1')
				render_walls(data);
			else if (data.map[data.y][data.x] == '0')
				put_image(data, "./textures/grass_path.xpm", data.x, data.y);
			else if (data.map[data.y][data.x] == 'C')
				put_image(data, "./textures/collectible.xpm", data.x, data.y);
			else if (data.map[data.y][data.x] == 'E')
				put_image(data, "./textures/exit.xpm", data.x, data.y);
			else if (data.map[data.y][data.x] == 'P')
			{
				put_image(data, "./textures/grass_path.xpm", data.x, data.y);
				put_image(data, "./textures/player/down/down_idle.xpm", data.x,
					data.y);
			}
			data.x++;
		}
		data.y++;
	}
}

void	before_move(t_map *data, t_cords *player_pos)
{
	if (data->current_tile == '0')
	{
		data->map[player_pos->y][player_pos->x] = '0';
		put_image(*data, "./textures/grass_path.xpm", player_pos->x,
			player_pos->y);
	}
	else if (data->current_tile == 'C')
	{
		data->map[player_pos->y][player_pos->x] = 'V';
		put_image(*data, "./textures/collected.xpm", player_pos->x,
			player_pos->y);
	}
	else if (data->current_tile == 'E')
	{
		data->map[player_pos->y][player_pos->x] = 'E';
		put_image(*data, "./textures/exit.xpm", player_pos->x, player_pos->y);
	}
	else if (data->current_tile == 'V')
	{
		data->map[player_pos->y][player_pos->x] = 'V';
		put_image(*data, "./textures/collected.xpm", player_pos->x,
			player_pos->y);
	}
}

void	after_move(t_map *data, t_cords *player_pos, char *move)
{
	if (data->map[player_pos->y][player_pos->x] == '0')
	{
		data->current_tile = '0';
		data->map[player_pos->y][player_pos->x] = 'P';
		render_player(data, player_pos, move);
	}
	else if (data->map[player_pos->y][player_pos->x] == 'E')
	{
		data->current_tile = 'E';
		data->map[player_pos->y][player_pos->x] = 'P';
		render_player(data, player_pos, move);
	}
	else if (data->map[player_pos->y][player_pos->x] == 'C')
	{
		data->current_tile = 'V';
		(data->c)--;
		data->map[player_pos->y][player_pos->x] = 'P';
		render_player(data, player_pos, move);
	}
	else if (data->map[player_pos->y][player_pos->x] == 'V')
	{
		data->current_tile = 'V';
		data->map[player_pos->y][player_pos->x] = 'P';
		render_player(data, player_pos, move);
	}
}
