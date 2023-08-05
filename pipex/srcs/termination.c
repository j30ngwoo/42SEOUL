/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:54:18 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/08/03 16:07:00 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_perror(char *message)
{
	char	*error_message;

	error_message = protected_strjoin("pipex: ", message);
	perror(error_message);
}

void	exit_with_pipex_perror(char *message)
{
	char	*error_message;

	error_message = protected_strjoin("pipex: ", message);
	perror(error_message);
	exit(1);
}

void	cmd_not_found(char *cmd_name)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(cmd_name, 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(127);
}

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}
