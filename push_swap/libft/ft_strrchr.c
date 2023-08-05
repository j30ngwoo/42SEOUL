/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:47:41 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/03/19 11:32:59 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = 0;
	while (*s)
	{
		if (*s == (char)c)
			result = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		result = (char *)s;
	return (result);
}
