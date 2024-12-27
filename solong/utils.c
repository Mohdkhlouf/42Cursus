/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:29:16 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/12/27 19:37:34 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[count])
		count++;
	ptr = (char *)malloc(count + 1);
	if (!ptr)
		return (NULL);
	while (i < count)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((big == NULL || little == NULL))
		return (NULL);
	if (!*little || little == NULL)
		return ((char *)big);
	while (big[i] != '\0')
	{
		j = 0;
		while (little[j] == big[i + j])
		{
			if (little[j + 1] == '\0')
			{
				return ((char *)big + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

void	check_filen_name(char *file_name)
{
	if (!(ft_strstr(file_name, ".ber")))
		print_error_and_exit("the Map file extintion is not corret.");
}

char	**create_map_arr(char **map, t_game *game)
{
	unsigned int	i;

	i = 0;
	map = malloc(game->map_orginal.map_height * sizeof(char *));
	if (!map)
		return (NULL);
	while (i < game->map_orginal.map_height)
	{
		map[i] = malloc(game->map_orginal.map_width * sizeof(char));
		if (!map[i])
		{
			while (i > 0)
			{
				free(map[i - 1]);
				i--;
			}
			free(map);
			print_error_and_exit("creating 2d array faild");
		}
		i++;
	}
	return (map);
}
void	initialize_struct_variable(t_game *game)
{
	game->map = NULL;
	game->map_orginal.map_height = 0;
	game->map_orginal.map_width = 0;
	game->player_direction = 1;
	game->collected = 0;
	game->assets.babies_to_collect = 0;
	game->assets.player_counter = 0;
	game->assets.exit_counter = 0;
	game->player_point.x = 0;
	game->player_point.y = 0;
	game->exit_point.x = 0;
	game->exit_point.y = 0;
}
void	delete_textures_exit(t_game *game)
{
	mlx_delete_texture(game->textures.player_left_t);
	mlx_delete_texture(game->textures.player_to_right_texture);
	exit(0);
}
