/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:05:40 by hang              #+#    #+#             */
/*   Updated: 2024/07/19 22:11:38 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	exit_point(data *list)
{
	int i;

    if (list->mlxpointer)
        mlx_destroy_window(list->mlxpointer, list->winpointer);
    free(list->mlxpointer);
    i = 0;
    while (i < list->n_height)
        free(list->map[i++]);
    free(list->map);
    exit(0);
}

int	main(int ac, char **av)
{
	data	list;

	if (ac != 2)
		return (0);
	ft_memset(&list, 0, sizeof(data));
	map_from_file(&list, av[1]);
	error_checker(&list);
    list.mlxpointer = mlx_init();
    list.winpointer = mlx_new_window(list.mlxpointer, (list.n_width * 100), (list.n_height * 100), "solong");
    mlx_loop(list.mlxpointer);
}
