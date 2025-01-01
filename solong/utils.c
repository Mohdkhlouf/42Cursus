/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:29:16 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/01 14:17:47 by mkhlouf          ###   ########.fr       */
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

void	create_map_arr(t_game *game)
{
	unsigned int	i;

	i = 0;
	game->map = malloc(game->map_orginal.map_height * sizeof(char *));
	if (!game->map)
		print_error_and_exit("creating 2d array faild", game);
	while (i < game->map_orginal.map_height)
	{
		game->map[i] = malloc(game->map_orginal.map_width * sizeof(char) + 1);
		if (!game->map[i])
			print_error_and_exit("creating 2d array faild", game);
		i++;
	}
}

void	delete_textures_exit(t_game *game)
{
	if(game->textures.player_left_t || game->textures.player_to_right_texture)
	{
		mlx_delete_texture(game->textures.player_left_t);
		mlx_delete_texture(game->textures.player_to_right_texture);
	}
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*orginal;

	orginal = dest;
	while (*src != 0)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (orginal);
}
