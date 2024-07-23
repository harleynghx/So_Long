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
	int		steps_counter;
	int		playerpos_y;
	int		playerpos_x;
	int		c_counter;

	char	**map;

	void	*img_floor;
	void	*img_wall;
	void	*img_player;
	void	*img_exit;
	void	*img_collectable;
	void	*mlxpointer;
	void	*winpointer;

}			data;

int			exit_point(data *list);
int			map_from_file(data *list, char *map);
void		xpm_to_pointer(data *list);
void		error_checker(data *list);
void		load_images(data *list);
int    		controls(int keycode, data *list);

#endif