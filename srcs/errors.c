/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:51:13 by hang              #+#    #+#             */
/*   Updated: 2024/07/23 15:56:46 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// TODO check if the map is a square, mine only checks if is surrounded by walls, if is surround by double walls it will pass

static void	surround_is_walls(data *list)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < list->n_height)
	{
		if (list->map[y][0] != '1' && list->map[y][list->n_width - 1] != '1')
		{
			perror("Error: Game must be surrounded by walls!");
			exit_point(list);
		}
		y++;
	}
	while (x < list->n_width)
	{
		if (list->map[0][x] != '1' && list->map[list->n_height - 1][x] != '1')
		{
			perror("Error: Game must be surrounded by walls!");
			exit_point(list);
		}
		x++;
	}
}

static void	validate_and_count_characters(data *list, int height, int width)
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
		// TODO perror("Invalid format: ")
		exit_point(list);
	}
}

void	validate_map_characters(data *list)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (y <= list->n_height - 2)
	{
		while (x <= list->n_width - 2)
		{
			validate_and_count_characters(list, y, x);
			x++;
		}
	}
	y++;
	if (list->n_player != 1 || list->n_collectible <= 1 || list->n_exit != 1)
	{
		perror("The Numbers of player or exit must be == 1");
        perror("THe Number of collectibles must be greater then 0");
		exit_point(list);
	}
}

void	error_checker(data *list)
{
	surround_is_walls(list);
	validate_map_characters(list);
    // TODO valid_path(&list);
}