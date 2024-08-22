/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:24:05 by schaaban          #+#    #+#             */
/*   Updated: 2024/08/22 14:11:09 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	error_handling(char **map, char *map_path)
{
	if (check_all_lines(map, map_path) == 0)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	else if (check_p_and_e(map, map_path) == 0)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	return (1);
}

int	error_handling1(char **map, char *map_path)
{
	if (check_chars(map) == 0)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	else if (check_c(map, map_path) == 0)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	else if (check_map_borders(map, map_path) == 0)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	return (1);
}

int	ffill_helper(char **map, char **map1)
{	
	free_2d_array(map);
	free_2d_array(map1);
	write(1, "ERROR\n", 6);
	exit (1);
}

int	error_handling_ffill(char **map, char *map_path)
{
	t_point	player;
	t_count	p;
	int		count_c;
	char	**map1;

	map1 = array2d(map_path);
	count_c = check_count_c(map, map_path);
	player = player_position1(map_path);
	p.c = 0;
	p.e = 0;
	flood_fill(map, player, &p);
	flood_fill_without_e(map1, player, &p);
	if (count_c != p.c)
		ffill_helper(map, map1);
	if (p.e != 1)
		ffill_helper(map, map1);
	free_2d_array(map1);
	return (1);
}

int	check_map_borders(char **map, char *map_path)
{
	int	i;
	int	j;
	int	countline;

	i = 0;
	j = 0;
	countline = count_lines(map_path);
	countline--;
	while (i <= countline)
	{
		if (map[i][0] != '1' || map[i][line_size(map, 0) - 1] != '1')
		{
			return (0);
		}
		i++;
	}
	while (j <= line_size(map, 0) - 1)
	{
		if (map[0][j] != '1' || map[countline][j] != '1')
			return (0);
		j++;
	}
	return (1);
}
