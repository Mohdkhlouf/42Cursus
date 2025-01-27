/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/27 10:41:42 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void Exit_print_Error()
{
    ft_putstr_fd("Error\n", 2);
    exit(-1);
}
//check commands functions
void check_files(char *cmd1, char *cmd2, t_pipex *pipex)
{
    pipex->cmd1 = cmd1;
    pipex->cmd2 = cmd2;
}
//--end of check commands functions



//++check files functions
void check_file_exisit_mode(char *filename, int mode)
{
    if (access(filename, F_OK|mode) == 0)
        return;
    else
        Exit_print_Error();
}

void check_files(char *infile, char *outfile, t_pipex *pipex)
{
    check_file_exisit_mode(infile, R_OK);
    pipex->infile = ft_strdup(infile);
    check_file_exisit_mode(outfile, W_OK);
    pipex->outfile = ft_strdup(outfile);
    ft_printf("infile:%s\noutfile:%s\n", pipex->infile, pipex->outfile);
}
//--end of check files functions



void check_arguments(int argc, char **argv, t_pipex *pipex)
{
    if(argc != 5)
            ft_putstr_fd("Error\n", 2);
    else
    {
        check_files(argv[1], argv[4], pipex);
        check_commands(argv[2], argv[3], pipex);
    }
}

int main(int argc, char **argv)
{
    t_pipex *pipex;
    pipex = malloc(sizeof pipex);

    check_arguments(argc, argv, pipex);
    return (0);
}
