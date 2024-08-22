/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:27:08 by schaaban          #+#    #+#             */
/*   Updated: 2024/08/22 11:16:40 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	on_keypress1(int keysym, t_data *data, char **map)
{
	if (keysym == 119)
	{
		if (data->j > 0 && (data->map[data->j - 1][data->i] != '1'
			&& data->map[data->j - 1][data->i] != 'E'))
		{
			if (data->map[data->j - 1][data->i] == 'C')
			{
				data->map[data->j - 1][data->i] = '0';
				data->j = data->j - 1;
				data->count++;
			}
			else
				data->j = data->j - 1;
			display_image(data->map, data, data->map_path);
			data->move_count++;
			ft_printf("%d\n", data->move_count);
		}
		else if (data->map[data->j - 1][data->i] == 'E')
		{
			if (check_count_c(map, data->map_path) == data->count)
				wfree(data, map);
		}
	}
}

void	on_keypress2(int keysym, t_data *data, char **map)
{
	if (keysym == 97)
	{
		if (data->i > 0 && (data->map[data->j][data->i - 1] != '1'
			&& data->map[data->j][data->i - 1] != 'E'))
		{
			if (data->map[data->j][data->i - 1] == 'C')
			{
				data->map[data->j][data->i - 1] = '0';
				data->i = data->i - 1;
				data->count++;
			}
			else
				data->i = data->i - 1;
			display_image(data->map, data, data->map_path);
			data->move_count++;
			ft_printf("%d\n", data->move_count);
		}
		else if (data->map[data->j][data->i - 1] == 'E')
		{
			if (check_count_c(map, data->map_path) == data->count)
				wfree(data, map);
		}
	}
}

void	on_keypress3(int keysym, t_data *data, char **map)
{
	if (keysym == 115)
	{
		if (data->j < (count_lines(data->map_path) - 1)
			&& (data->map[data->j +1][data->i] != '1'
			&& data->map[data->j + 1][data->i] != 'E'))
		{
			if (data->map[data->j + 1][data->i] == 'C')
			{
				data->map[data->j + 1][data->i] = '0';
				data->j = data->j + 1;
				data->count++;
			}
			else
				data->j = data->j + 1;
			display_image(data->map, data, data->map_path);
			data->move_count++;
			ft_printf("%d\n", data->move_count);
		}
		else if (data->map[data->j + 1][data->i] == 'E')
		{
			if (check_count_c(map, data->map_path) == data->count)
				wfree(data, map);
		}
	}
}

void	on_keypress4(int keysym, t_data *data, char **map)
{
	if (keysym == 100)
	{
		if (data->i < line_size(data->map, 0) && (data->map[data->j][data->i
				+ 1] != '1' && data->map[data->j][data->i + 1] != 'E'))
		{
			if (data->map[data->j][data->i + 1] == 'C')
			{
				data->map[data->j][data->i + 1] = '0';
				data->i = data->i + 1;
				data->count++;
			}
			else
				data->i = data->i + 1;
			display_image(data->map, data, data->map_path);
			data->move_count++;
			ft_printf("%d\n", data->move_count);
		}
		else if (data->map[data->j][data->i + 1] == 'E')
		{
			if (check_count_c(map, data->map_path) == data->count)
				wfree(data, map);
		}
	}
}

int	on_keypress(int keysym, t_data *data)
{
	char	**map;

	(void)data;
	map = array2d(data->map_path);
	if (keysym == 65307)
	{
		free_2d_array(map);
		on_destroy(data);
		exit(0);
	}
	else if (keysym == 119)
		on_keypress1(keysym, data, map);
	else if (keysym == 97)
		on_keypress2(keysym, data, map);
	else if (keysym == 115)
		on_keypress3(keysym, data, map);
	else if (keysym == 100)
		on_keypress4(keysym, data, map);
	free_2d_array(map);
	return (0);
}
