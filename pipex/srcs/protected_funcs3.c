/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protected_funcs3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:23:40 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/08/03 17:06:00 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*protected_get_next_line(int fd)
{
	char	*result;

	result = get_next_line(fd);
	if (result == NULL)
		exit_with_pipex_perror("malloc()");
	return (result);
}

ssize_t	protected_read(int fildes, void *buf, size_t nbyte)
{
	ssize_t	result;

	result = read(fildes, buf, nbyte);
	if (result == -1)
		exit_with_pipex_perror("read()");
	return (result);
}

int	protected_open(const char *path, int oflag, mode_t mode)
{
	int	result;

	result = open(path, oflag, mode);
	if (result == -1)
		exit_with_pipex_perror("open()");
	return (result);
}
