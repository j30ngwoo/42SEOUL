/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:56:54 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/03/19 14:05:30 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	sub_len;
	char	*result;

	sub_len = 0;
	while (start + sub_len < ft_strlen(s) && sub_len < len)
		sub_len++;
	result = malloc(sizeof(char) * (sub_len + 1));
	if (result == 0)
		return (0);
	i = 0;
	while (i < sub_len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
