/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <ikhabour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:24:43 by ikhabour          #+#    #+#             */
/*   Updated: 2023/02/17 04:20:14 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	find_exit_coordinates(t_cords *exitt, t_map *data)
{
	exitt->y = 0;
	while (data->map[exitt->y])
	{
		exitt->x = 0;
		while (data->map[exitt->y][exitt->x]
			&& data->map[exitt->y][exitt->x] != 'E')
			(exitt->x)++;
		if (data->map[exitt->y][exitt->x]
			&& data->map[exitt->y][exitt->x] == 'E')
			break ;
		(exitt->y)++;
	}
}

void	make_move(int keycode, t_map *data, t_cords *player_pos)
{
	if (keycode == 53)
		(mlx_destroy_window(data->mlx_ptr, data->win_ptr), exit(0));
	if (keycode == 0 || keycode == 123)
		move_left(data, player_pos);
	if (keycode == 1 || keycode == 125)
		move_down(data, player_pos);
	if (keycode == 2 || keycode == 124)
		move_right(data, player_pos);
	if (keycode == 13 || keycode == 126)
		move_up(data, player_pos);
}

int	press(int keycode, t_map *data)
{
	t_cords	player_pos;
	t_cords	exitt;

	exitt.x = 0;
	exitt.y = 0;
	find_player_pos(data->map, &player_pos);
	find_exit_coordinates(&exitt, data);
	make_move(keycode, data, &player_pos);
	data->move_count++;
	ft_putstr_fd("Move Count : ", 1);
	ft_putnbr_fd(data->move_count, 1);
	ft_putstr_fd("\n", 1);
	if (data->c == 0)
	{
		put_image(*data, "./textures/exit_opened.xpm", exitt.x, exitt.y);
		if (player_pos.y == exitt.y && player_pos.x == exitt.x)
		{
			write(1, "YOU WON\n", 8);
			exit(0);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	data;

	data.move_count = 0;
	if (argc != 2)
		(write(2, "invalid arguments\n", 19), exit(1));
	if (ft_strcmp((argv[1] + (ft_strlen(argv[1]) - 4)), ".ber"))
		(write(2, "Error\n", 6), exit(1));
	data = validate_map(argv[1]);
	data.current_tile = '0';
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, (data.line_length * 64),
			(data.line_count * 64), "so_long");
	mlx_key_hook(data.win_ptr, press, &data);
	render_map(data);
	mlx_loop(data.mlx_ptr);
}
