/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:27:35 by schaaban          #+#    #+#             */
/*   Updated: 2024/08/22 14:13:57 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	main2(char *s)
{
	char	**map;

	map = array2d(s);
	if (!map)
	{
		write(1, "ERROR\n", 6);
		return ;
	}
	if (check_all_lines(map, s) == 0)
	{
		write(1, "ERROR\n", 6);
		return ;
	}
	if (!free1(map, s) || !free2(s, map))
	{
		free_2d_array(map);
		return ;
	}
	free_2d_array(map);
	mainhelper11(s);
}

int	main(int ac, char *av[])
{
	int	l;
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	if (ac == 2)
	{
		l = ft_strlen(av[1]) - 1;
		while (av[1][l] == ' ' || av[1][l] == '\t')
			l--;
		if (av[1][l] == 'r' && av[1][l - 1] == 'e' && av[1][l - 2] == 'b'
			&& av[1][l - 3] == '.')
		{
			main2(av[1]);
		}
		else
			write(1, "ERROR\n", 6);
	}
	else
		write(1, "ERROR\n", 6);
	return (0);
}

void	mainhelper11(char *mappath)
{
	t_data	*data;

	data = create_window(mappath);
	data->move_count = 0;
	data->map_path = ft_strdup(mappath);
	data->count = 0;
	window_helperr(mappath, data);
}
