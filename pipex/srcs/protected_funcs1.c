/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protected_funcs1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:25:24 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/08/02 11:47:01 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**protected_split(char const *s, char c)
{
	char	**result;

	result = ft_split(s, c);
	if (result == NULL)
		exit_with_pipex_perror("malloc()");
	return (result);
}

void	*protected_calloc(size_t count, size_t size)
{
	char	*result;

	result = ft_calloc(count, size);
	if (result == NULL)
		exit_with_pipex_perror("malloc()");
	return (result);
}

void	protected_pipe(int fd[2])
{
	if (pipe(fd) == -1)
		exit_with_pipex_perror("pipe()");
}

int	protected_close(int fd)
{
	int	return_value;

	return_value = close(fd);
	if (return_value == -1)
		exit_with_pipex_perror("close()");
	return (return_value);
}

char	*protected_strndup(const char *s1, size_t n)
{
	char	*result;

	result = ft_strndup(s1, n);
	if (result == NULL)
		exit_with_pipex_perror("malloc()");
	return (result);
}
