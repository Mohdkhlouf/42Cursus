/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:31:19 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/12/23 16:40:50 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

#include "MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define TILE_SIZE 64
#define BUFFER_SIZE 1

typedef struct
{
	mlx_t* mlx;
	mlx_image_t* img;
	mlx_image_t* ground;
	mlx_image_t* wall;
	mlx_image_t* baby;
	mlx_image_t* home;
	mlx_image_t* player_to_left;
	mlx_image_t* player_to_right;
	mlx_texture_t *player_to_left_texture;
	mlx_texture_t *player_to_right_texture;
	int player_direction;
	
	char **map;
	int instance_id;
	int map_width;
	int map_height;
	int collected;
	int babies_to_collect;
	bool game_status;
	int	player_place_x;
	int	player_place_y;
}s_game;

char	**read_map(int *columns, int *rows, s_game *game);
static mlx_image_t* image;
void draw_bg(s_game *game);
void draw_walls_exit(s_game *game);
void draw_player(s_game *game);
int	two2one(int x, int y, s_game *game);
void	draw_collectables(s_game *game);
void	create_assets(s_game *game);
void draw_map(s_game *game);
void set_points(s_game *game, int new_location_x, int new_location_y);
// void render_game(s_game *game);
char	*ft_itoa(int n);



#endif