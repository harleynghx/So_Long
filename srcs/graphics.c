/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:44:16 by hang              #+#    #+#             */
/*   Updated: 2024/07/21 23:30:20 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	put_image(data *list, int x, int y)
{
	if (list->map[y][x] == '1')
		mlx_put_image_to_window(list->mlxpointer, list->winpointer,
			list->img_wall, x * 85, y * 85);
	else if (list->map[y][x] == '0')
		mlx_put_image_to_window(list->mlxpointer, list->winpointer,
			list->img_floor, x * 85, y * 85);
	else if (list->map[y][x] == 'E')
		mlx_put_image_to_window(list->mlxpointer, list->winpointer,
			list->img_exit, x * 85, y * 85);
	else if (list->map[y][x] == 'C')
		mlx_put_image_to_window(list->mlxpointer, list->winpointer,
			list->img_collectable, x * 85, y * 85);
}

void	load_images(data *list)
{
	int			y;
	int			x;
	const char	*valid_chars;

	y = 0;
	while (y < list->n_height - 1)
	{
		x = 0;
		while (x < list->n_width - 1)
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
		}
		x++;
	}
	y++;
}

void	xpm_to_pointer(data *list)
{
	list->img_wall = mlx_xpm_file_to_image(list->mlxpointer, "iamges/wall.xpm",
			0, 0);
	list->img_floor = mlx_xpm_file_to_image(list->mlxpointer,
			"images/floor.xpm", 0, 0);
	list->img_player = mlx_xpm_file_to_image(list->mlxpointer,
			"images/player.xpm", 0, 0);
	list->img_collectable = mlx_xpm_file_to_image(list->mlxpointer,
			"images/collectible", 0, 0);
	list->img_exit = mlx_xpm_file_to_image(list->mlxpointer, "images/exit.xpm",
			0, 0);
}
