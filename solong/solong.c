
#include "solong.h"
#include <stdlib.h>
#include <string.h>

void draw_bg(struct player *player1)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < player1->map_height)
	{
		j = 0;
		while (j < player1->map_width)
		{
			
			if (player1->map[i][j] == '1')
				mlx_image_to_window(player1->mlx, player1->wall, j * TILE_SIZE,
					i * TILE_SIZE);
			else if (player1->map[i][j] == 'E')
				mlx_image_to_window(player1->mlx, player1->home, j * TILE_SIZE,
					i * TILE_SIZE);
			else
				mlx_image_to_window(player1->mlx, player1->ground, j* TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}
void draw_player(struct player *player1)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	i = 0;
	while (i < player1->map_height)
	{
		j = 0;
		while (j < player1->map_width)
		{
			if (player1->map[i][j] == 'P')
				mlx_image_to_window(player1->mlx, player1->img, j * TILE_SIZE, i
					* TILE_SIZE);
			j++;
		}
		i++;
	}
}
void	draw_collectables(struct player *player1)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	
	while (i < player1->map_height)
	{
		j = 0;
		while (j < player1->map_width)
		{
			if (player1->map[i][j] == 'C')
				mlx_image_to_window(player1->mlx, player1->baby, j * TILE_SIZE,
					i * TILE_SIZE);
			j++;
		}
		i++;
	}
	
}
void	create_assets(struct player *player1)
{
	mlx_texture_t	*baby_boy;
	mlx_texture_t	*wall;
	mlx_texture_t	*home;
	mlx_texture_t	*ground;
	mlx_texture_t	*player;

	baby_boy = mlx_load_png("assets/babyboy.png");
	wall = mlx_load_png("assets/wall.png");
	home = mlx_load_png("assets/home.png");
	ground = mlx_load_png("assets/ground.png");
	player = mlx_load_png("assets/player.png");
	if (!baby_boy || wall || home || ground || player)
		perror("error in loading Baby boy image");
	player1->wall = mlx_texture_to_image(player1->mlx, wall);
	player1->ground = mlx_texture_to_image(player1->mlx, ground);
	player1->home = mlx_texture_to_image(player1->mlx, home);
	player1->baby = mlx_texture_to_image(player1->mlx, baby_boy);
	player1->img = mlx_texture_to_image(player1->mlx, player);
	if (!player1->wall || !player1->ground || !player1->home || !player1->baby
		|| !player1->img)
		perror("Error in loading image");
}

void	move_player(int x, int y, struct player *player1)
{
	int	player_place_x;
	int	player_place_y;
	int	new_location_x;
	int	new_location_y;

	player_place_x = player1->img->instances->x / TILE_SIZE;
	player_place_y = player1->img->instances->y / TILE_SIZE;
	new_location_x = player_place_x + x;
	new_location_y = player_place_y + y;
	if (player1->map[new_location_y][new_location_x] == '0')
	{
		puts("allow");
		player1->img->instances->x = new_location_x * TILE_SIZE;
		player1->img->instances->y = new_location_y * TILE_SIZE;
	}
	else if (player1->map[new_location_y][new_location_x] == 'C')
	{
		puts("BABY");
		player1->collected += 1;
		printf("%d", player1->collected);
		player1->map[new_location_y][new_location_x] = '0';
		player1->img->instances->x = new_location_x * TILE_SIZE;
		player1->img->instances->y = new_location_y * TILE_SIZE;
	}
	else if (player1->map[new_location_y][new_location_x] == 'P')
	{
		puts("Player Spot");
		player1->img->instances->x = new_location_x * TILE_SIZE;
		player1->img->instances->y = new_location_y * TILE_SIZE;
	}
	else if (player1->map[new_location_y][new_location_x] == 'E')
		exit(0);
	else
	{
		puts("Not Allowed WALL");
	}
	draw_collectables(player1);
}
void	handle_keys(mlx_key_data_t keydata, void *param)
{
	struct player	*player1;

	// (void)param; // Unused parameter
	player1 = (struct player *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		printf("ESC\n");
		exit(0);
	}
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move_player(0, -1, player1);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move_player(0, +1, player1);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		move_player(+1, 0, player1);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move_player(-1, 0, player1);
}

void	my_resize_hook(int32_t width, int32_t height, void *param)
{
	printf("Window resized to: %dx%d\n", width, height);
}

int32_t	main(void)
{
	int				map_width;
	int				map_height;
	char			**map;
	int				i;
	int				j;
	struct player	player1;

	i = 0;
	j = 0;
	map_width = 0;
	map_height = 0;
	player1.collected = 0;
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
	player1.mlx = mlx_init(map_width * TILE_SIZE, map_height * TILE_SIZE,
			"MLX42", true);
	if (!player1.mlx)
		exit(EXIT_FAILURE);
	create_assets(&player1);
	draw_bg(&player1);
	draw_collectables(&player1);
	draw_player(&player1);
	player1.instance_id = 0;
	mlx_key_hook(player1.mlx, handle_keys, &player1);
	mlx_resize_hook(player1.mlx, my_resize_hook, NULL);
	mlx_loop(player1.mlx);
	mlx_terminate(player1.mlx);
	return (EXIT_SUCCESS);
}
