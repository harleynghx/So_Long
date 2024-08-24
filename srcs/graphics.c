/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:44:16 by hang              #+#    #+#             */
/*   Updated: 2024/08/19 13:36:47 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	put_image(t_data *list, int x, int y)
{
	if (list->map[y][x] == '1')
		mlx_put_image_to_window(list->mlxpointer, list->winpointer,
			list->img_wall, x * 85, y * 85);
	if (list->map[y][x] == '0')
		mlx_put_image_to_window(list->mlxpointer, list->winpointer,
			list->img_floor, x * 85, y * 85);
	if (list->map[y][x] == 'E')
		mlx_put_image_to_window(list->mlxpointer, list->winpointer,
			list->img_exit, x * 85, y * 85);
	if (list->map[y][x] == 'C')
		mlx_put_image_to_window(list->mlxpointer, list->winpointer,
			list->img_collectible, x * 85, y * 85);
}

void	load_images(t_data *list)
{
	int			y;
	int			x;
	const char	*valid_chars;

	y = 0;
	while (y < list->n_height)
	{
		x = 0;
		while (x < list->n_width)
		{
			valid_chars = "10PEC";
			if (ft_strchr(valid_chars, list->map[y][x]))
			{
				if (list->map[y][x] == 'P')
					mlx_put_image_to_window(list->mlxpointer, list->winpointer,
						list->img_player, x * 85, y * 85);
				else
					put_image(list, x, y);
			}
			x++;
		}
		y++;
	}
}

void	xpm_to_pointer(t_data *list)
{
	int i;
	int x;
	list->img_wall = mlx_xpm_file_to_image(list->mlxpointer, "images/wall.xpm",
			&i, &x);
	list->img_floor = mlx_xpm_file_to_image(list->mlxpointer,
			"images/floor.xpm", &i, &x);
	list->img_player = mlx_xpm_file_to_image(list->mlxpointer,
			"images/player.xpm", &i, &x);
	list->img_collectible = mlx_xpm_file_to_image(list->mlxpointer,
			"images/collectible.xpm", &i, &x);
	list->img_exit = mlx_xpm_file_to_image(list->mlxpointer, "images/exit.xpm",
			&i, &x);
}
