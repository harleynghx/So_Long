#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
void *mlx_ptr;  // Pointer to the MLX connection
void *win_ptr;  // Pointer to the MLX window
int width = 400; //width of the window
int height = 400; //height of the window
int square_size = 50; //size of the square 

int main(void) {
    mlx_ptr = mlx_init(); //initialize the connection
    win_ptr = mlx_new_window(mlx_ptr, width, height, "mlx 42"); //create a window
    // Calculate starting coordinates for the square (centered)


    int square_x = (width - square_size) / 2;
    int square_y = (height - square_size) / 2;


    int red_color = 0x00FF0000; // Red color in hex format
    // Loop through each pixel within the square and set its color to red
    for (int y = square_y; y < square_y + square_size; y++) {
      for (int x = square_x; x < square_x + square_size; x++) {
        mlx_pixel_put(mlx_ptr, win_ptr, x, y, red_color);
        sleep(1);
      }
    }
    // Start the event loop to keep the window open
    mlx_loop(mlx_ptr);



    return 0;
}
