/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:31:19 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/06 15:55:30 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "MLX42/MLX42.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>

# define TILE_SIZE 64
# define BUFFER_SIZE 1

typedef struct s_points
{
	unsigned int	x;
	unsigned int	y;

}					t_points;

typedef struct s_assets
{
	unsigned int	player_counter;
	unsigned int	exit_counter;
	unsigned int	babies_to_collect;
	unsigned int	walls;
	unsigned int	allowed_tiles;
}					t_assets;

typedef struct s_map
{
	unsigned int	map_height;
	unsigned int	map_width;
}					t_map;

typedef struct s_textures
{
	mlx_texture_t	*baby_boy;
	mlx_texture_t	*wall;
	mlx_texture_t	*home;
	mlx_texture_t	*ground;
	mlx_texture_t	*player;
	mlx_texture_t	*player_left_t;
	mlx_texture_t	*player_right_tex;
}					t_textures;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_image_t		*ground;
	mlx_image_t		*wall;
	mlx_image_t		*baby;
	mlx_image_t		*home;
	t_assets		assets;
	t_map			map_orginal;
	t_textures		textures;
	t_points		player_point;
	t_points		exit_point;
	int				player_direction;
	char			**map;
	unsigned int	collected;
	bool			game_status;
	int				player_place_x;
	int				player_place_y;
	unsigned int	tile_size;
	unsigned int	move_counter;
}					t_game;

void				read_map(t_game *game, char *file_name);
void				draw_bg(t_game *game);
void				draw_walls_exit(t_game *game);
void				draw_player(t_game *game);
int					two2one(int x, int y, t_game *game);
void				draw_collectables(t_game *game);
void				create_assets(t_game *game);
void				draw_map(t_game *game);
void				set_points(t_game *game, int new_location_x,
						int new_location_y);
int					open_file(char *file_name);
void				game_counters(char *buffer, t_game *game);
void				print_error_and_exit(char *str, t_game *game);
void				map_validation(t_game *game);
char				*ft_strdup(const char *s);
void				check_file_name(int argc, char *argv[]);
void				reading_validation(t_game *game);
void				create_map_arr(t_game *game);
char				**fill_in_maze(char **maze, t_game *game);
void				path_validation(t_game *game);
void				initialize_struct_variable(t_game *game);
void				delete_textures_exit(t_game *game);
void				free_2d_map(t_game *game);
void				create_maze_arr(char **map, t_game *game);
void				free_2d_arr(char **arr2d, t_game *game);
void				free_row_closefd(int fd, char *row, t_game *game,
						char *msg);
void				change_player_direction(t_game *game);
void				handle_collectable(t_game *game, int new_location_x,
						int new_location_y);
void				move_player(int x, int y, t_game *game);
void				close_button(void *param);
char				*ft_strcpy(char *dest, char *src);
void				free_faild_arr(t_game *game, int fd, char *row,
						unsigned int i);
char				*ft_strstr(const char *big, const char *little);
void				print_exit_after_mlx(char *str, t_game *game);
void				free_mlx(t_game *game);

#endif