/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <ikhabour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:53:30 by ikhabour          #+#    #+#             */
/*   Updated: 2023/02/17 00:58:18 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_left(t_map *data, t_cords *player_pos)
{
	static int	move;

	if (move == 0)
	{
		put_image(*data, "./textures/player/left/left_idle.xpm", player_pos->x,
			player_pos->y);
		move++;
	}
	else if (move == 1)
	{
		put_image(*data, "./textures/player/left/left_move01.xpm",
			player_pos->x, player_pos->y);
		move++;
	}
	else if (move == 2)
	{
		put_image(*data, "./textures/player/left/left_move02.xpm",
			player_pos->x, player_pos->y);
		move = 0;
	}
}

void	render_right(t_map *data, t_cords *player_pos)
{
	static int	move;

	if (move == 0)
	{
		put_image(*data, "./textures/player/right/right_idle.xpm",
			player_pos->x, player_pos->y);
		move++;
	}
	else if (move == 1)
	{
		put_image(*data, "./textures/player/right/right_move01.xpm",
			player_pos->x, player_pos->y);
		move++;
	}
	else if (move == 2)
	{
		put_image(*data, "./textures/player/right/right_move02.xpm",
			player_pos->x, player_pos->y);
		move = 0;
	}
}

void	render_up(t_map *data, t_cords *player_pos)
{
	static int	move;

	if (move == 0)
	{
		put_image(*data, "./textures/player/up/up_idle.xpm", player_pos->x,
			player_pos->y);
		move++;
	}
	else if (move == 1)
	{
		put_image(*data, "./textures/player/up/up_move01.xpm", player_pos->x,
			player_pos->y);
		move++;
	}
	else if (move == 2)
	{
		put_image(*data, "./textures/player/up/up_move02.xpm", player_pos->x,
			player_pos->y);
		move = 0;
	}
}

void	render_down(t_map *data, t_cords *player_pos)
{
	static int	move;

	if (move == 0)
	{
		put_image(*data, "./textures/player/down/down_move01.xpm",
			player_pos->x, player_pos->y);
		move++;
	}
	else if (move == 1)
	{
		put_image(*data, "./textures/player/down/down_move02.xpm",
			player_pos->x, player_pos->y);
		move = 0;
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
		ft_putnbr_fd(nb, fd);
	}
	else if (nb < 10)
	{
		ft_putchar_fd(nb + '0', fd);
	}
	else if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}
