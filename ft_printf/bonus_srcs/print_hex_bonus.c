/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 06:38:33 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/05/07 20:13:19 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_hex(t_flags *flag, va_list ap)
{
	unsigned int	n;
	int				print_len;
	int				space_len;

	n = va_arg(ap, unsigned int);
	if (flag->precision == 0 && n == 0)
		print_len = 0;
	else
		print_len = ft_max(count_hex_len(n), flag->precision);
	if (flag->hash == 1 && n != 0)
		print_len += 2;
	space_len = set_space_len(print_len, flag);
	if (flag->minus == 0 && flag->zero == 0 && print_space(space_len) == -1)
		return (-1);
	if (print_0x(n, flag) == -1)
		return (-1);
	if (flag->minus == 0 && flag->zero == 1 && print_zero(space_len) == -1)
		return (-1);
	if (puthex_using_format(n, flag) == -1)
		return (-1);
	if (flag->minus == 1 && print_space(space_len) == -1)
		return (-1);
	return (print_len + space_len);
}

int	puthex_using_format(unsigned int n, t_flags *flag)
{
	if (flag->precision != -1 && flag->precision - count_hex_len(n) > 0)
		if (print_zero(flag->precision - count_hex_len(n)) == -1)
			return (-1);
	if (flag->precision == 0 && n == 0)
		return (0);
	if (puthex(n, flag) == -1)
		return (-1);
	return (0);
}

int	puthex(unsigned int n, t_flags *flag)
{
	int		index;
	char	result[9];

	if (n == 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		return (0);
	}
	index = count_hex_len(n);
	result[index] = '\0';
	while (--index >= 0)
	{
		if (flag->specifier == 'x')
			result[index] = "0123456789abcdef"[n % 16];
		else
			result[index] = "0123456789ABCDEF"[n % 16];
		n /= 16;
	}
	if (ft_putstr(result) == -1)
		return (-1);
	return (0);
}

int	count_hex_len(unsigned int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		count++;
		n /= 16;
	}
	return (count);
}

int	print_0x(unsigned int n, t_flags *flag)
{
	if (flag->hash == 1 && flag->specifier == 'x' && n != 0
		&& ft_putstr("0x") == -1)
		return (-1);
	if (flag->hash == 1 && flag->specifier == 'X' && n != 0
		&& ft_putstr("0X") == -1)
		return (-1);
	return (0);
}
