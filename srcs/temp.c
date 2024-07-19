/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:13:06 by hang              #+#    #+#             */
/*   Updated: 2024/07/16 19:13:07 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static int vertical_wall(data list)
{
    int y;

    y = 0;
    while (y < list.n_height)
    {
        if (list.map[y][0] != '1' && list.map[y][list.n_width - 1] != '1')
            return (0);
        y++:
    }
    return (1);
}

static int horizontal_wall(data list)
{
    int x;

    x = 0;
    while (x < list.n_width)
    {
        if (list.map[0][x] != '1' && list.map[list.n_height - 1][x] != '1')
            return (0);
        x++;
    }
    return (1);
}

static int surround_is_walls(data *list)
{
    if (vertical_wall(list) == 0 || horizontal_wall(list) == 0)
    {
        perror("error: Game must be surrounded by walls!")
        //TODO exit_point(&list);
    }
}
