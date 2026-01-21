/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:20:26 by cmathot           #+#    #+#             */
/*   Updated: 2024/04/06 16:59:08 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data_pipex	data;

	if (ac != 5)
		return (ft_printf(2, "WRONG NUMBERS OF ARGUMENTS\n"), 1);
	init_pipex(&data);
	open_files(ac, av, &data);
	if (envp)
		get_path(envp, &data);
	if (!is_empty_or_spaces(av[2]))
		get_first_commands(av, &data);
	if (!is_empty_or_spaces(av[3]))
		get_second_commands(av, &data);
	exec_command(&data, av, envp);
	dump_truck(&data, 0);
	return (data.exit_status);
}
