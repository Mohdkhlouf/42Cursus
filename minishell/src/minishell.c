/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:20:09 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/18 15:27:21 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*first ceaning the line from spaces and white spaces and etc.
then send it as clean ass should be to the tokenising,
	then after that parsing starts. the parsing will store
		everthing in the abstract tree*/

/*clean line function to clean the line from spaces, it changes spaces to one */

void tokenizing(t_data *data)
{
	int i;

	i = 0;
	// clean_line(data);
	line_split(data);
	while (i < data->tokens_conter)
	{
		printf("%s\n", data->tokens[i].data);
		i++;
	}

}
void data_init(t_data *data)
{
	data->cleaned_line = NULL;
	data->cline_parts = 0;
	data->input_line = NULL;
	data->tokens = NULL;
	data->end = 0;
	data->start = 0;
	data->in_token = false;
	data->tokens_conter = 0;
	// data->tokens->data = NULL;
}

void reading_loop(t_data *data)
{
	while (true)
	{
		data_init(data);
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



int	main(void)
{
	t_data *data;
	
	data = malloc(sizeof (t_data));
	// cleanup_line(line) // this will remove all spaess and tabs and make the
	// line more ready to execution.
	// lexing / will do lexing .
	// parsing // will parse the inputs.
	reading_loop(data);

	free_data(data);
	free(data);
	return (EXIT_SUCCESS);
}
