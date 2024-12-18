/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:31:19 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/12/18 16:20:21 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

#include "MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define TILE_SIZE 64
#define BUFFER_SIZE 1
char **read_map(int *map_width, int *map_height);
static mlx_image_t* image;

struct player
{
	mlx_t* mlx;
	mlx_image_t* img;
	mlx_image_t* ground;
	mlx_image_t* wall;
	mlx_image_t* baby;
	mlx_image_t* home;
	char **map;
	int instance_id;
	int map_width;
	int map_height;
	int collected;
	bool game_status;
};




#endif