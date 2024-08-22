/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:26:25 by schaaban          #+#    #+#             */
/*   Updated: 2024/08/22 09:37:22 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*append_char_to_line(char *line, char c, int len)
{
	int		i;
	char	*new_line;

	i = 0;
	new_line = (char *)malloc(len + 2);
	if (!new_line)
		return (NULL);
	while (i < len)
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[len] = c;
	new_line[len + 1] = '\0';
	free (line);
	return (new_line);
}

ssize_t	buffer_read(int fd, char *buffer, int *position, int *buf_size)
{
	*buf_size = read (fd, buffer, BUFFER_SIZE);
	*position = 0;
	return (*buf_size);
}

char	*read_line(int fd, char *buffer, int *position, int *buf_size)
{
	int		line_len;
	char	*line;
	char	c;

	line = NULL;
	line_len = 0;
	while (1)
	{
		if (*position >= *buf_size)
		{
			if (buffer_read(fd, buffer, position, buf_size) <= 0)
			{
				if (line_len > 0)
					return (line);
				free (line);
				return (NULL);
			}
		}
		c = buffer[(*position)++];
		line = append_char_to_line(line, c, line_len++);
		if (!line || c == '\n')
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	position = 0;
	static int	buf_size = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (read_line(fd, buffer, &position, &buf_size));
}
