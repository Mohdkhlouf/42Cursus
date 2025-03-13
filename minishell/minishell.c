/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:20:09 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/13 14:53:04 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*first ceaning the line from spaces and white spaces and etc.
then send it as clean ass should be to the tokenising,
	then after that parsing starts. the parsing will store
		everthing in the abstract tree*/

int	main(void)
{
	t_data *data;
	
	memset(data,0,0);
	// cleanup_line(line) // this will remove all spaess and tabs and make the
	// line more ready to execution.
	// lexing / will do lexing .
	// parsing // will parse the inputs.
	while (1)
	{
		data->line = readline("Prompt > ");
	}
	return (0);
}
