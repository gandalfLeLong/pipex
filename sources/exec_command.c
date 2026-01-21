/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:57:22 by cmathot           #+#    #+#             */
/*   Updated: 2024/04/07 15:50:16 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_exec_1(t_data_pipex *data, char **envp, char **argv)
{
	close(data->outfile_fd);
	close(data->fd[0]);
	dup2(data->infile_fd, STDIN_FILENO);
	close(data->infile_fd);
	dup2(data->fd[1], STDOUT_FILENO);
	close(data->fd[1]);
	if (data->in_file_open)
		exit (1);
	if (!data->absolute_path_cmd1)
	{
		if (!data->command_path)
			ft_printf(2, "bash: %s: No such file or directory\n", argv[2]);
		else
			ft_printf(2, "bash: %s: command not found\n", argv[2]);
		exit(127);
	}
	execve(data->absolute_path_cmd1, data->command_args[0], envp);
}

static void	child_exec_2(t_data_pipex *data, char **envp, char **argv)
{
	close(data->infile_fd);
	close(data->fd[1]);
	dup2(data->fd[0], STDIN_FILENO);
	close(data->fd[0]);
	dup2(data->outfile_fd, STDOUT_FILENO);
	close(data->outfile_fd);
	if (data->out_file_open)
		exit (1);
	if (!data->absolute_path_cmd2)
	{
		if (!data->command_path)
			ft_printf(2, "bash: %s: No such file or directory\n", argv[3]);
		else
			ft_printf(2, "bash: %s: command not found\n", argv[3]);
		exit(127);
	}
	execve(data->absolute_path_cmd2, data->command_args[1], envp);
}

void	exec_command(t_data_pipex *data, char **argv, char **envp)
{
	int	id1;
	int	id2;
	int	status;

	id1 = -1;
	id2 = -1;
	if (pipe(data->fd) == -1)
		dump_truck(data, EXIT_STATUS_PIPE);
	id1 = fork();
	if (id1 == -1)
		dump_truck(data, EXIT_STATUS_FORK);
	if (id1 == 0)
		child_exec_1(data, envp, argv);
	id2 = fork();
	if (id2 == -1)
		dump_truck(data, EXIT_STATUS_FORK);
	if (id2 == 0)
		child_exec_2(data, envp, argv);
	close(data->fd[0]);
	close(data->fd[1]);
	waitpid(id1, NULL, 0);
	waitpid(id2, &status, 0);
	if (WIFEXITED(status))
		data->exit_status = WEXITSTATUS(status);
}
