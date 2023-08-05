/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 05:18:14 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/04/08 15:50:36 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_unsinged_int(t_flags *flag, va_list ap)
{
	unsigned int	n;
	int				print_len;
	int				space_len;

	n = va_arg(ap, unsigned int);
	if (flag->precision == 0 && n == 0)
		print_len = 0;
	else
		print_len = ft_max(count_uint_len(n), flag->precision);
	space_len = set_space_len(print_len, flag);
	if (flag->minus == 0 && flag->zero == 1 && print_zero(space_len) == -1)
		return (-1);
	if (flag->minus == 0 && flag->zero == 0 && print_space(space_len) == -1)
		return (-1);
	if (putuint_using_format(n, flag) == -1)
		return (-1);
	if (flag->minus == 1 && print_space(space_len) == -1)
		return (-1);
	return (print_len + space_len);
}

int	putuint_using_format(unsigned int n, t_flags *flag)
{
	if (flag->precision == 0 && n == 0)
		return (0);
	if (flag->precision != -1 && flag->precision - count_uint_len(n) > 0)
		if (print_zero(flag->precision - count_uint_len(n)) == -1)
			return (-1);
	if (putuint(n) == -1)
		return (-1);
	return (0);
}

int	putuint(unsigned int n)
{
	int		index;
	char	result[11];

	if (n == 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		return (0);
	}
	index = count_uint_len(n);
	result[index] = '\0';
	while (--index >= 0)
	{
		result[index] = (n % 10) + '0';
		n /= 10;
	}
	if (ft_putstr(result) == -1)
		return (-1);
	return (0);
}

int	count_uint_len(unsigned int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}
