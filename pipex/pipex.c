/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/30 18:07:14 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	Exit_print_Error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}
// check commands functions
// void free_2d_arr(char **arr)
// {
//     while (*arr)
//     {
//         free(*arr);
//         arr++;
//     }
//     free(arr);
// }

void	check_commands_exisit_mode(char *filename, int mode)
{
	printf("%s , %d \n", filename, mode);
	if (access(filename, F_OK | mode) == 0)
		return ;
	else
		Exit_print_Error();
}

char	**parse_path(char *env[])
{
	int		i;
	char	**path;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
		{
			path = ft_split(ft_strdup(env[i] + 5), ':');
			if (!path)
				Exit_print_Error();
			return (path);
		}
		i++;
	}
	return (NULL);
}

void	compare_commands(char **path, char *cmd1, char *cmd2, t_pipex *pipex)
{
	int		i;
	char	*file_name1;
	char	*file_name2;
    int accessed = 1 ;
    
	i = 0;
    accessed = 0;
	while (path[i])
	{
		file_name1 = ft_strjoin(path[i], ft_strjoin("/", cmd1));
		file_name2 = ft_strjoin(path[i], ft_strjoin("/", cmd2));
		if ((access(file_name1, F_OK | X_OK) == 0) && (access(file_name2,
				F_OK | X_OK) == 0))
			accessed = 1 ;
		i++;
	}
    if(accessed)
    {
        pipex->cmd1 = ft_strdup(file_name1);
        pipex->cmd2 = ft_strdup(file_name2);
    }
    else
        Exit_print_Error();
}
void	check_commands(char *cmd1, char *cmd2, t_pipex *pipex, char *env[])
{
	char	**path_cmd1_arr;
	char	**path_cmd2_arr;
	int		i;
	char	**path;

	// char *path_cmd1;
	// char *path_cmd2;
	i = 0;
	path_cmd1_arr = ft_split(cmd1, ' ');
	path_cmd2_arr = ft_split(cmd2, ' ');
	pipex->cmd1 = path_cmd1_arr[0];
	path = parse_path(env);
	if (path)
		compare_commands(path, path_cmd1_arr[0], path_cmd2_arr[0],pipex);
    ft_printf("cmd1:%s\ncmd2:%s\n", pipex->cmd1, pipex->cmd2);
	// free_2d_arr(path_cmd1_arr);
	// free_2d_arr(path_cmd2_arr);
	// free(path_cmd1);
	// free(path_cmd2);
}
//--end of check commands functions

//++check files functions
void	check_file_exisit_mode(char *filename, int mode)
{
	if (access(filename, F_OK | mode) == 0)
		return ;
	else
		Exit_print_Error();
}

void	check_files(char *infile, char *outfile, t_pipex *pipex)
{
	check_file_exisit_mode(infile, R_OK);
	pipex->infile = ft_strdup(infile);
	check_file_exisit_mode(outfile, W_OK);
	pipex->outfile = ft_strdup(outfile);
	ft_printf("infile:%s\noutfile:%s\n", pipex->infile, pipex->outfile);
}
//--end of check files functions

void	check_arguments(int argc, char **argv, t_pipex *pipex, char *env[])
{
	if (argc != 5)
		ft_putstr_fd("Error\n", 2);
	else
	{
		check_files(argv[1], argv[4], pipex);
		check_commands(argv[2], argv[3], pipex, env);
	}
}

int	main(int argc, char **argv, char *env[])
{
	t_pipex	*pipex;
	int		pipefd[2];
	pid_t	pid;

	pipex = malloc(sizeof pipex);
	check_arguments(argc, argv, pipex, env);
	pipe(pipefd);
	pid = pipe(pipefd);
	return (0);
}
