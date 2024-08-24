/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:05:40 by hang              #+#    #+#             */
/*   Updated: 2024/08/19 13:36:59 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	exit_point(t_data *list)
{
	int	i;

	i = 0;
	if (list->mlxpointer)
		mlx_destroy_window(list->mlxpointer, list->winpointer);
	free(list->mlxpointer);
	while (i < list->n_height)
		free(list->map[i++]);
	free(list->map);
	ft_printf("Exit Successful!\n");
	exit(0);
}

int	main(int ac, char **av)
{
	t_data	list;
	if (ac != 2)
	{
		perror("Invalid Args");
		return (0);
	}
	ft_memset(&list, 0, sizeof(t_data));
	map_from_file(&list, av[1]);
	error_checker(&list);
	list.mlxpointer = mlx_init();
	list.winpointer = mlx_new_window(list.mlxpointer, (list.n_width * 85),
			(list.n_height * 85), "cat and donuts");
	xpm_to_pointer(&list);
	load_images(&list);
	mlx_key_hook(list.winpointer, controls, &list);
	mlx_hook(list.winpointer, 17, 0, (void *)exit, 0);
	mlx_loop(list.mlxpointer);
}
