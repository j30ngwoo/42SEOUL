/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:00:22 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/03/28 22:05:51 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(va_list ap)
{
	unsigned long long	ptr;
	int					print_len;

	ptr = va_arg(ap, unsigned long long);
	if (ft_putstr("0x") == -1)
		return (-1);
	if (ptr == 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		return (3);
	}
	print_len = recursion_ptr(ptr);
	if (print_len == -1)
		return (-1);
	return (print_len + 2);
}

int	recursion_ptr(unsigned long long ptr)
{
	int	prev_len;

	if (ptr == 0)
		return (0);
	prev_len = recursion_ptr(ptr / 16);
	if (prev_len == -1 || ft_putchar("0123456789abcdef"[ptr % 16]) == -1)
		return (-1);
	return (prev_len + 1);
}
