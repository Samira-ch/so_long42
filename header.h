/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:26:54 by schaaban          #+#    #+#             */
/*   Updated: 2024/08/22 13:53:22 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include "mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;
typedef struct s_count
{
	int		e;
	int		c;
}			t_count;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*walls;
	void	*background;
	void	*cat;
	void	*fish;
	void	*door;
	char	**map;
	int		i;
	int		j;
	int		count;
	char	*map_path;
	int		move_count;
}			t_data;

char		**ft_split(char const *s, char c);
char		*get_next_line(int fd);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
int			on_keypress(int keysym, t_data *data);
int			open_map(const char *file_path);
char		*fill_array(char *mappath);
char		**array2d(char *map_path);
void		free_2d_array(char **array);
int			line_size(char **map, int j);
int			count_lines(char *map_path);
int			check_all_lines(char **map, char *map_path);
int			check_p_and_e(char **map, char *map_path);
int			check_c(char **map, char *map_path);
int			check_count_c(char **map, char *map_path);
int			to_fill(char **map, int i, int j);
void		fill(char **map, t_point cur, t_count *p);
void		flood_fill(char **tab, t_point begin, t_count *p);
void		player_position(t_data *data, char *map_path);
t_point		player_position1(char *map_path);
int			check_map_borders(char **map, char *map_path);
int			error_handling(char **map, char *map_path);
int			error_handling1(char **map, char *map_path);
int			error_handling_ffill(char **map, char *map_path);
int			on_destroy(t_data *data);
int			check_chars(char **map);
void		display_image(char **map, t_data *image, char *map_path);
t_data		*create_window(char *map_path);
void		image_to_pointer(t_data *image);
char		*ft_strdup(const char *s1);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		on_keypress1(int keysym, t_data *data, char **map);
void		on_keypress2(int keysym, t_data *data, char **map);
void		on_keypress3(int keysym, t_data *data, char **map);
void		on_keypress4(int keysym, t_data *data, char **map);
int			free1(char **map, char *map_path);
int			free2(char *map_path, char **map);
void		window_helperr(char *map_path, t_data *data);
void		wfree(t_data *data, char **map);
void		mainhelper11(char *mappath);
void		display_image_1(char **map, t_data *image, int i, int j);
int			ft_putchar(char c);
int			ft_putnbr(int n);
int			ft_putstr(char *str);
int			ft_putnbr_unsignedint(unsigned int n);
int			ft_printf(char const *str, ...);
int			ft_put_hexadecimal(unsigned int i, char c);
int			ft_hexadecimal_pointer(long unsigned int i);
void		main2(char *s);
void		free_when_empty_lines(char *line, char *temp, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		fill_without_e(char **map, t_point cur, t_count *p);
int			to_fill_without_e(char **map, int i, int j);
void		flood_fill_without_e(char **tab, t_point begin,
				t_count *p);
int			ffill_helper(char **map, char **map1);
#endif