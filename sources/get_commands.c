/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:26:41 by cmathot           #+#    #+#             */
/*   Updated: 2024/04/06 16:38:04 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	get_absolute_path_1(t_data_pipex *data)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	if (!data->command_path)
		return ;
	while (data->command_path[i])
	{
		line = ft_strjoin(data->command_path[i], data->command_args[0][0]);
		if (!line)
			dump_truck(data, EXIT_STATUS_GET_CMD);
		if (!access(line, X_OK))
		{
			data->absolute_path_cmd1 = line;
			break ;
		}
		free(line);
		i++;
	}
}

static void	get_absolute_path_2(t_data_pipex *data)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	if (!data->command_path)
		return ;
	while (data->command_path[i])
	{
		line = ft_strjoin(data->command_path[i], data->command_args[1][0]);
		if (!line)
			dump_truck(data, EXIT_STATUS_GET_CMD);
		if (!access(line, X_OK))
		{
			data->absolute_path_cmd2 = line;
			break ;
		}
		free(line);
		i++;
	}
}

void	get_second_commands(char **av, t_data_pipex *data)
{
	data->command_args[1] = ft_split(av[3], ' ');
	if (!data->command_args[1])
		dump_truck(data, EXIT_STATUS_GET_CMD);
	if (!access(data->command_args[1][0], X_OK))
	{
		data->absolute_path_cmd2 = ft_strdup(data->command_args[1][0]);
		if (!data->absolute_path_cmd2)
			dump_truck(data, EXIT_STATUS_GET_CMD);
	}
	if (data->absolute_path_cmd2 == NULL)
		get_absolute_path_2(data);
}

void	get_first_commands(char **av, t_data_pipex *data)
{
	data->command_args[0] = ft_split(av[2], ' ');
	if (!data->command_args[0])
		dump_truck(data, EXIT_STATUS_GET_CMD);
	if (!access(data->command_args[0][0], X_OK))
	{
		data->absolute_path_cmd1 = ft_strdup(data->command_args[0][0]);
		if (!data->absolute_path_cmd1)
			dump_truck(data, EXIT_STATUS_GET_CMD);
	}
	if (data->absolute_path_cmd1 == NULL)
		get_absolute_path_1(data);
}
