/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:35:31 by hang              #+#    #+#             */
/*   Updated: 2024/09/02 17:45:21 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void ft_freemap(t_data *list)
{
	if(list->map)
		free(list->map);
	if(list->floodfill_map)
		free(list->floodfill_map);
	return;
}
static int	append_line_to_map(t_data *list, char *row)
{
	int		i;
	char	**temp;
	char	**temp2;

	list->n_height++;
	i = 0;
	if (!row)
		return (0);
	temp = malloc(sizeof(char *) * (list->n_height + 1));
	temp2 = malloc(sizeof(char *) * (list->n_height + 1));
	temp[list->n_height] = NULL;
	temp2[list->n_height] = NULL;
	while (i < list->n_height - 1)
	{
		temp[i] = list->map[i];
		temp2[i] = list->floodfill_map[i];
		i++;
	}
	ft_freemap(list);
	temp[i] = row;
	temp2[i] = ft_strdup(row);
	list->map = temp;
	list->floodfill_map = temp2;
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
		exit_point(list);
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
void	map_is_rectangle(t_data *list)
{
    int i;
	
    i = 1;
    while (i < list->n_height)
    {
        int row_width = 0;
        while (list->map[i][row_width])
            row_width++;
        if (list->map[i][row_width - 1] == '\n')
            row_width--;
        if (row_width != list->n_width)
		{
			ft_printf("Invalid Game: Map is not rectangle!\n");
            exit_point(list);
		}
        i++;
    }
    return ;
}
