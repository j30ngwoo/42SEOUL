/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:44:30 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/03/31 16:31:25 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_ptr(t_flags *flag, va_list ap)
{
	unsigned long long	n;
	int					print_len;
	int					space_len;

	n = va_arg(ap, unsigned long long);
	print_len = count_ptr_len(n) + 2;
	space_len = flag->width - print_len;
	if (space_len < 0)
		space_len = 0;
	if (flag->minus == 0 && print_space(space_len) == -1)
		return (-1);
	if (putptr_using_format(n) == -1)
		return (-1);
	if (flag->minus == 1 && print_space(space_len) == -1)
		return (-1);
	return (print_len + space_len);
}

int	putptr_using_format(unsigned long long n)
{
	char	result[17];
	int		index;

	if (ft_putstr("0x") == -1)
		return (-1);
	if (n == 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		return (0);
	}
	index = count_ptr_len(n);
	result[index] = '\0';
	while (--index >= 0)
	{
		result[index] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	if (ft_putstr(result) == -1)
		return (-1);
	return (0);
}

int	count_ptr_len(unsigned long long n)
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
