/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:11:15 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/25 14:20:59 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexing.h"

void split_vars(char *var, char **vars_arr)
{
	int vars_count;
	int start;
	int c;
	bool var_is_found;
	
	vars_count = 0;
	start = 0;
	c = 0;
	var_is_found = false;
	
	while (1)
	{
		if (var[c] == '\0')
		{
			vars_arr[vars_count] = ft_substr(var, start, c - start);
			vars_count++;
			break ;
		}
		if (var[c] == '$')
		{
			var_is_found = true;
			vars_arr[vars_count] = ft_substr(var, start, c - start);
			vars_count++;
			start = c;
		}
		if (var_is_found && var[c] == ' ')
		{
			
			var_is_found = false;
			vars_arr[vars_count] = ft_substr(var, start, c - start);
			vars_count++;
			start = c;
		}
		c++;
	}
	vars_arr[vars_count] = 0;
}

char *expand_vars(char **vars_arr, int len)
{
	int c;
	char *temp;
	
	temp = malloc(len);
	c = 0;
	while (vars_arr[c])
	{
		if (vars_arr[c][0] == '$')
		{
			vars_arr[c] = getenv(vars_arr[c] + 1);
		}
		c++;
	}
	c = 0;
	while (vars_arr[c])
	{
		temp = ft_strcat(temp, vars_arr[c]);
		c++;
	}
	return(temp);
}


void	var_handler2(t_data *data, int i)
{
	int		j;	
	int		c;

	j = 0;
	c = 0;
	t_vars_data *var;
	var = malloc(sizeof(t_vars_data) * 1);
	var_init(var);
	var->len = ft_strlen(data->tokens[i].data);
	var->vars_count = find_vars_count(data, i);
	var->vars_arr = malloc(sizeof (char *) * var->vars_count + 3);
	if (!var->vars_arr)
		exit(EXIT_FAILURE);
	printf("Vars Count:%d\n", var->vars_count);
	search_for_file_seperator(data, i, var->len, &j);
	if (data->file_seperator_found)
	{
		var->var_var = ft_substr(data->tokens[i].data, 0, j);
		var->temp = ft_substr(data->tokens[i].data, j, var->len);
	}
	else
		var->var_var = data->tokens[i].data;
	split_vars(var->var_var, var->vars_arr);
	var->var_var= expand_vars(var->vars_arr, var->len);
	path_set_and_join(data, i, var->temp, var->var_var);
}
