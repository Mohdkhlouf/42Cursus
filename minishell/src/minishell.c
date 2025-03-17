/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:20:09 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/17 15:27:32 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*first ceaning the line from spaces and white spaces and etc.
then send it as clean ass should be to the tokenising,
	then after that parsing starts. the parsing will store
		everthing in the abstract tree*/

/*clean line function to clean the line from spaces, it changes spaces to one */
void clean_line(t_data *data)
{
	int line_length;
	int i;
	int j;

	i = 0;
	j = 0;
	line_length = ft_strlen(data->input_line);
	data->cleaned_line = malloc(sizeof (char) * line_length + 1);
	if (!data->cleaned_line) {
		// Handle memory allocation error
		printf("Error allocating memory for tokens\n");
		exit(EXIT_FAILURE);
	}
	
	while (data->input_line[i])
	{
		while ((data->input_line[i] == ' ' &&  data->input_line[i + 1] == ' ')
			|| (data->input_line[i] == ' ' &&  data->input_line[i + 1] == '\0'))
			i++;
		data->cleaned_line[j] =  data->input_line[i];
		i++;
		j++;
	}
	data->cleaned_line[j] = '\0';
}

void tokenizing(t_data *data)
{
	int i;

	i = 0;
	clean_line(data);
	line_split(data);
	while(data->tokens[i].data)
	{
		printf("token #%s#\n", data->tokens[i].data);
		i++;
	}
}

void reading_loop(t_data *data)
{
	while (true)
	{
		data->input_line = readline("Prompt > ");
		if (!data->input_line)
		{
			printf("Exit");
			return;
		}
		add_history(data->input_line);
		tokenizing(data);
		free_data(data);
	}
}

void data_init(t_data *data)
{
	data->cleaned_line = NULL;
	data->cline_parts = 0;
	data->input_line = NULL;
	data->tokens = NULL;
	// data->tokens->data = NULL;
}

int	main(void)
{
	t_data *data;
	
	data = malloc(sizeof (t_data));
	data_init(data);

	// cleanup_line(line) // this will remove all spaess and tabs and make the
	// line more ready to execution.
	// lexing / will do lexing .
	// parsing // will parse the inputs.
	reading_loop(data);

	free_data(data);
	free(data);
	return (EXIT_SUCCESS);
}
