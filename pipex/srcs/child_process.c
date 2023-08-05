/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:56:25 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/08/03 17:11:41 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int process_index, t_pipex_info *info)
{
	if (info->heredoc_flag == 0 && process_index == 0)
		open_infile(info);
	if (info->heredoc_flag == 0 && process_index == info->process_num - 1)
		open_outfile(info);
	if (info->heredoc_flag == 1 && process_index == 0)
		read_from_stdin_save_to_tempfile(info);
	if (info->heredoc_flag == 1 && process_index == info->process_num - 1)
		open_outfile_to_append_mode(info);
	if (process_index != info->process_num - 1)
		close(info->pipe2[0]);
	set_io_pipe(process_index, info);
	exec_cmd(process_index, info);
}

void	set_io_pipe(int process_index, t_pipex_info *info)
{
	if (process_index == 0)
		dup2(info->infile_fd, STDIN_FILENO);
	else
		dup2(info->pipe1[0], STDIN_FILENO);
	if (process_index == info->process_num - 1)
		dup2(info->outfile_fd, STDOUT_FILENO);
	else
		dup2(info->pipe2[1], STDOUT_FILENO);
}

void	exec_cmd(int process_index, t_pipex_info *info)
{
	char	*cmd_name;
	char	*cmd_path;
	char	**cmd_argv;

	cmd_argv = protected_split(info->cmd_strs[process_index], ' ');
	cmd_name = cmd_argv[0];
	find_cmd_path(&cmd_path, cmd_name, info);
	execve(cmd_path, cmd_argv, info->env);
	cmd_not_found(cmd_name);
}

void	find_cmd_path(char **cmd_path, char *cmd_name, t_pipex_info *info)
{
	char	*joined_path;
	int		index;

	*cmd_path = NULL;
	index = 0;
	while (info->split_paths[index])
	{
		joined_path = protected_strjoin(info->split_paths[index++], "/");
		joined_path = protected_strjoin(joined_path, cmd_name);
		if (access(joined_path, X_OK) == 0)
			*cmd_path = joined_path;
		else
			free(joined_path);
	}
	if (access(cmd_name, X_OK) == 0)
		*cmd_path = joined_path;
}
