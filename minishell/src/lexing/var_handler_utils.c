/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_handler_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:12:29 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/25 14:22:25 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexing.h"

void var_init(t_vars_data *var)
{
	var->len = 0;
	var->temp = NULL;
	var->var_var = NULL;
	var->vars_arr = NULL;
	var->vars_count = 0;
}
void	search_for_file_seperator(t_data *data, int i, int len, int *j)
{
	while (*j < len)
	{
		if (data->tokens[i].data[*j] == '/' || data->tokens[i].data[*j] == '\''
			|| data->tokens[i].data[*j] == '\"')
		{
			data->file_seperator_found = true;
			break ;
		}
		(*j)++;
	}
}

void	path_set_and_join(t_data *data, int i, char *temp, char *path)
{
	if (path == NULL)
		exit(EXIT_FAILURE);
	else
	{
		if (data->file_seperator_found == true)
			data->tokens[i].data = ft_strjoin(path, temp);
		else
			data->tokens[i].data = path;
		data->tokens[i].type = TOK_ENV_VAR;
	}
}

int	find_vars_count(t_data *data, int i)
{
	int	j;
	int	vars_count;

	j = 0;
	vars_count = 0;
	while (data->tokens[i].data[j])
	{
		if (data->tokens[i].data[j] == '$')
			vars_count++;
		j++;
	}
	return (vars_count);
}
