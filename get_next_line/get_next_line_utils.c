/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:29:49 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/05/26 13:22:16 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_str(char *str)
{
	if (str != NULL)
		free(str);
	return (NULL);
}

void	ft_strncpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
}

void	ft_memncpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

char	*ft_realloc(char *str, int size)
{
	char	*temp;

	temp = str;
	str = malloc(size);
	if (str == NULL)
		return (free_str(temp));
	if (temp != NULL)
		ft_strncpy(str, temp, size);
	free_str(temp);
	return (str);
}
