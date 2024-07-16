/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:51:13 by hang              #+#    #+#             */
/*   Updated: 2024/07/16 16:05:08 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void surround_is_walls(data *list)
{
    int y;
    int x;

    y = 0;
    x = 0;
    while (y < list.n_height)
    {
        if (list.map[y][0] != '1' && list.map[y][list.n_width - 1] != '1')
        {
            perror("Error: Game must be surrounded by walls!");
            exit_point();
        }
        y++:
    }
    while (x < list.n_width)
    {
        if (list.map[0][x] != '1' && list.map[list.n_height - 1][x] != '1')
        {
            perror("Error: Game must be surrounded by walls!");
            exit_point();
        }
        x++;
    }
}

void error_checker(data *list)
{
    surround_is_walls(&list);
    
    
}