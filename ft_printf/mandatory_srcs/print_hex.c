/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:19:08 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/03/28 22:25:49 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(va_list ap, char x_or_X)
{
	unsigned int	hex;
	int				print_len;

	hex = va_arg(ap, unsigned int);
	if (hex == 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		return (1);
	}
	print_len = recursion_hex(hex, x_or_X);
	if (print_len == -1)
		return (-1);
	return (print_len);
}

int	recursion_hex(unsigned int hex, char x_or_X)
{
	int	prev_len;

	if (hex == 0)
		return (0);
	prev_len = recursion_hex(hex / 16, x_or_X);
	if (prev_len == -1)
		return (-1);
	if (x_or_X == 'x' && ft_putchar("0123456789abcdef"[hex % 16]) == -1)
		return (-1);
	if (x_or_X == 'X' && ft_putchar("0123456789ABCDEF"[hex % 16]) == -1)
		return (-1);
	return (prev_len + 1);
}
