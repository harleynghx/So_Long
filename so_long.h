#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct t_database
{
	int		fd;
	int		n_height;
	int		n_width;
	int		n_player;
	int		n_collectible;
	int		n_exit;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectables;
	int		playerpos_y;
	int		playerpos_x;

	char	**map;


	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;

}			data;

int			map_from_file(data *list, char *map);
void		error_checker(data *list);
int			exit_point(data *list);

#endif