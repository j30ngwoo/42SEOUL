/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:44:55 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/08/02 10:11:57 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_process(int process_index, t_pipex_info *info)
{
	pid_t	pid;

	if (process_index != info->process_num - 1)
		protected_pipe(info->pipe2);
	pid = protected_fork(process_index);
	if (pid == 0)
		child_process(process_index, info);
	else
		parent_process_after_fork(process_index, info);
}

pid_t	protected_fork(int process_index)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		wait_children(process_index);
		exit_with_pipex_perror("fork()");
	}
	return (pid);
}

void	wait_children(int child_num)
{
	int	child_index;
	int	status;

	child_index = 0;
	while (child_index++ < child_num)
		wait(&status);
}

void	parent_process_after_fork(int process_index, t_pipex_info *info)
{
	if (process_index != 0)
	{
		protected_close(info->pipe1[0]);
	}
	if (process_index != info->process_num - 1)
	{
		transfer_pipe2_to_pipe1(info->pipe1, info->pipe2);
		protected_close(info->pipe1[1]);
	}
}

void	transfer_pipe2_to_pipe1(int pipe1[2], int pipe2[2])
{
	pipe1[0] = pipe2[0];
	pipe1[1] = pipe2[1];
}
