/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:24:24 by schaaban          #+#    #+#             */
/*   Updated: 2024/08/22 13:16:01 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	to_fill(char **map, int i, int j)
{
	if (map[i][j] == 'E' || map[i][j] == 'P' || map[i][j] == '0'
		|| map[i][j] == 'C')
	{
		return (1);
	}
	return (0);
}

int	to_fill_without_e(char **map, int i, int j)
{
	if (map[i][j] == 'P' || map[i][j] == '0'
		|| map[i][j] == 'C')
	{
		return (1);
	}
	return (0);
}

void	fill_without_e(char **map, t_point cur, t_count *p)
{
	if (!to_fill_without_e(map, cur.x, cur.y))
		return ;
	if (map[cur.x][cur.y] == 'C')
		p->c++;
	map[cur.x][cur.y] = 'F';
	fill_without_e(map, (t_point){cur.x - 1, cur.y}, p);
	fill_without_e(map, (t_point){cur.x + 1, cur.y}, p);
	fill_without_e(map, (t_point){cur.x, cur.y - 1}, p);
	fill_without_e(map, (t_point){cur.x, cur.y + 1}, p);
}

void	fill(char **map, t_point cur, t_count *p)
{
	if (!to_fill(map, cur.x, cur.y))
		return ;
	if (map[cur.x][cur.y] == 'E')
		p->e++;
	map[cur.x][cur.y] = 'F';
	fill(map, (t_point){cur.x - 1, cur.y}, p);
	fill(map, (t_point){cur.x + 1, cur.y}, p);
	fill(map, (t_point){cur.x, cur.y - 1}, p);
	fill(map, (t_point){cur.x, cur.y + 1}, p);
}

void	flood_fill_without_e(char **tab, t_point begin, t_count *p)
{
	fill_without_e(tab, begin, p);
}
