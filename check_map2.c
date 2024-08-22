/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:22:39 by schaaban          #+#    #+#             */
/*   Updated: 2024/08/22 12:37:43 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_p_and_e(char **map, char *map_path)
{
	int	i;
	int	j;
	int	count_p;
	int	count_e;

	j = 0;
	count_p = 0;
	count_e = 0;
	while (j < count_lines(map_path))
	{
		i = 0;
		while (i < line_size(map, j))
		{
			if (map[j][i] == 'E')
				count_e++;
			if (map[j][i] == 'P')
				count_p++;
			i ++;
		}
		j ++;
	}
	if (count_e == 1 && count_p == 1)
		return (1);
	return (0);
}

int	check_c(char **map, char *map_path)
{
	int	i;
	int	j;
	int	count_c;

	j = 0;
	count_c = 0;
	while (j < count_lines(map_path))
	{
		i = 0;
		while (i < line_size(map, j))
		{
			if (map[j][i] == 'C')
				count_c++;
			i++;
		}
		j++;
	}
	if (count_c > 0)
		return (1);
	return (0);
}

int	check_count_c(char **map, char *map_path)
{
	int	i;
	int	j;
	int	count_c;

	j = 0;
	count_c = 0;
	while (j < count_lines(map_path))
	{
		i = 0;
		while (i < line_size(map, j))
		{
			if (map[j][i] == 'C')
				count_c++;
			i++;
		}
		j++;
	}
	return (count_c);
}
