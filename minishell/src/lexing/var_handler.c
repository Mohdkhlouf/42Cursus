/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:11:15 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/26 16:37:49 by mkhlouf          ###   ########.fr       */
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
			if (start == c)
				vars_arr[vars_count] = ft_substr(var, start, 1);
			else
				vars_arr[vars_count] = ft_substr(var, start, c - start);
			vars_count++;
			break ;
		}
		else if (var[c] == '$')
		{
			var_is_found = true;
			vars_arr[vars_count] = ft_substr(var, start, c - start);
			vars_count++;
			start = c;
		}
		else if ((var_is_found && var[c] == ' ' ) || (var_is_found && var[c] == '/' ) || (var_is_found && var[c] == '\"' ))
		{
			var_is_found = false;
			vars_arr[vars_count] = ft_substr(var, start, c - start);
			vars_count++;
			start = c;
		}
		
		c++;
	}
	
	vars_arr[vars_count] = NULL;
}

char *expand_vars(char **vars_arr)
{
	int c;
	char *temp;
	
	c = 0;
	while (vars_arr[c])
	{
		if (vars_arr[c][0] == '$')
		{
			vars_arr[c] = ft_strdup(getenv(vars_arr[c] + 1));
			if (vars_arr[c] == NULL)
				vars_arr[c] = ft_strdup("");
		}
		printf("value:%s#\n", vars_arr[c]);
		c++;
	}
	temp = ft_strdup("");

	c = 0;
	while (vars_arr[c])
	{
		temp = ft_strdup(ft_strcat(temp, vars_arr[c]));
		c++;
	}
	return(temp);
}

void free_var(t_vars_data *var)
{
	free(var->vars_arr);
	free(var);
}

void	var_handler2(t_data *data, int i)
{
	int		j;	
	int		c;

	j = 0;
	c = 0;
	t_vars_data *var;
	var = malloc(sizeof(t_vars_data) * 1);
	if (!var)
		exit(EXIT_FAILURE);
	var_init(var, data, i);
	split_vars(data->tokens[i].data, var->vars_arr);
	var->var_var = expand_vars(var->vars_arr);
	path_set_and_join(data, i, var->temp, var->var_var);
	free_var(var);
}
