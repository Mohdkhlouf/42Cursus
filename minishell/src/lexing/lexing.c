/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:02:18 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/25 15:49:10 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexing.h"

void	malloc_tokens_arr(t_data *data)
{
	data->cline_parts = ft_strlen(data->input_line) / 2;
	if (data->cline_parts != 0)
	{
		data->tokens = malloc(sizeof(t_token) * data->cline_parts);
		if (!data->tokens)
		{
			printf("Error allocating memory for tokens\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		printf("Error\n");
		// free
		exit(EXIT_FAILURE);
	}
}

// this one to add the data normally
void	append_token(t_data *data, int type)
{
	if (data->end == data->start)
		data->tokens[data->tokens_conter].data = ft_substr(data->input_line,
				data->start, 1);
	else
		data->tokens[data->tokens_conter].data = ft_substr(data->input_line,
				data->start, data->end - data->start);
	data->tokens[data->tokens_conter].type = type;
	data->tokens_conter++;
}

void	line_split(t_data *data)
{
	data->end = 0;
	data->start = 0;
	malloc_tokens_arr(data);
	while (1)
	{
		if (data->input_line[data->end] == '\0')
			return (eof_function(data));
		if (data->quote_found && data->input_line[data->end] != '\'')
			normal_function(data);
		else if (data->double_quote_found && data->input_line[data->end] != '\"'
			&& data->input_line[data->end] != '$')
			normal_function(data);
		else if (ft_strchr(DELEMETERS, data->input_line[data->end]))
			space_function(data);
		else if (data->input_line[data->end] == '|')
			pipe_function(data);
		else if (data->input_line[data->end] == '>')
			redirectout_function(data);
		else if (data->input_line[data->end] == '<')
			redirectin_function(data);
		else if (data->input_line[data->end] == '$' && !data->quote_found)
			env_variable_function(data);
		else
			normal_function(data);
		data->end++;
	}
}

/*first ceaning the line from spaces and white spaces and etc.
then send it as clean ass should be to the tokenising,
	then after that parsing starts. the parsing will store
		everthing in the abstract tree*/

/*clean line function to clean the line from spaces, it changes spaces to one */

void	lexing(t_data *data)
{
	int	i;

	i = 0;
	line_split(data);
}
