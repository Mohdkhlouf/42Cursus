/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:02:18 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/19 15:16:06 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexing.h"

void	normal_function(t_data *data)
{
	data->in_token = true;
}

void single_quote_function(t_data *data)
{
	if (data->in_token)
	{
		append_token(data, TOK_COMMAND);
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
		append_token(data, TOK_COMMAND);
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
		append_token(data, TOK_COMMAND);
		data->in_token = false;
	}
	data->start = data->end + 1;
}
