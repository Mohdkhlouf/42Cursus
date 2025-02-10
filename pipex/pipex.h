/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/10 10:26:50 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <sched.h>
# include <sys/wait.h>

typedef struct s_cmd
{
	char	**cmd;
	char	*path;
}			t_cmd;

typedef struct s_pipes
{
	char	*infile;
	char	*outfile;
	t_cmd	*cmds;
	int		counter;
	char	*t_infile;
	char	*t_outfile;
	char	*t_cmd1;
	char	*t_cmd2;
	char	**env_path;
}			t_pipex;

void		free_stack(t_pipex *pipex);
void		exit_print_error(t_pipex *pipex);
void		check_arguments(int argc, t_pipex *pipex);
void		check_file_exisit_mode(char *filename, t_pipex *pipex);
char		*find_path(t_pipex *pipex, char *cmd);
char		**parse_path(char *env[], t_pipex *pipex);
void		check_command(char *cmd, t_pipex *pipex, int i);
void		initialize_values(t_pipex *pipex, int *status, char *argv[],
				int *pid);
void		free_stack(t_pipex *pipex);
void		free_multi(char *str1, char *str2, char *str3, char *str4);
void		free_2d_arr(char **arr);
void		execve_error_close(t_pipex *pipex);
void		check_outfile(t_pipex *pipex, int *pipefd);
void		path_nfnound_error(t_pipex *pipex, char *file_name, char *cmd);
void		permission_denide_error(t_pipex *pipex);

#endif