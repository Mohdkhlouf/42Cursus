/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:17:36 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/17 15:08:43 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef enum e_token_type
{
	TOK_UNKNOWN,             // Unknown token
	TOK_COMMAND,             // Command (e.g., "ls")
	TOK_ARGUMENT,            // Argument (e.g., "file.txt")
	TOK_PIPE,                // Pipe "|" operator
	TOK_REDIRECT_IN,         // Redirect "<" operator
	TOK_REDIRECT_OUT,        // Redirect ">" operator
	TOK_APPEND,              // Append ">>" operator
	TOK_REDIRECT_HEREDOC,    // Here Document "<<" operator
	TOK_REDIRECT_HERESTRING, // Here String "<<<" operator
	TOK_LOGICAL_AND,         // Logical AND "&&" operator
	TOK_LOGICAL_OR,          // Logical OR "||" operator
	TOK_BACKGROUND,          // Background "&" operator
	TOK_GROUP_START,         // Grouping "(" operator
	TOK_GROUP_END,           // Grouping ")" operator
	TOK_SEMICOLON,           // Command separator ";" operator
	TOK_ASSIGNMENT,          // Assignment "=" operator
	TOK_COMMENT,             // Comment "#" operator
	TOK_WILDCARD,            // Wildcard "*" operator
	TOK_SINGLE_QUOTE,        // Single quote "'" character
	TOK_DOUBLE_QUOTE,        // Double quote "\"" character
	TOK_ENV_VAR,             // Environment variable (e.g., $HOME)
	TOK_EOF,                 // End of file or input termination
}					t_token_type;

typedef struct s_token
{
	char			*data;
	t_token_type	*type;
}					t_token;

typedef struct s_data
{
	char			*input_line;
	char			*cleaned_line;
	int				cline_parts; // clean line parts number
	t_token			*tokens;
}					t_data;

void				free_data(t_data *data);
void				line_split(t_data *data);

#endif