/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:56:54 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/04/02 17:10:11 by mkhlouf          ###   ########.fr       */
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
	cmds_init(cmds_data);
	while (data->input_line[i])
	{
		if (data->input_line[i] == '|')
			cmds_data->pipes_counter++;
		i++;
	}
	cmds_data->cmds_counter = cmds_data->pipes_counter + 1;
}

void create_cmds_arr(t_parsed_data *cmds_data)
{
	cmds_data->cmds = malloc(sizeof(char *) * cmds_data->cmds_counter);
	if (!cmds_data->cmds->cmd)
		exit(EXIT_FAILURE);
	
	cmds_data->cmds->cmd = malloc (sizeof (char) * 20);
}
void fill_in_arr(t_parsed_data *cmds_data, t_data *data)
{
	int i;
	int cmds_counter;
	int redirect_counter;
	int token_counter;

	i = 0;
	cmds_counter = 0;
	redirect_counter = 0;
	token_counter = 0;
	while (data->tokens[i].type != TOK_EOF)
	{
		redirect_counter = 0;
		
		if(data->tokens[i].type == TOK_PIPE)
			cmds_counter++;
		if(data->tokens[i].type== TOK_REDIRECT_HEREDOC || data->tokens[i].type== TOK_REDIRECT_IN
			|| data->tokens[i].type== TOK_REDIRECT_OUT || data->tokens[i].type== TOK_APPEND)	
			{
				cmds_data->cmds[cmds_counter].redirections[redirect_counter] = data->tokens[i].data;
				redirect_counter++;
			}
		else
			{
				cmds_data->cmds[cmds_counter].cmd[token_counter]= data->tokens[i].data;
				token_counter++;
			}
		i++;
	}
}
void	parsing(t_data *data)
{
	t_parsed_data *cmds_data;

	cmds_data = malloc(sizeof(t_parsed_data) * 1);
	if (!cmds_data)
		exit(EXIT_FAILURE);
	find_cmds_counter(data, cmds_data);
	create_cmds_arr(cmds_data);
	fill_in_arr(cmds_data, data);
	printf("i have %d commands\n", cmds_data->cmds_counter);
}
