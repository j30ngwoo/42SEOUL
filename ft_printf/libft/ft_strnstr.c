/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:14:51 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/03/25 21:02:54 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hay_index;
	size_t	hay_find;
	size_t	needle_find;

	if (haystack[0] == '\0' && needle[0] == '\0')
		return ((char *)haystack);
	hay_index = 0;
	while (haystack[hay_index])
	{
		needle_find = 0;
		hay_find = hay_index;
		while (haystack[hay_find] == needle[needle_find] && hay_find < len
			&& haystack[hay_find])
		{
			hay_find++;
			needle_find++;
		}
		if (needle[needle_find] == '\0')
			return ((char *)(&haystack[hay_index]));
		hay_index++;
	}
	return (0);
}
