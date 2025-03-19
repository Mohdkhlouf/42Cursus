/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:20:09 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/19 14:30:24 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


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
	data->quote_found = false;
	data->double_quote_found = false;
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
