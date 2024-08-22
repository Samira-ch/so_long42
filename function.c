/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:25:56 by schaaban          #+#    #+#             */
/*   Updated: 2024/08/22 13:19:30 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

void	fill_array_helper(char **array, char **temp, char **line, int fd)
{
	(*array) = ft_strjoin(*temp, *line);
	free(*line);
	free(*temp);
	*temp = NULL;
	*temp = ft_strdup(*array);
	*line = get_next_line(fd);
}

char	*fill_array(char *mappath)
{
	char	*line;
	char	*array;
	int		fd;
	char	*temp;

	fd = open_map(mappath);
	line = get_next_line(fd);
	array = NULL;
	temp = ft_strdup("");
	while (line)
	{
		if (ft_strncmp(line, "\n", ft_strlen(line)) != 0)
		{
			fill_array_helper(&array, &temp, &line, fd);
			if (line == NULL)
				break ;
			free(array);
		}
		else
			free_when_empty_lines(line, temp, fd);
	}
	free(temp);
	close(fd);
	return (array);
}

void	free_2d_array(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}

void	wfree(t_data *data, char **map)
{
	free_2d_array(map);
	on_destroy(data);
}
