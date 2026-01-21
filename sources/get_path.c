/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:42:59 by cmathot           #+#    #+#             */
/*   Updated: 2024/04/06 16:36:40 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_put_slash(t_data_pipex *data)
{
	int		i;
	char	*cp;

	i = 0;
	if (!data->command_path)
		return ;
	while (data->command_path[i])
	{
		cp = data->command_path[i];
		data->command_path[i] = ft_strjoin(data->command_path[i], "/");
		free(cp);
		if (!data->command_path[i])
			dump_truck(data, EXIT_STATUS_GET_CMD);
		i++;
	}
}

static char	**add_to_path(char *str, t_data_pipex *data)
{
	char	*line;
	char	**path;

	line = ft_strtrim(str, "PATH=");
	if (!line)
		dump_truck(data, EXIT_STATUS_GET_CMD);
	path = ft_split(line, ':');
	free(line);
	if (!path)
		dump_truck(data, EXIT_STATUS_GET_CMD);
	return (path);
}

static int	is_path(char *str)
{
	if (str[0] != 'P')
		return (0);
	if (str[1] != 'A')
		return (0);
	if (str[2] != 'T')
		return (0);
	if (str[3] != 'H')
		return (0);
	if (str[4] != '=')
		return (0);
	return (1);
}

void	get_path(char **envp, t_data_pipex *data)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (is_path(envp[i]))
		{
			data->command_path = add_to_path(envp[i], data);
			break ;
		}
		i++;
	}
	ft_put_slash(data);
}
