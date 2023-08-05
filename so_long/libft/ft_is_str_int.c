/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:30:06 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/08 20:41:49 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_str_int(char *str)
{
	long long	n;
	long long	negative;

	if (str == 0)
		return (0);
	negative = 1;
	if (*str == '-')
	{
		str++;
		negative = -1;
	}
	if (!ft_isdigit(*str))
		return (0);
	n = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		n = n * 10 + negative * (*str - '0');
		if (!(-2147483648 <= n && n <= 2147483647))
			return (0);
		str++;
	}
	return (1);
}
