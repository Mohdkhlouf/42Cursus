/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:53:30 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/10 10:30:58 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execve_error_close(t_pipex *pipex)
{
	perror("execve failed: ");
	free_stack(pipex);
	exit(127);
}
