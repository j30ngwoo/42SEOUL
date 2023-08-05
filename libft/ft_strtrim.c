/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:19:01 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/03/19 16:06:49 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	left;
	size_t	right;
	char	*result;

	if (s1 == 0 || *s1 == '\0')
		return (ft_calloc(1, sizeof(char)));
	left = 0;
	while (s1[left] && is_set(s1[left], set))
		left++;
	right = ft_strlen(s1);
	while (s1[right - 1] && is_set(s1[right - 1], set) && left < right - 1)
		right--;
	result = ft_calloc(right - left + 1, sizeof(char));
	if (result == 0)
		return (0);
	i = 0;
	while (left < right)
		result[i++] = s1[left++];
	result[i] = '\0';
	return (result);
}
