/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:37:25 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/03/21 17:30:20 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_int_len(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		len;
	char	*result;

	len = count_int_len(n);
	result = ft_calloc(len + 1, sizeof(char));
	if (result == 0)
		return (0);
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		result[0] = '-';
	}
	if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		result[--len] = n % 10 * sign + '0';
		n /= 10;
	}
	return (result);
}
