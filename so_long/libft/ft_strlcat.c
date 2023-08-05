/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:09:01 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/08 19:16:40 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_index;

	dst_len = 0;
	src_index = 0;
	while (*dst)
	{
		dst_len++;
		dst++;
	}
	if (dstsize < dst_len)
	{
		while (src[src_index])
			src_index++;
		return (src_index + dstsize);
	}
	while (*src && dst_len + src_index + 1 < dstsize)
	{
		*dst++ = *src++;
		src_index++;
	}
	*dst = '\0';
	while (*src++)
		src_index++;
	return (dst_len + src_index);
}
