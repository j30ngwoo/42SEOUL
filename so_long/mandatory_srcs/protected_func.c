/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protected_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:05:31 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/25 12:29:00 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

ssize_t	protected_read(int fildes, void *buf, size_t nbyte)
{
	ssize_t	read_len;

	read_len = read(fildes, buf, nbyte);
	if (read_len < 0)
		perror_exit();
	return (read_len);
}

int	protected_open(const char *path, int oflag)
{
	int	fd;

	fd = open(path, oflag);
	if (fd < 0)
		perror_exit();
	return (fd);
}

void	*protected_malloc(size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(size);
	if (ptr == NULL)
		perror_exit();
	i = 0;
	while (i < size)
		((t_byte *)ptr)[i++] = 0;
	return (ptr);
}

void	*double_ptr_realloc(char **ptr, size_t size)
{
	char	**new_ptr;
	size_t	i;

	new_ptr = protected_malloc(sizeof(char **) * size);
	i = 0;
	if (ptr != NULL)
	{
		while (ptr[i])
		{
			new_ptr[i] = ptr[i];
			i++;
		}
		free(ptr);
	}
	new_ptr[i] = NULL;
	return (new_ptr);
}

char	*protected_ntoa(int n)
{
	int		str_len;
	int		temp_n;
	char	*result;

	str_len = 0;
	temp_n = n;
	while (1)
	{
		str_len++;
		temp_n /= 10;
		if (temp_n == 0)
			break ;
	}
	result = protected_malloc(sizeof(char) * (str_len + 1));
	result[str_len] = '\0';
	while (str_len)
	{
		result[--str_len] = n % 10 + '0';
		n /= 10;
	}
	return (result);
}
