/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:35:31 by hang              #+#    #+#             */
/*   Updated: 2024/08/28 17:48:18 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	append_line_to_map(t_data *list, char *row)
{
	int		i;
	char	**temp;

	list->n_height++;
	i = 0;
	if (!row)
		return (0);
	temp = malloc(sizeof(char *) * (list->n_height + 1));
	temp[list->n_height] = NULL;
	while (i < list->n_height - 1)
	{
		temp[i] = list->map[i];
		temp[i] = list->floodfill_map[i];
		i++;
	}
	if (list->map)
		free(list->map);
	temp[i] = row;
	list->map = temp;
	return (1);
}

static int	width_counter(t_data *list)
{
	size_t	width;

	width = 0;
	while (list->map[0][width])
		width++;
	if (list->map[0][width - 1] == '\n')
		width--;
	return (width);
}

int	map_from_file(t_data *list, char *map)
{
	char	*str;

	list->fd = open(map, O_RDONLY);
	if (list->fd < 0)
	{
		perror("Invalid fd");
		return (0);
	}
	while (1)
	{
		str = get_next_line(list->fd);
		if (!append_line_to_map(list, str))
			break ;
	}
	close(list->fd);
	list->n_height--;
	list->n_width = width_counter(list);
	return (1);
}
