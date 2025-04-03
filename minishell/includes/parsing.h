/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:17:36 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/04/03 14:43:44 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

typedef struct s_data	t_data;

void					parsing(t_data *data);

typedef struct s_cmds
{
	char				**cmd;
	char				**redirections;
	// int	redirect_counter;
	// int	token_counter;
	// int cmds_ctr;
}						t_cmds;

typedef struct s_parsed_data
{
	t_cmds				*cmds;
	int cmds_counter;
	int pipes_counter;
}						t_parsed_data;

#endif