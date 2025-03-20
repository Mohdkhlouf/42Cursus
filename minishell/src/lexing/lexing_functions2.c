/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:02:18 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/20 12:20:58 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexing.h"

void	normal_function(t_data *data)
{
	data->in_token = true;
	if(data->input_line[data->end] == '\'' || data->input_line[data->end] == '\"')
	{
		if(data->quote_found == true)
			data->quote_found = false;
		else if(data->quote_found == false)
			data->quote_found = true;
	}
	
}

void single_quote_function(t_data *data)
{
	if (data->in_token)
	{
		append_token(data, TOK_SINGLE_QUOTE);
		data->in_token = false;
	}
	data->start = data->end + 1;
	if (data->quote_found == false)	
		data->quote_found = true;
	else
	{
		data->quote_found = false;
	}		
}

void double_quote_function(t_data *data)
{
	if (data->in_token)
	{
		append_token(data, TOK_DOUBLE_QUOTE);
		data->in_token = false;
	}
	data->start = data->end + 1;
	if (data->double_quote_found == false)	
		data->double_quote_found = true;
	else
	{
		data->double_quote_found = false;
	}
}

void	env_variable_function(t_data *data)
{
	if (data->in_token)
	{
		append_token(data, TOK_ENV_VAR);
		data->in_token = false;
	}
	data->start = data->end;
}
