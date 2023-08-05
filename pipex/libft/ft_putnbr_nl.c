/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:21:39 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/26 09:44:55 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursion(int n, int sign)
{
	if (n == 0)
		return ;
	recursion(n / 10, sign);
	ft_putchar(n % 10 * sign + '0');
}

void	ft_putnbr_nl(int n)
{
	int	sign;

	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		ft_putchar('-');
	}
	recursion(n, sign);
	ft_putchar('\n');
}
