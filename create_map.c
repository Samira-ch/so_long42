/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:22:57 by schaaban          #+#    #+#             */
/*   Updated: 2024/08/22 09:37:04 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	open_map(const char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd <= 0)
	{
		return (0);
	}
	return (fd);
}

size_t	ft_strlen1(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	**array2d(char *map_path)
{
	char	**splitted_map;
	char	*map;

	map = fill_array(map_path);
	if (map)
	{
		splitted_map = ft_split(map, '\n');
		free(map);
		return (splitted_map);
	}
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;

	if (!src && !dest)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*copy;

	len = ft_strlen1(s1) + 1;
	copy = (char *)malloc(len);
	if (copy)
		ft_memcpy(copy, s1, len);
	return (copy);
}
