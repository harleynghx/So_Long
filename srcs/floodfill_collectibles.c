/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_collectibles.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 23:00:18 by hang              #+#    #+#             */
/*   Updated: 2024/10/30 21:48:43 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_valid_c(t_data *list, int row, int col, char **map)
{
	return (row >= 0 && row < list->n_height && col >= 0 && col < list->n_width
		&& map[row][col] != '1' && map[row][col] != 'v'
		&& map[row][col] != 'E');
}

static int	collectibles_iterative(t_data *list, t_point_c *queue,
		t_floodfill_c *ffc_d)
{
	t_point_c	current;

	while (ffc_d->track < ffc_d->append)
	{
		current = queue[ffc_d->track++];
		while (ffc_d->dir < 4)
		{
			ffc_d->new_y = current.y
				+ ffc_d->dir_y[ffc_d->dir];
			ffc_d->new_x = current.x
				+ ffc_d->dir_x[ffc_d->dir];
			if (is_valid_c(list, ffc_d->new_y,
					ffc_d->new_x, list->floodfill_map))
			{
				if (list->floodfill_map[ffc_d->new_y][ffc_d->new_x] == 'C')
					list->n_collectibles_found++;
				list->floodfill_map[ffc_d->new_y][ffc_d->new_x] = 'v';
				queue[ffc_d->append++] = (t_point_c){ffc_d->new_y,
					ffc_d->new_x};
			}
			ffc_d->dir++;
		}
		ffc_d->dir = 0;
	}
	return (list->n_collectibles_found);
}

int	floodfill_collectibles(t_data *list)
{
	t_point_c		*queue;
	t_floodfill_c	floodfill_data_c;
	id_t			result;

	queue = (t_point_c *)malloc(sizeof(t_point_c) * (list->n_height
				* list->n_width));
	floodfill_data_c = (t_floodfill_c){.dir_y = {-1, 1, 0, 0}, .dir_x = {0, 0,
		-1, 1}, .append = 0, .track = 0, .dir = 0};
	queue[floodfill_data_c.append++] = (t_point_c){list->playerpos_y,
		list->playerpos_x};
	list->floodfill_map[list->playerpos_y][list->playerpos_x] = 'v';
	result = collectibles_iterative(list, queue, &floodfill_data_c);
	return (result);
}
