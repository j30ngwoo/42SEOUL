/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:09:01 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/03/19 10:59:51 by jeongwoo         ###   ########.fr       */
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

/*
#include    <iostream>
using namespace std;
int main(void)
{
	char src[100] = "1232131231";
	char dst1[100] = "ab";
	char dst2[100] = "ab";
	int dstsize = 6;

	cout << ft_strlcat(dst2, src, dstsize) << ' ' << dst2 << '\n';
	cout << strlcat(dst1, src, dstsize) << ' ' << dst1 << '\n';

	return (0);
}*/