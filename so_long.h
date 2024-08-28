/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:04:26 by hang              #+#    #+#             */
/*   Updated: 2024/08/24 19:04:35 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_point
{
	int		y;
	int		x;
}			t_point;

typedef struct s_floodfill
{
	int		append;
	int		track;
	int		dir;
	int		dir_y[4];
	int		dir_x[4];
	char	**map;
	int		new_y;
	int		new_x;
}			t_floodfill;

typedef struct s_data
{
	int		fd;
	int		n_height;
	int		n_width;
	int		n_player;
	int		n_collectible;
	int		n_exit;
	int		x_axis;
	int		y_axis;
	int		steps_counter;
	int		playerpos_y;
	int		playerpos_x;
	int		c_counter;
	char	**map;
	void	*img_floor;
	void	*img_wall;
	void	*img_player;
	void	*img_exit;
	void	*img_collectible;
	void	*mlxpointer;
	void	*winpointer;

}			t_data;

int			exit_point(t_data *list);
int			map_from_file(t_data *list, char *map);
void		xpm_to_pointer(t_data *list);
void		error_checker(t_data *list);
void		load_images(t_data *list);
int			controls(int keycode, t_data *list);
int			floodfill_iterative(t_data *list);
int			valid_move(t_data *list, int x, int y);

#endif