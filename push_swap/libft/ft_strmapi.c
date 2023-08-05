/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:27:40 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/03/21 17:36:04 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*result;

	result = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (result == 0)
		return (0);
	index = 0;
	while (s[index])
	{
		result[index] = f(index, s[index]);
		index++;
	}
	return (result);
}
