/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/29 15:27:27 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void Exit_print_Error()
{
    ft_putstr_fd("Error\n", 2);
    exit(-1);
}
//check commands functions
// void free_2d_arr(char **arr)
// {
//     while (*arr)
//     {
//         free(*arr);
//         arr++;
//     }
//     free(arr);
// }

void check_commands_exisit_mode(char *filename, int mode)
{
    if (access(filename, F_OK|mode) == 0)
        return;
    else
        Exit_print_Error();
}


void check_commands(char *cmd1, char *cmd2, t_pipex *pipex)
{
    char **path_cmd1_arr;
    char **path_cmd2_arr;
    char *path_cmd1;
    char *path_cmd2;

    path_cmd1_arr = ft_split(cmd1, ' ');
    path_cmd2_arr = ft_split(cmd2, ' ');
    
    path_cmd1 = ft_strjoin("/bin/", path_cmd1_arr[0]);
    path_cmd2 = ft_strjoin("/bin/", path_cmd2_arr[0]);
    check_commands_exisit_mode(path_cmd1, X_OK);
    check_commands_exisit_mode(path_cmd2, X_OK);
    pipex->cmd1 = ft_strdup(path_cmd1);
    pipex->cmd2 = ft_strdup(path_cmd2);
    // free_2d_arr(path_cmd1_arr);
    // free_2d_arr(path_cmd2_arr);
    // free(path_cmd1);
    // free(path_cmd2);
   
    ft_printf("cmd1 path:#%s#\ncmd2 path:#%s#\n", pipex->cmd1 , pipex->cmd2);

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

int main(int argc, char **argv, char *env[] )
{
    t_pipex *pipex;
    int pipefd[2];

    pid_t pid;
    
    pipex = malloc(sizeof pipex);
    check_arguments(argc, argv, pipex);

    pipe(pipefd);
    
    return (0);
}
