/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 23:48:38 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/16 18:15:42 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsdup(char **strs)
{
	char	**result;
	int		len;
	int		i;

	len = 0;
	while (strs[len])
		len++;
	result = malloc(sizeof(char *) * (len + 1));
	if (result == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		result[i] = ft_strdup(strs[i]);
		if (result[i] == NULL)
		{
			while (--i >= 0)
				free(strs[i]);
			free(result);
			return (0);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
