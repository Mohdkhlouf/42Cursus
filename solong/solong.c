
#include "solong.h"

#include <stdlib.h>
#include <string.h>

// Bytes Per Pixel. Since each pixel is represented as an integer, it will be four bytes for four channels.
#define BPP sizeof(int32_t)



void my_keyhook(mlx_key_data_t keydata, void* param)
{
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	// if (mlx_is_key_down(param, MLX_KEY_UP))
	// 	g_img->instances[0].y -= 5;
	// if (mlx_is_key_down(param, MLX_KEY_DOWN))
	// 	g_img->instances[0].y += 5;
	// if (mlx_is_key_down(param, MLX_KEY_LEFT))
	// 	g_img->instances[0].x -= 5;
	// if (mlx_is_key_down(param, MLX_KEY_RIGHT))
	// 	g_img->instances[0].x += 5;
}


int32_t	main(void)
{
	int fd;
	int map_width;
	int map_height;
	char *map;

	fd = 0;
	map_width = 0;
	map_height = 0;
	fd = open("map.ber", O_RDONLY);
	if (fd == -1) {
        perror("Error opening file");
    }
	map = read_map(fd, &map_width, &map_height);
	if (!map_height || !map_width)
	{
		perror("null values");
		exit(1);
	}
    // Init mlx with a canvas size of 256x256 and the ability to resize the window.
    mlx_t* mlx = mlx_init(map_width * TILE_SIZE, map_height * TILE_SIZE, "MLX42", true);
    if (!mlx) exit(EXIT_FAILURE);


	// create my tetures start
	mlx_texture_t* baby_boy = mlx_load_png("assets/babyboy.png");
	if (!baby_boy)
        perror("error in loading Baby boy image");
	
	mlx_texture_t* player = mlx_load_png("assets/player.png");
	if (!player)
        perror("error in loading Player image");
	
	mlx_texture_t* wall = mlx_load_png("assets/wall.png");
	if (!wall)
        perror("error in loading wall image");
	
	// mlx_texture_t* ground = mlx_load_png("assets/ground.png");
	// if (!ground)
    //     perror("error in loading ground image");

	mlx_texture_t* home = mlx_load_png("assets/home.png");
	if (!home)
        perror("error in loading Home image");
	
	mlx_image_t* img = mlx_texture_to_image(mlx, wall);
	if (!img)
        perror("Error in loading image");
	// create my tetures end

    // Draw the image at coordinate (0, 0).


    mlx_image_to_window(mlx, img, 0*TILE_SIZE, 0*TILE_SIZE);
	mlx_image_to_window(mlx, img, 1*TILE_SIZE, 0*TILE_SIZE);


    // Run the main loop and terminate on quit.  
	mlx_key_hook(mlx, &my_keyhook, NULL);
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}
