/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_collectibles.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 23:00:18 by hang              #+#    #+#             */
/*   Updated: 2024/08/30 00:16:33 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


static int	is_valid_c(t_data *list, int row, int col, char **map)
{
	return (row >= 0 && row < list->n_height && col >= 0 && col < list->n_width
		&& map[row][col] != '1' && map[row][col] != 'v' && map[row][col] != 'E');
}

static int	collectibles_iterative(t_data *list, t_point_c *queue, t_floodfill_c *floodfill_data_c)
{
	t_point_c	current;

	while (floodfill_data_c->track < floodfill_data_c->append)
	{
		current = queue[floodfill_data_c->track++];
        
		while (floodfill_data_c->dir < 4)
		{
			floodfill_data_c->new_y = current.y + floodfill_data_c->dir_y[floodfill_data_c->dir];
			floodfill_data_c->new_x = current.x + floodfill_data_c->dir_x[floodfill_data_c->dir];
			if (is_valid_c(list, floodfill_data_c->new_y, floodfill_data_c->new_x, list->floodfill_map))
			{
				if (list->floodfill_map[floodfill_data_c->new_y][floodfill_data_c->new_x] == 'C')
                    list->n_collectibles_found++;
				list->floodfill_map[floodfill_data_c->new_y][floodfill_data_c->new_x] = 'v';
				queue[floodfill_data_c->append++] = (t_point_c){floodfill_data_c->new_y,
					floodfill_data_c->new_x};
			}
			floodfill_data_c->dir++;
		}
		floodfill_data_c->dir = 0;
	}
	return (list->n_collectibles_found);
}

int	floodfill_collectibles(t_data *list)
{
	t_point_c		*queue;
	t_floodfill_c	floodfill_data_c;

	queue = (t_point_c *)malloc(sizeof(t_point_c) * (list->n_height
				* list->n_width));
	floodfill_data_c = (t_floodfill_c){.dir_y = {-1, 1, 0, 0}, .dir_x = {0, 0, -1, 1},
		.append = 0, .track = 0, .dir = 0};
	queue[floodfill_data_c.append++] = (t_point_c){list->playerpos_y, list->playerpos_x};
	list->floodfill_map[list->playerpos_y][list->playerpos_x] = 'v';
	return (collectibles_iterative(list, queue, &floodfill_data_c));
}
