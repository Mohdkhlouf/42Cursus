/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:17:36 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/24 09:51:09 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXING_H
# define LEXING_H

# include "minishell.h"

# define DELEMETERS " \t\n\0"
# define VAR_DELEMITER "/\'\"$"
typedef struct s_data	t_data;

void					space_function(t_data *data);
void					pipe_function(t_data *data);
void					redirectin_function(t_data *data);
void					redirectout_function(t_data *data);
void					append_token_double(t_data *data, int type);
void					normal_function(t_data *data);
void					append_token(t_data *data, int type);
void					env_variable_function(t_data *data);
void					eof_function(t_data *data);

#endif