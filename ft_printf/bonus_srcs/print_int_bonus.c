/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 05:13:36 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/04/08 15:48:42 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_int(t_flags *flag, va_list ap)
{
	int	n;
	int	print_len;
	int	space_len;

	n = va_arg(ap, int);
	if (flag->precision == 0 && n == 0)
		print_len = 0;
	else
		print_len = ft_max(count_int_len(n), flag->precision);
	if (flag->space == 1 || flag->plus == 1 || n < 0)
		print_len++;
	space_len = set_space_len(print_len, flag);
	if (flag->minus == 0 && flag->zero == 0 && print_space(space_len) == -1)
		return (-1);
	if (print_int_sign(n, flag) == -1)
		return (-1);
	if (flag->minus == 0 && flag->zero == 1 && print_zero(space_len) == -1)
		return (-1);
	if (putint_using_format(n, flag) == -1)
		return (-1);
	if (flag->minus == 1 && print_space(space_len) == -1)
		return (-1);
	return (print_len + space_len);
}

int	print_int_sign(int n, t_flags *flag)
{
	if (flag->plus == 1 && n >= 0 && ft_putchar('+') == -1)
		return (-1);
	if (flag->space == 1 && n >= 0 && ft_putchar(' ') == -1)
		return (-1);
	if (n < 0 && ft_putchar('-') == -1)
		return (-1);
	return (0);
}

int	putint_using_format(int n, t_flags *flag)
{
	if (flag->precision == 0 && n == 0)
		return (0);
	if (flag->precision != -1 && flag->precision - count_int_len(n) > 0)
		if (print_zero(flag->precision - count_int_len(n)) == -1)
			return (-1);
	if (putint_nosign(n) == -1)
		return (-1);
	return (0);
}

int	putint_nosign(int n)
{
	int		sign;
	int		index;
	char	result[11];

	if (n == 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		return (0);
	}
	sign = 1;
	if (n < 0)
		sign = -1;
	index = count_int_len(n);
	result[index] = '\0';
	while (--index >= 0)
	{
		result[index] = (n % 10) * sign + '0';
		n /= 10;
	}
	if (ft_putstr(result) == -1)
		return (-1);
	return (0);
}

int	count_int_len(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}
