/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 10:41:10 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/12/25 17:08:04 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	print_error_and_exit(char *str)
{
	perror(str);
	exit(-1);
	// we habe to ffree all created memory
}
// count the collectables.
void	game_counters(char buffer, s_game *game)
{
	if ((buffer != 'C') && (buffer != 'P') && (buffer != '1') && (buffer != '0')
		&& (buffer != '\n') && (buffer != 'E'))
	{
		print_error_and_exit("Map Error: has unsupported letters.\n");
	}
	else if (buffer == 'C')
		game->assets.babies_to_collect += 1;
	else if (buffer == 'P')
	{
		game->assets.player_counter += 1;
		if (game->assets.player_counter > 1)
			print_error_and_exit("Map Error: has 2 Players.\n");
	}
	else if (buffer == 'E')
	{
		game->assets.exit_counter += 1;
		if (game->assets.exit_counter > 1)
			print_error_and_exit("Map Error: has 2 exits.\n");
	}
}
// to open the file
int	open_file(char *file_name)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		print_error_and_exit("error in reading file");
	return (fd);
}