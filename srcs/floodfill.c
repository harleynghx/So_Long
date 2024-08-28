/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:11:43 by hang              #+#    #+#             */
/*   Updated: 2024/08/20 18:14:25 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_valid(t_data *list, int row, int col, char **map)
{
	return (row >= 0 && row < list->n_height && col >= 0 && col < list->n_width
		&& map[row][col] != '1');
}

static int	ff_iterative(t_data *list, t_point *queue, t_floodfill *ff_data)
{
	t_point	current;

	while (ff_data->track < ff_data->append)
	{
		current = queue[ff_data->track++];
		if (ff_data->map[current.y][current.x] == 'E')
			return (0);
		while (ff_data->dir < 4)
		{
			ff_data->new_y = current.y + ff_data->dir_y[ff_data->dir];
			ff_data->new_x = current.x + ff_data->dir_x[ff_data->dir];
			if (is_valid(list, ff_data->new_y, ff_data->new_x, ff_data->map))
			{
				if (ff_data->map[ff_data->new_y][ff_data->new_x] == 'E')
					return (0); // TODO
				ff_data->map[ff_data->new_y][ff_data->new_x] = '1';
				queue[ff_data->append++] = (t_point){ff_data->new_y,
					ff_data->new_x};
			}
			ff_data->dir++;
		}
		ff_data->dir = 0;
	}
	return (1);
}

int	floodfill_iterative(t_data *list)
{
	t_point		*queue;
	t_floodfill	ff_data;

	queue = (t_point *)malloc(sizeof(t_point) * (list->n_height
				* list->n_width));
	ff_data = (t_floodfill){.dir_y = {-1, 1, 0, 0}, .dir_x = {0, 0, -1, 1},
		.append = 0, .track = 0, .dir = 0, .map = list->map};
	queue[ff_data.append++] = (t_point){list->playerpos_y, list->playerpos_x};
	ff_data.map[list->playerpos_y][list->playerpos_x] = '1';
	return (ff_iterative(list, queue, &ff_data));
}
