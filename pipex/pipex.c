/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/30 16:31:01 by mkhlouf          ###   ########.fr       */
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

char **parse_path(char *env[])
{
    int i;
    char **path;
    i = 0;
    while (env[i])
    {
        if (ft_strnstr(env[i], "PATH=", 5))
        {
            printf("%s", env[i]);
            path = ft_split(ft_strdup(env[i]),":");
            if(!path)
                Exit_print_Error();
            return (path);
        } 
        i++;
    }
    return (NULL);
}

void compare_commands(char *path, char * cmd1, char * cmd2)
{
    int i;
    
    i = 0;
    while ( path[i])
    {
        if (check_commands_exisit_mode());
    }
        
            
    
    
}
void check_commands(char *cmd1, char *cmd2, t_pipex *pipex, char *env[])
{
    char **path_cmd1_arr;
    char **path_cmd2_arr;
    char *path_cmd1;
    char *path_cmd2;
    int i;
    char **path;
    
    i = 0;
    path_cmd1_arr = ft_split(cmd1, ' ');
    path_cmd2_arr = ft_split(cmd2, ' ');
    
    path = parse_path(env);
    if (path)
        compare_commands(path, path_cmd1_arr[0], path_cmd2_arr[0]);
    // path_cmd1 = ft_strjoin("/bin/", path_cmd1_arr[0]);
    // path_cmd2 = ft_strjoin("/bin/", path_cmd2_arr[0]);
    // check_commands_exisit_mode(path_cmd1, X_OK);
    // check_commands_exisit_mode(path_cmd2, X_OK);
    // pipex->cmd1 = ft_strdup(path_cmd1);
    // pipex->cmd2 = ft_strdup(path_cmd2);
    
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



void check_arguments(int argc, char **argv, t_pipex *pipex, char *env[])
{
    if(argc != 5)
            ft_putstr_fd("Error\n", 2);
    else
    {
        check_files(argv[1], argv[4], pipex);
        check_commands(argv[2], argv[3], pipex, env);
    }
}

int main(int argc, char **argv, char *env[] )
{
    t_pipex *pipex;
    int pipefd[2];

    pid_t pid;
    pipex = malloc(sizeof pipex);
    check_arguments(argc, argv, pipex, env);

    pipe(pipefd);
    pid = pipe(pipefd);
    return (0);
}
