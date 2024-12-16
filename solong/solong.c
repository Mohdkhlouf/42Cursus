
#include "solong.h"

#include <stdlib.h>
#include <string.h>

// Bytes Per Pixel. Since each pixel is represented as an integer, it will be four bytes for four channels.
#define BPP sizeof(int32_t)



static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}




int32_t	main(void)
{
	int map_width;
	int map_height;
	char **map;
	int i;
	int j;

	i = 0;
	j = 0;
	map_width = 0;
	map_height = 0;

	map = read_map(&map_width, &map_height);
	if (!map_height || !map_width)
	{
		perror("null values");
		exit(1);
	}
	j = 0;
	mlx_set_setting(MLX_MAXIMIZED, true);
    mlx_t* mlx = mlx_init(map_width * TILE_SIZE, map_height * TILE_SIZE, "MLX42", true);
    if (!mlx) exit(EXIT_FAILURE);
	
	// define a color



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
	
	mlx_texture_t* home = mlx_load_png("assets/home.png");
	if (!home)
        perror("error in loading Home image");
	
	mlx_image_t* img = mlx_texture_to_image(mlx, wall);
	if (!img)
        perror("Error in loading image");
	
	mlx_image_t* player_img = mlx_texture_to_image(mlx, player);
	if (!player_img)
        perror("Error in loading image");
	mlx_image_t* baby_img = mlx_texture_to_image(mlx, baby_boy);
	if (!baby_img)
        perror("Error in loading image");
	// create my tetures end

	while(i < map_height)
		{
			j = 0;
			while(j < map_width)
			{
				if (map[i][j] == '1')
					mlx_image_to_window(mlx, img, j*TILE_SIZE, i*TILE_SIZE);
				else if (map[i][j] == 'P')
					mlx_image_to_window(mlx, player_img, j*TILE_SIZE, i*TILE_SIZE);
				else if (map[i][j] == 'C')
					mlx_image_to_window(mlx, baby_img, j*TILE_SIZE, i*TILE_SIZE);
				j++;
			}
			i++;		
		}

	mlx_loop_hook(mlx, ft_hook, mlx);
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}
