/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/01 01:08:48 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <sched.h> // for pid_t
# include <sys/wait.h>

typedef struct s_pipes
{
	char	*infile;
	char	*outfile;
	char	**cmd1;
	char	*path1;
	char	**cmd2;
	char	*path2;
}			t_pipex;

void		free_stack(t_pipex *pipex);
void		Exit_print_Error(t_pipex *pipex);
void		check_arguments(int argc, char **argv, t_pipex *pipex, char *env[]);
void		check_files(char *infile, char *outfile, t_pipex *pipex);
void		check_file_exisit_mode(char *filename, int mode, t_pipex *pipex);
char		*find_path(char **path, char *cmd);
char		**parse_path(char *env[], t_pipex *pipex);
void		check_commands(char *cmd1, char *cmd2, t_pipex *pipex, char *env[]);
void		compare_commands(char **path, char *cmd1, char *cmd2,
				t_pipex *pipex);
void		check_accessed(char **path, char *cmd1, char *cmd2, t_pipex *pipex);
void		check_commands_exisit_mode(char *filename, int mode,
				t_pipex *pipex);
void		initialize_values(t_pipex *pipex);
void		free_stack(t_pipex *pipex);
void		free_multi(char *str1, char *str2, char *str3, char *str4);
void		free_2d_arr(char **arr);

#endif