/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:46:01 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/04/09 18:45:46 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;
	size_t	i;

	result = malloc(count * size);
	if (result == 0)
		return (0);
	i = 0;
	while (i < count * size)
		result[i++] = 0;
	return ((void *)result);
}
