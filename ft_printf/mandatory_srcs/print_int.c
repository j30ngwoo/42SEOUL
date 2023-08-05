/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:03:12 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/03/28 22:47:40 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(va_list ap)
{
	int	n;
	int	print_len;

	n = va_arg(ap, int);
	if (n == 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		return (1);
	}
	if (n > 0)
		print_len = recursion_int(n, 1);
	else
	{
		if (ft_putchar('-') == -1)
			return (-1);
		print_len = recursion_int(n, -1) + 1;
	}
	if (print_len == -1)
		return (-1);
	return (print_len);
}

int	recursion_int(int n, int sign)
{
	int	prev_len;

	if (n == 0)
		return (0);
	prev_len = recursion_int(n / 10, sign);
	if (prev_len == -1 || ft_putchar(n % 10 * sign + '0') == -1)
		return (-1);
	return (prev_len + 1);
}

int	print_uint(va_list ap)
{
	unsigned int	n;
	int				print_len;

	n = va_arg(ap, unsigned int);
	if (n == 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		return (1);
	}
	print_len = recursion_uint(n);
	if (print_len == -1)
		return (-1);
	return (print_len);
}

int	recursion_uint(unsigned int n)
{
	int	prev_len;

	if (n == 0)
		return (0);
	prev_len = recursion_uint(n / 10);
	if (prev_len == -1 || ft_putchar(n % 10 + '0') == -1)
		return (-1);
	return (prev_len + 1);
}
