/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <ikhabour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 04:15:21 by ikhabour          #+#    #+#             */
/*   Updated: 2023/02/17 04:25:15 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_first_last(char *first, char *last, int len)
{
	int	i;

	i = 0;
	if (ft_strlen(last) != (unsigned long)len)
		(write(2, "error1\n", 7), exit(1));
	while (first[i] && last[i])
	{
		if (first[i] != '1' || last[i] != '1')
			(write(2, "error2\n", 7), exit(1));
		i++;
	}
}

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == 'E' || line[i] == 'P'
			|| line[i] == 'C')
			i++;
		else
			return (1);
	}
	return (0);
}

void	check_map_details(t_map *data, char c)
{
	if (c == 'P')
		data->p++;
	if (c == 'E')
		data->e++;
	if (c == 'C')
		data->c++;
}

void	validate_map_details(t_map *data)
{
	if (data->p != 1 || data->e != 1 || data->c < 1)
		(write(2, "errorh\n", 7), exit(1));
}

void	check_middle(char **map, int index, int len, t_map *data)
{
	int	j;
	int	i;

	j = 0;
	while (j++ < index - 1)
	{
		if (!check_line(map[j]))
		{
			i = 0;
			while (map[j][i])
			{
				if (map[j][i] == '\n')
					(write(2, "error3\n", 7), exit(1));
				if (ft_strlen(map[j]) != (unsigned long)len)
					(write(2, "error4\n", 7), exit(1));
				check_map_details(data, map[j][i++]);
			}
		}
		else
			(write(2, "error5\n", 7), exit(1));
		if (map[j][0] != '1' || map[j][i - 1] != '1')
			(write(2, "error6\n", 7), exit(1));
	}
	validate_map_details(data);
}
