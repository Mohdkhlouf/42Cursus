/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:02:18 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/18 16:00:26 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void	normal_function(t_data *data)
{
	data->in_token = true;
}

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
void	redirectout_function(t_data *data)
{
	if (data->in_token)
	{
		append_token(data, TOK_COMMAND);
		data->in_token = false;
	}
	data->start = data->end;
	data->end++;
	if (data->input_line[data->end] == '>')
	{
		data->end++;
		append_token(data, TOK_APPEND);
	}
	else
		append_token(data, TOK_REDIRECT_OUT);
	data->start = data->end;
}

void	redirectin_function(t_data *data)
{
	if (data->in_token)
	{
		append_token(data, TOK_COMMAND);
		data->in_token = false;
	}
	data->start = data->end;
	data->end++;
	if (data->input_line[data->end] == '<')
	{
		data->end++;
		append_token(data, TOK_REDIRECT_IN);
	}
	else
		append_token(data, TOK_REDIRECT_IN);
	data->start = data->end;
}

void	pipe_function(t_data *data)
{
	if (data->in_token)
	{
		append_token(data, TOK_COMMAND);
		data->in_token = false;
	}
	data->start = data->end;
	append_token(data, TOK_PIPE);
	data->start = data->end + 1;
}

void	space_function(t_data *data)
{
	printf("space\n");
	if (data->in_token)
	{
		append_token(data, TOK_COMMAND);
		data->in_token = false;
	}
	data->start = data->end + 1;
}

void	line_split(t_data *data)
{
	data->end = 0;
	data->start = 0;
	malloc_tokens_arr(data);
	while (data->input_line[data->end])
	{
		if (data->input_line[data->end] == ' ')
			space_function(data);
		else if (data->input_line[data->end] == '|')
			pipe_function(data);
		else if (data->input_line[data->end] == '>')
			redirectout_function(data);
		else if (data->input_line[data->end] == '<')
			redirectin_function(data);
		else
			normal_function(data);
		data->end++;
	}
	if (data->in_token)
	{
		data->end++;
		append_token(data, TOK_COMMAND);
	}
}
