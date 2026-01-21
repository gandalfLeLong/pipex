/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:20:37 by cmathot           #+#    #+#             */
/*   Updated: 2024/04/07 15:48:00 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*------------DEFINES------------*/
# define EXIT_STATUS_GET_CMD 2
# define EXIT_STATUS_PIPE 3
# define EXIT_STATUS_FORK 4

/*------------INCLUDES-----------*/
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <sys/wait.h>

/*------------STRUCTURES---------*/
typedef struct s_data_pipex
{
	int		exit_status;
	int		in_file_open;
	int		out_file_open;
	int		infile_fd;
	int		outfile_fd;
	int		fd[2];
	char	*absolute_path_cmd1;
	char	*absolute_path_cmd2;
	char	**command_path;
	char	**command_args[2];

}	t_data_pipex;

/*------------FUNCTIONS----------*/

//pipex_utils.c
int		is_empty_or_spaces(char *s);
void	dump_truck(t_data_pipex *data, int exit_status);
void	open_files(int ac, char **av, t_data_pipex *data);
void	init_pipex(t_data_pipex *data);

//get_path.c
void	get_path(char **envp, t_data_pipex *data);

//get_commands
void	get_first_commands(char **av, t_data_pipex *data);
void	get_second_commands(char **av, t_data_pipex *data);

//exec_command.c
void	exec_command(t_data_pipex *data, char **argv, char **envp);

#endif
