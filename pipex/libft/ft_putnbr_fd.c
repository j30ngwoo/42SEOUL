/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:52:41 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/03/21 18:00:18 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursion(int n, int sign, int fd)
{
	if (n == 0)
		return ;
	recursion(n / 10, sign, fd);
	ft_putchar_fd(n % 10 * sign + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		ft_putchar_fd('-', fd);
	}
	recursion(n, sign, fd);
}
