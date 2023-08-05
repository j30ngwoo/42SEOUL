/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protected_funcs2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:04:56 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/08/02 14:20:37 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*protected_strjoin(char const *s1, char const *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	if (result == NULL)
		exit_with_pipex_perror("malloc()");
	return (result);
}

void	*protected_realloc(void *ptr, size_t size)
{
	void	*result;

	if (ptr == NULL)
		result = protected_calloc(1, size);
	else
	{
		result = protected_calloc(1, size);
		ft_strcpy(result, ptr);
		free(ptr);
	}
	return (result);
}

char	*protected_strdup(const char *s1)
{
	char	*result;

	result = ft_strdup(s1);
	if (result == NULL)
		exit_with_pipex_perror("malloc()");
	return (result);
}

char	*protected_itoa(int n)
{
	char	*result;

	result = ft_itoa(n);
	if (result == NULL)
		exit_with_pipex_perror("malloc()");
	return (result);
}

int	protected_unlink(const char *pathname)
{
	int	result;

	if (access(pathname, F_OK) != 0)
		return (-1);
	result = unlink(pathname);
	if (result != 0)
		exit_with_pipex_perror("unlink()");
	return (result);
}
