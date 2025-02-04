/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/04 18:20:48 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_files(char *infile, char *outfile, t_pipex *pipex)
{
	int	fd;

	check_file_exisit_mode(infile, R_OK, pipex);
	pipex->infile = ft_strdup(infile);
	if (access(outfile, F_OK) == 0)
	{
		if (access(outfile, W_OK) == 0)
			pipex->outfile = ft_strdup(outfile);
		else
			exit_print_error(pipex);
	}
	else
	{
		fd = open(outfile, O_CREAT | O_TRUNC, 0777);
		if (fd > -1)
			pipex->outfile = ft_strdup(outfile);
		close(fd);
	}
}

void	check_arguments(int argc, char **argv, t_pipex *pipex, char *env[])
{
	if (argc != 5)
	{
		ft_putstr_fd("Error\n", 2);
		free(pipex->cmds);
		free(pipex);
		exit(1);
	}
	else
	{
		check_files(argv[1], argv[4], pipex);
		check_commands(argv[2], argv[3], pipex, env);
	}
}

void	check_file_exisit_mode(char *filename, int mode, t_pipex *pipex)
{
	if (access(filename, F_OK | mode) == 0)
		return ;
	else
	{
		ft_putstr_fd("Error\n", 2);
		free(pipex->cmds);
		free(pipex);
		exit(1);
	}
}

char	**parse_path(char *env[], t_pipex *pipex)
{
	int		i;
	char	**parse_path;
	char	*result;

	i = 0;
	parse_path = NULL;
	result = NULL;
	while (env[i])
	{
		result = ft_strnstr(env[i], "PATH=", 5);
		if (result)
		{

			parse_path = ft_split(result + 5, ':');
			if (!parse_path)
			{
				ft_putstr_fd("Error\n", 2);
				free_stack(pipex);
				exit(1);
			}
			return (parse_path);
		}
		i++;
	}
	free_2d_arr(parse_path);
	return (NULL);
}


