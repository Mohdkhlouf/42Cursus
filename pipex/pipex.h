/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/31 15:42:44 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
#include <sched.h> // for pid_t
#include <fcntl.h>

typedef struct s_pipes
{
	char	*infile;
	char	*outfile;
	char	*cmd1;
	char	*cmd2;
}			t_pipex;

void free_stack(t_pipex *pipex);
void	Exit_print_Error(t_pipex *pipex);

#endif