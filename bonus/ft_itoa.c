/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <ikhabour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:34:45 by ikhabour          #+#    #+#             */
/*   Updated: 2023/03/10 14:45:02 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	nbr_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len++;
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int		len;
	char	*res;

	len = nbr_len(nbr);
	res = malloc(sizeof(char) * (len + 1));
	if (nbr == -2147483648)
	{
		res = "-2147483648";
		return (res);
	}
	res[len--] = '\0';
	if (nbr == 0)
		res[len] = '0';
	if (nbr < 0)
	{
		nbr *= -1;
		res[0] = '-';
	}
	while (nbr)
	{
		res[len--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (res);
}

void	display_count(t_map data)
{
	char	*move_count;

	move_count = ft_itoa(data.move_count);
	put_image(data, "./textures/grass_path.xpm", 1, 0);
	put_image(data, "./textures/plant.xpm", 1, 0);
	mlx_string_put(data.mlx_ptr, data.win_ptr, 64, 0, 0255204, move_count);
	free(move_count);
}

void	find_enemy_coordinates(t_map *data)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = 0;
	j = 0;
	data->enemy_pos = ft_lstnew(0, 0, 0);
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'X')
				ft_lstadd_back(&data->enemy_pos, ft_lstnew(i, j, 0));
			i++;
		}
		j++;
	}
	tmp = data->enemy_pos;
	data->enemy_pos = data->enemy_pos->next;
	free(tmp);
}

void	render_map(t_map data)
{
	data.y = 0;
	while (data.map[data.y])
	{
		data.x = 0;
		while (data.map[data.y][data.x])
		{
			render_images(data);
			data.x++;
		}
		data.y++;
	}
}
