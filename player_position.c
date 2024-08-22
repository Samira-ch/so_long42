/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:28:53 by schaaban          #+#    #+#             */
/*   Updated: 2024/08/22 13:21:11 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	player_position(t_data *data, char *map_path)
{
	int	i;
	int	j;

	i = 0;
	while (i < count_lines(map_path))
	{
		j = 0;
		while (j <= line_size(data->map, 0))
		{
			if (data->map[i][j] == 'P')
			{
				data->i = j;
				data->j = i;
			}
			j++;
		}
		i++;
	}
}

t_point	player_position1(char *map_path)
{
	int		i;
	int		j;
	t_point	position;
	char	*full_map;
	char	**map;

	i = 0;
	full_map = fill_array(map_path);
	map = array2d(map_path);
	while (++i < count_lines(map_path))
	{
		j = 0;
		while (++j <= line_size(map, 0))
		{
			if (map[i][j] == 'P')
			{
				position.x = i;
				position.y = j;
			}
		}
	}
	free(full_map);
	free_2d_array(map);
	return (position);
}

void	flood_fill(char **tab, t_point begin, t_count *p)
{
	fill(tab, begin, p);
}
