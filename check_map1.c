/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:21:05 by schaaban          #+#    #+#             */
/*   Updated: 2024/08/22 12:04:58 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	line_size(char **map, int j)
{
	int	i;

	i = 0;
	while (map[j][i] != '\0')
	{
		i++;
	}
	return (i);
}

int	check_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (j < line_size(map, 0))
		{
			if (map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != '0'
				&& map[i][j] != 'C' && map[i][j] != '1')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	free_when_empty_lines(char *line, char *temp, int fd)
{
	free(line);
	free(temp);
	close(fd);
	write(1, "ERROR\n", 6);
	exit(0);
}

int	count_lines(char *map_path)
{
	int		fd;
	int		count;
	char	byte;

	count = 0;
	fd = open_map(map_path);
	if (fd)
	{
		while (read(fd, &byte, 1) > 0)
		{
			if (byte == '\n')
				count++;
		}
	}
	close(fd);
	return (count);
}

int	check_all_lines(char **map, char *map_path)
{
	int	j;
	int	temp;

	j = 0;
	temp = line_size(map, j);
	j++;
	while (j < count_lines(map_path))
	{
		if (line_size(map, j) != temp)
		{
			return (0);
		}
		j++;
	}
	return (1);
}
