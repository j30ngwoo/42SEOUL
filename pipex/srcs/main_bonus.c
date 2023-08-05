/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:49:28 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/08/03 16:51:17 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex_info	info;
	int				process_index;

	info.bonus_flag = BONUS;
	if (info.bonus_flag == MANDATORY && ac != 5)
		return (1);
	if (info.bonus_flag == BONUS && ac < 5)
		return (1);
	init_info(ac, av, env, &info);
	parse_env_path(env, &info);
	process_index = 0;
	while (process_index < info.process_num)
		fork_process(process_index++, &info);
	wait_children(info.process_num);
	if (info.heredoc_flag == 1)
		protected_unlink(info.infile_name);
	free_strs(info.split_paths);
	return (0);
}
