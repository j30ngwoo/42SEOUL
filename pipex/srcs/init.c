/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:18:53 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/08/02 18:48:22 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_info(int ac, char **av, char **env, t_pipex_info *info)
{
	info->env = env;
	if (info->bonus_flag == BONUS && ft_strcmp(av[1], "here_doc") == 0)
	{
		info->heredoc_flag = 1;
		info->limiter = av[2];
		info->process_num = ac - 4;
		info->cmd_strs = av + 3;
		select_new_tempfile(info);
		info->outfile_name = av[ac - 1];
	}
	else
	{
		info->heredoc_flag = 0;
		info->limiter = NULL;
		info->process_num = ac - 3;
		info->cmd_strs = av + 2;
		info->infile_name = av[1];
		info->outfile_name = av[ac - 1];
	}
}

void	parse_env_path(char **env, t_pipex_info *info)
{
	int		index;

	info->split_paths = NULL;
	index = 0;
	while (env[index])
	{
		if (ft_strncmp("PATH=", env[index], 5) == 0)
			info->split_paths = protected_split(env[index] + 5, ':');
		index++;
	}
	if (info->split_paths == NULL)
		info->split_paths = protected_calloc(1, sizeof(char *));
	if (info->split_paths[0] == NULL)
		info->split_paths[0] = protected_calloc(1, sizeof(char));
}
