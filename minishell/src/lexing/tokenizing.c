/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:02:18 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/25 13:48:34 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexing.h"

void	assign_quotes(t_data *data, int len, int i, char *temp)
{
	int	c;
	int	j;

	c = 0;
	j = 0;
	while (j < len)
	{
		if (data->tokens[i].data[j] == '\'' && data->quote_type == 0)
			data->quote_type = '\'';
		if (data->tokens[i].data[j] == '\"' && data->quote_type == 0)
			data->quote_type = '\"';
		if (data->tokens[i].data[j] == data->quote_type
			|| (data->tokens[i].data[j] == '\'' && data->quote_type == 0)
				|| (data->tokens[i].data[j] == '\"' && data->quote_type == 0))
			j++;
		else
		{
			temp[c] = data->tokens[i].data[j];
			c++;
			j++;
		}
	}
	data->quote_type = 0;
	temp[c] = '\0';
}

void	quote_fixing(t_data *data, int i)
{
	char	*temp;
	int		len;

	if (data->tokens[i].data[0] == '\'')
		data->tokens[i].type = TOK_SINGLE_QUOTE;
	else if (data->tokens[i].data[0] == '\"')
		data->tokens[i].type = TOK_DOUBLE_QUOTE;
	len = ft_strlen(data->tokens[i].data);
	temp = malloc(sizeof(char) * len + 1);
	if (temp == NULL)
		exit(EXIT_FAILURE);
	assign_quotes(data, len, i, temp);
	free(data->tokens[i].data);
	data->tokens[i].data = ft_strdup(temp);
	free(temp);
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
		if (data->file_seperator_found)
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

void expand_vars(char **vars_arr, int len)
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
	printf("Final %s\n",temp);
}

void	var_handler2(t_data *data, int i)
{
	char	*var;
	char	*temp;
	int		len;
	int		var_found;
	int		j;
	int		vars_count;
	char	**vars_arr;
	int		c;


	j = 0;
	var_found = 0;
	vars_count = 0;
	c = 0;
	
	len = ft_strlen(data->tokens[i].data);
	vars_count = find_vars_count(data, i);
	vars_arr = malloc(sizeof (char *) * vars_count * 3);
	if (!vars_arr)
		exit(EXIT_FAILURE);
	printf("Vars Count:%d\n", vars_count);
	search_for_file_seperator(data, i, len, &j);
	if (data->file_seperator_found)
	{
		var = ft_substr(data->tokens[i].data, 0, j);
		temp = ft_substr(data->tokens[i].data, j, len);
	}
	else
		var = data->tokens[i].data;
	
	split_vars(var, vars_arr);
	expand_vars(vars_arr, len);
	
	c = 0;
	while (vars_arr[c])
	{
		printf("part:%s#\n", vars_arr[c]);
		c++;
	}
	
	// path_set_and_join(data, i, temp, path);
}

void	var_handler(t_data *data, int i)
{
	char	*path;
	char	*var;
	char	*temp;
	int		len;
	int		j;

	j = 0;
	temp = NULL;
	var = NULL;
	path = NULL;
	len = ft_strlen(data->tokens[i].data);
	search_for_file_seperator(data, i, len, &j);
	if (data->file_seperator_found)
	{
		var = ft_substr(data->tokens[i].data, 0, j);
		temp = ft_substr(data->tokens[i].data, j, len);
	}
	else
		var = data->tokens[i].data;
	ft_memcpy(var, var + 1, ft_strlen(var) - 1);
	path = getenv(var);
	path_set_and_join(data, i, temp, path);
}

void	tokenizing(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->tokens_conter)
	{
		printf("token %s\n", data->tokens[i].data);
		if (ft_strchr(data->tokens[i].data, '$')
			&& data->tokens[i].data[0] != '\''
			&& data->tokens[i].data[0] != '\"')
			var_handler(data, i);
		if (ft_strchr(data->tokens[i].data, '\'')
				|| ft_strchr(data->tokens[i].data, '\"'))
		{
			quote_fixing(data, i);
		}
		if ((data->tokens[i].type == TOK_DOUBLE_QUOTE)
			&& ft_strchr(data->tokens[i].data, '$'))
			var_handler2(data, i);
		i++;
	}
	i = 0;
	while (i < data->tokens_conter)
	{
		printf("Token:#%s# Type:%u\n", data->tokens[i].data,
			data->tokens[i].type);
		i++;
	}
}
