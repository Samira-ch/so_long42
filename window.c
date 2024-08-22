/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:29:22 by schaaban          #+#    #+#             */
/*   Updated: 2024/08/22 10:30:45 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	on_destroy(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->door);
	mlx_destroy_image(data->mlx_ptr, data->cat);
	mlx_destroy_image(data->mlx_ptr, data->fish);
	mlx_destroy_image(data->mlx_ptr, data->background);
	mlx_destroy_image(data->mlx_ptr, data->walls);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_2d_array(data->map);
	free(data->mlx_ptr);
	free(data->map_path);
	free(data);
	exit(0);
	return (0);
}

void	display_image(char **map, t_data *image, char *map_path)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count_lines(map_path))
	{
		j = 0;
		while (j < line_size(map, 0))
		{
			display_image_1(map, image, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(image->mlx_ptr, image->win_ptr, image->cat, image->i
		* 40, image->j * 40);
}

void	display_image_1(char **map, t_data *image, int i, int j)
{
	if (map[i][j] == '0' || map[i][j] == 'P')
		mlx_put_image_to_window(image->mlx_ptr, image->win_ptr,
			image->background, j * 40, i * 40);
	else if (map[i][j] == '1')
		mlx_put_image_to_window(image->mlx_ptr, image->win_ptr, image->walls, j
			* 40, i * 40);
	else if (map[i][j] == 'C')
		mlx_put_image_to_window(image->mlx_ptr, image->win_ptr, image->fish, j
			* 40, i * 40);
	else if (map[i][j] == 'E')
		mlx_put_image_to_window(image->mlx_ptr, image->win_ptr, image->door, j
			* 40, i * 40);
}

t_data	*create_window(char *map_path)
{
	t_data	*data;
	char	**map;

	map = array2d(map_path);
	data = (t_data *)malloc(sizeof(t_data));
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 40 * line_size(map, 0),
			count_lines(map_path) * 40, ":)");
	data->map = map;
	return (data);
}

void	image_to_pointer(t_data *image)
{
	int	i;
	int	j;

	image->walls = mlx_xpm_file_to_image(image->mlx_ptr,
			"textures/walls.xpm", &i, &j);
	image->background = mlx_xpm_file_to_image(image->mlx_ptr,
			"textures/background.xpm", &i, &j);
	image->cat = mlx_xpm_file_to_image(image->mlx_ptr,
			"textures/cat.xpm", &i, &j);
	image->fish = mlx_xpm_file_to_image(image->mlx_ptr,
			"textures/fish.xpm", &i, &j);
	image->door = mlx_xpm_file_to_image(image->mlx_ptr,
			"textures/door.xpm", &i, &j);
}
