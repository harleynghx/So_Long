#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *mlx_ptr;        // Pointer to the MLX connection
void *win_ptr;        // Pointer to the MLX window
int	width = 400;      // width of the window
int	height = 400;     // height of the window
int	square_size = 50; // size of the square

int	on_close(void *param)
{
	(void)param;
	mlx_destroy_window(mlx_ptr, win_ptr);
	exit(0);
}

int	on_key(int key, void *param)
{
	(void)param;
	if (key == 53 || key == 65307)
	{
		mlx_destroy_window(mlx_ptr, win_ptr);
		exit(0);
	}
	else
	{
		printf("key = %i\n", key);
		// exit(0);
	}
	return (0);
}

int	main(void)
{
	int	square_x;
	int	square_y;

	mlx_ptr = mlx_init();
	// initialize the connection
	win_ptr = mlx_new_window(mlx_ptr, width, height, "mlx 42");
	// create a window
	// Calculate starting coordinates for the square (centered)
	square_x = (width - square_size) / 2;
	square_y = (height - square_size) / 2;
	mlx_hook(win_ptr, 2, 1L << 0, on_key, 0);
	mlx_hook(win_ptr, 17, 0L, on_close, 0);
	int red_color = 0x00FF0000; // Red color in hex format
	// Loop through each pixel within the square and set its color to red
	for (int y = square_y; y < square_y + square_size; y++)
	{
		for (int x = square_x; x < square_x + square_size; x++)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, red_color);
			// sleep(1);
		}
	}
	// Start the event loop to keep the window open
	mlx_loop(mlx_ptr);
	return (0);
}
