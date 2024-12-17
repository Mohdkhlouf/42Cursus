
#include "solong.h"

#include <stdlib.h>
#include <string.h>


void move_player(int x, int y, struct player *player1)
{
	int player_place_x = player1->img->instances->x/TILE_SIZE;
	int player_place_y = player1->img->instances->y/TILE_SIZE;
	
	int new_location_x = player_place_x + x;
	int new_location_y = player_place_y + y;
	
	if (player1->map[new_location_y][new_location_x] == '0')
	{
		puts("allow");
		player1->img->instances->x = new_location_x*TILE_SIZE;
		player1->img->instances->y = new_location_y*TILE_SIZE;
	}
	else if (player1->map[new_location_y][new_location_x] == 'C')
	{
		puts("BABY");
		player1->img->instances->x = new_location_x*TILE_SIZE;
		player1->img->instances->y = new_location_y*TILE_SIZE;
	}
	else if (player1->map[new_location_y][new_location_x] == 'P')
	{
		puts("Player Spot");
		player1->img->instances->x = new_location_x*TILE_SIZE;
		player1->img->instances->y = new_location_y*TILE_SIZE;
	}
	else if (player1->map[new_location_y][new_location_x] == 'E')
		exit(0);
	else
	{
		puts("Not Allowed WALL");
	}

}
void handle_keys(mlx_key_data_t keydata, void* param)
{
    // (void)param; // Unused parameter
    struct player *player1 = (struct player *)param;
	
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
    {
        printf("ESC\n");
		exit(0);
    }
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
        move_player(0, -1, player1);
	if (keydata.key == MLX_KEY_DOWN&& keydata.action == MLX_PRESS)
		move_player(0, +1, player1);
	if (keydata.key == MLX_KEY_RIGHT&& keydata.action == MLX_PRESS)
		move_player(+1, 0, player1);
	if (keydata.key == MLX_KEY_LEFT&& keydata.action == MLX_PRESS)
        move_player(-1, 0, player1);;
}

void my_resize_hook(int32_t width, int32_t height, void* param)
{
    printf("Window resized to: %dx%d\n", width, height);
}


int32_t	main(void)
{
	int map_width;
	int map_height;
	char **map;
	int i;
	int j;
	struct player player1;

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
	player1.map = map;
	player1.map_width = map_width;
	player1.map_height = map_height;
	j = 0;
    mlx_t* mlx = mlx_init(map_width * TILE_SIZE, map_height * TILE_SIZE, "MLX42", true);
    if (!mlx) exit(EXIT_FAILURE);
	// create my tetures start
	mlx_texture_t* baby_boy = mlx_load_png("assets/babyboy.png");
	if (!baby_boy)
        perror("error in loading Baby boy image");	
	mlx_texture_t* wall = mlx_load_png("assets/wall.png");
	if (!wall)
        perror("error in loading wall image");
	
	mlx_texture_t* home = mlx_load_png("assets/home.png");
	if (!home)
        perror("error in loading Home image");
	mlx_texture_t* ground = mlx_load_png("assets/ground.png");
	if (!home)
        perror("error in loading Ground image");
	mlx_texture_t* player = mlx_load_png("assets/player.png");
	if (!player)
        perror("error in loading Player image");


	mlx_image_t* wall_img = mlx_texture_to_image(mlx, wall);
	if (!wall_img)
        perror("Error in loading image");
	mlx_image_t* ground_img = mlx_texture_to_image(mlx, ground);
	if (!wall_img)
        perror("Error in loading image");
	mlx_image_t* home_img = mlx_texture_to_image(mlx, home);
	if (!home_img)
        perror("Error in loading image");	
	mlx_image_t* baby_img = mlx_texture_to_image(mlx, baby_boy);
	if (!baby_img)
        perror("Error in loading image");
	mlx_image_t* player_img = mlx_texture_to_image(mlx, player);
	if (!player_img)
        perror("Error in loading image");
	player1.img = player_img;
	// create my tetures end

	while(i < map_height)
		{
			j = 0;
			while(j < map_width)
			{
				
				if (map[i][j] == '0')
					mlx_image_to_window(mlx, ground_img, j*TILE_SIZE, i*TILE_SIZE);
				if (map[i][j] == '1')
					mlx_image_to_window(mlx, wall_img, j*TILE_SIZE, i*TILE_SIZE);
				if (map[i][j] == 'C')
					mlx_image_to_window(mlx, baby_img, j*TILE_SIZE, i*TILE_SIZE);
				if (map[i][j] == 'E')
					mlx_image_to_window(mlx, home_img, j*TILE_SIZE, i*TILE_SIZE);
				j++;
			}
			i++;		
		}
	i =0;
	while(i < map_height)
		{
			j = 0;
			while(j < map_width)
			{
				if (map[i][j] == 'P')
					mlx_image_to_window(mlx, player1.img, j*TILE_SIZE, i*TILE_SIZE);
				j++;
			}
			i++;		
		}
	player1.instance_id = 0;
	mlx_key_hook(mlx, handle_keys, &player1);
	mlx_resize_hook(mlx, my_resize_hook, NULL);
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}
