/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainhelper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:28:23 by schaaban          #+#    #+#             */
/*   Updated: 2024/08/22 09:37:30 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	free1(char **map, char *map_path)
{
	if (!error_handling1(map, map_path))
		return (0);
	return (1);
}

int	free2(char *map_path, char **map)
{
	if (!error_handling(map, map_path))
		return (0);
	if (!error_handling_ffill(map, map_path))
		return (0);
	return (1);
}

void	window_helperr(char *map_path, t_data *data)
{
	player_position(data, map_path);
	image_to_pointer(data);
	display_image(data->map, data, map_path);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &on_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy,
		data);
	mlx_loop(data->mlx_ptr);
	free_2d_array(data->map);
	on_destroy(data);
}
