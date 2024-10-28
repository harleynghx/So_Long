/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:51:13 by hang              #+#    #+#             */
/*   Updated: 2024/09/17 10:49:28 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	valid_move(t_data *list, int x, int y)
{
	if (list->map[y][x] == 'E')
	{
		if (list->c_counter < list->n_collectible)
			return (0);
		ft_printf("You Have Won, Congrats!\n");
		exit_point(list);
	}
	if (list->map[y][x] == '0')
	{
		list->map[y][x] = 'P';
		list->playerpos_x = x;
		list->playerpos_y = y;
		list->steps_counter++;
	}
	if (list->map[y][x] == 'C')
	{
		list->map[y][x] = 'P';
		list->playerpos_x = x;
		list->playerpos_y = y;
		list->steps_counter++;
		list->c_counter++;
	}
	ft_printf("%i steps taken\n", list->steps_counter);
	return (1);
}

static void	surround_is_walls(t_data *list)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < list->n_height - 1)
	{
		if (list->map[y][0] != '1' || list->map[y][list->n_width - 1] != '1')
		{
			ft_printf("Invalid Map: Game must be surrounded by walls!\n");
			exit_point(list);
		}
		y++;
	}
	while (x < list->n_width)
	{
		if (list->map[0][x] != '1' || list->map[list->n_height - 1][x] != '1')
		{
			ft_printf("Invalid Map: Game must be surrounded by walls!\n");
			exit_point(list);
		}
		x++;
	}
}

static void	validate_and_count_characters(t_data *list, int height, int width)
{
	const char	*valid_chars;

	valid_chars = "10PEC\n";
	if (ft_strchr(valid_chars, list->map[height][width]))
	{
		if (list->map[height][width] == 'C')
			list->n_collectible++;
		else if (list->map[height][width] == 'E')
			list->n_exit++;
		else if (list->map[height][width] == 'P')
		{
			list->n_player++;
			list->playerpos_y = height;
			list->playerpos_x = width;
		}
	}
	else
	{
		ft_printf("Error: Unknown character!\n");
		exit_point(list);
	}
}

static void	validate_map_characters(t_data *list)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (y <= list->n_height - 1)
	{
		x = 1;
		while (x <= list->n_width - 1)
		{
			validate_and_count_characters(list, y, x);
			x++;
		}
		y++;
	}
	if (list->n_player != 1 || list->n_collectible <= 0 || list->n_exit != 1)
	{
		ft_printf("Invalid Game: The Number of player or exit must be == 1\n");
		ft_printf("Invalid Gmae: The Number of collectibles must be >= 1\n");
		exit_point(list);
	}
}

void	error_checker(t_data *list)
{
	surround_is_walls(list);
	validate_map_characters(list);
	map_is_rectangle(list);
	if (floodfill_collectibles(list) != list->n_collectible)
	{
		ft_printf("Invalid Game: One or more Collectibles are not reachable!\n");
		exit_point(list);
	}
	if (floodfill_iterative(list) == 0)
	{
		ft_printf("Invalid Game: Exit not reachable!\n");
		exit_point(list);
	}
}
