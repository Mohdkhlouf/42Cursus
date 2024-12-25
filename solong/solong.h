/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:31:19 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/12/25 17:09:57 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define TILE_SIZE 64
# define BUFFER_SIZE 1

typedef struct
{
	unsigned int	player_counter;
	unsigned int	exit_counter;
	unsigned int	babies_to_collect;
	unsigned int	walls;
	unsigned int	allowed_tiles;
}					s_assets;

typedef struct
{
	unsigned int	map_height;
	unsigned int	map_width;
}					s_map;

typedef struct
{
	mlx_texture_t	*baby_boy;
	mlx_texture_t	*wall;
	mlx_texture_t	*home;
	mlx_texture_t	*ground;
	mlx_texture_t	*player;
	mlx_texture_t	*player_to_left_texture;
	mlx_texture_t	*player_to_right_texture;
}					s_textures;

typedef struct
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_image_t		*ground;
	mlx_image_t		*wall;
	mlx_image_t		*baby;
	mlx_image_t		*home;
	mlx_image_t		*player_to_left;
	mlx_image_t		*player_to_right;
	s_assets		assets;
	s_map			map_orginal;
	s_textures		textures;
	int				player_direction;
	char			**map;
	unsigned int	collected;
	bool			game_status;
	int				player_place_x;
	int				player_place_y;
}					s_game;

char				**read_map(s_game *game,char *file_name);
static mlx_image_t	*image;
void				draw_bg(s_game *game);
void				draw_walls_exit(s_game *game);
void				draw_player(s_game *game);
int					two2one(int x, int y, s_game *game);
void				draw_collectables(s_game *game);
void				create_assets(s_game *game);
void				draw_map(s_game *game);
void				set_points(s_game *game, int new_location_x,
						int new_location_y);
int					open_file(char *file_name);
void				game_counters(char buffer, s_game *game);
void				print_error_and_exit(char *str);
int					map_validation(char **map_arr, s_game *game);
char				*ft_strdup(const char *s);

#endif