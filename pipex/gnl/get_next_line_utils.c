/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:29:49 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/18 17:34:48 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_str(char *str)
{
	if (str != NULL)
		free(str);
	return (NULL);
}

void	gnl_strncpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
}

void	gnl_memncpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

char	*gnl_realloc(char *str, int size)
{
	char	*temp;

	temp = str;
	str = malloc(size);
	if (str == NULL)
		return (free_str(temp));
	if (temp != NULL)
		gnl_strncpy(str, temp, size);
	free_str(temp);
	return (str);
}
