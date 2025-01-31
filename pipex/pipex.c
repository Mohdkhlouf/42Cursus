/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/31 15:01:42 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	Exit_print_Error(t_pipex *pipex)
{
	ft_putstr_fd("Error\n", 2);
	free_stack(pipex);
	exit(-1);
}
// check commands functions
void	free_2d_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	check_commands_exisit_mode(char *filename, int mode, t_pipex *pipex)
{
	printf("%s , %d \n", filename, mode);
	if (access(filename, F_OK | mode) == 0)
		return ;
	else
		Exit_print_Error(pipex);
}

char	**parse_path(char *env[], t_pipex *pipex)
{
	int		i;
	char	**path;
	char	*temp;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
		{
			temp = ft_strdup(env[i] + 5);
			path = ft_split(temp, ':');
			free(temp);
			if (!path)
				Exit_print_Error(pipex);
			return (path);
		}
		i++;
	}
	return (NULL);
}

void free_multi(char *str1, char *str2, char *str3, char *str4)
{
	if(str1)
		free(str1);
	if(str2)
		free(str2);
	if(str3)
		free(str3);
	if(str4)
		free(str4);
}

void	check_accessed(char **path, char *cmd1, char *cmd2, t_pipex *pipex)
{
	int		i;
	char	*file_name1;
	char	*file_name2;

	i = 0;
	while (path[i])
	{
		if (i != 0)
		free_multi(file_name1, file_name2, NULL, NULL);
		file_name1 = ft_strjoin(path[i], cmd1);
		file_name2 = ft_strjoin(path[i], cmd2);
		if ((access(file_name1, F_OK | X_OK) == 0) && (access(file_name2,
					F_OK | X_OK) == 0))
		{
			pipex->cmd1 = ft_strdup(file_name1);
			pipex->cmd2 = ft_strdup(file_name2);
			free_multi(file_name1, file_name2, NULL, NULL);
			break;
		}
		i++;
	}
	free_multi(file_name1, file_name2, NULL, NULL);
}
void	compare_commands(char **path, char *cmd1, char *cmd2, t_pipex *pipex)
{
	int	i;

	i = 0;
	cmd1 = ft_strjoin("/", cmd1);
	cmd2 = ft_strjoin("/", cmd2);
	check_accessed(path, cmd1, cmd2, pipex);
	if(!pipex->cmd1 && !pipex->cmd1)
		Exit_print_Error(pipex);
	free(cmd1);
	free(cmd2);
}
void	check_commands(char *cmd1, char *cmd2, t_pipex *pipex, char *env[])
{
	char	**path_cmd1_arr;
	char	**path_cmd2_arr;
	int		i;
	char	**path;

	i = 0;
	path_cmd1_arr = ft_split(cmd1, ' ');
	path_cmd2_arr = ft_split(cmd2, ' ');
	path = parse_path(env, pipex);
	if (path)
		compare_commands(path, path_cmd1_arr[0], path_cmd2_arr[0], pipex);
	ft_printf("cmd1:%s\ncmd2:%s\n", pipex->cmd1, pipex->cmd2);
	free_2d_arr(path_cmd1_arr);
	free_2d_arr(path_cmd2_arr);
	free_2d_arr(path);
}
//--end of check commands functions

//++check files functions
void	check_file_exisit_mode(char *filename, int mode, t_pipex *pipex)
{
	if (access(filename, F_OK | mode) == 0)
		return ;
	else
		Exit_print_Error(pipex);
}

void	check_files(char *infile, char *outfile, t_pipex *pipex)
{
	check_file_exisit_mode(infile, R_OK, pipex);
	pipex->infile = ft_strdup(infile);
	check_file_exisit_mode(outfile, W_OK, pipex);
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
void	free_stack(t_pipex *pipex)
{
	if (pipex->infile)
		free(pipex->infile);
	if (pipex->outfile)
		free(pipex->outfile);
	if (pipex->cmd1)
		free(pipex->cmd1);
	if (pipex->cmd2)
		free(pipex->cmd2);
	free(pipex);
}

void	initialize_values(t_pipex *pipex)
{
	pipex->infile = NULL;
	pipex->outfile = NULL;
	pipex->cmd1 = NULL;
	pipex->cmd2 = NULL;
}

int	main(int argc, char **argv, char *env[])
{
	t_pipex	*pipex;
	int		pipefd[2];
	pid_t	pid;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		exit(-1);
	initialize_values(pipex);
	check_arguments(argc, argv, pipex, env);
	pipe(pipefd);
	pid = pipe(pipefd);
	free_stack(pipex);
	return (0);
}
