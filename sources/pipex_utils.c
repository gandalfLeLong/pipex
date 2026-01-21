/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:18:34 by cmathot           #+#    #+#             */
/*   Updated: 2024/04/08 12:43:09 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_empty_or_spaces(char *s)
{
	int	i;

	i = 0;
	if (!s[0])
		return (1);
	while (s[i])
	{
		if (s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	init_pipex(t_data_pipex *data)
{
	data->exit_status = 0;
	data->in_file_open = 0;
	data->out_file_open = 0;
	data->infile_fd = -1;
	data->outfile_fd = -1;
	data->absolute_path_cmd1 = NULL;
	data->absolute_path_cmd2 = NULL;
	data->command_path = NULL;
	data->command_args[0] = NULL;
	data->command_args[1] = NULL;
}

void	open_files(int ac, char **av, t_data_pipex *data)
{
	data->infile_fd = open(av[1], O_RDONLY);
	if (data->infile_fd == -1)
	{
		if (errno == EACCES)
			ft_printf(2, "bash: %s: Permission denied\n", av[1]);
		else if (errno == ENOENT)
			ft_printf(2, "bash: %s: No such file or directory\n", av[1]);
		data->in_file_open = 1;
	}
	data->outfile_fd = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (data->outfile_fd == -1)
	{
		ft_printf(2, "bash: %s: Permission denied\n", av[4]);
		data->out_file_open = 1;
	}
}

static void	ft_error(int exit_status)
{
	if (exit_status == 1)
		ft_printf(2, "ISSUE GETTING THE COMMAND\n");
	if (exit_status == 2)
		ft_printf(2, "ISSUE OPENING THE PIPE\n");
	if (exit_status == 3)
		ft_printf(2, "ISSUE DOING THE FORK\n");
}

void	dump_truck(t_data_pipex *data, int exit_status)
{
	ft_free_tab(data->command_args[0]);
	ft_free_tab(data->command_args[1]);
	ft_free_tab(data->command_path);
	if (data->absolute_path_cmd1)
		free(data->absolute_path_cmd1);
	if (data->absolute_path_cmd2)
		free(data->absolute_path_cmd2);
	close(data->infile_fd);
	close(data->outfile_fd);
	if (exit_status == EXIT_STATUS_FORK)
	{
		close(data->fd[0]);
		close(data->fd[1]);
	}
	if (exit_status)
	{
		ft_error(exit_status);
		exit(exit_status);
	}
}
