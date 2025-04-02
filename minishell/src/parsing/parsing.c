/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:56:54 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/04/02 16:00:19 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	cmds_init(t_parsed_data *cmds_data)
{
	cmds_data->cmds_counter = 0;
	cmds_data->pipes_counter = 0;
}

void	find_cmds_counter(t_data *data, t_parsed_data *cmds_data)
{
	int	i;

	i = 0;
	while (data->input_line[i])
	{
		if (data->input_line[i] == '|')
			cmds_data->pipes_counter++;
		i++;
	}
	cmds_data->cmds_counter = cmds_data->pipes_counter + 1;
}

void	parsing(t_data *data)
{
	t_parsed_data *cmds_data;

	cmds_data = malloc(sizeof(t_parsed_data) * 1);
	cmds_init(cmds_data);
	find_cmds_counter(data, cmds_data);
	printf("i have %d commands\n", cmds_data->cmds_counter);
}