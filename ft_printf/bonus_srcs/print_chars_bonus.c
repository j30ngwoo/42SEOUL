/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:33:43 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/04/08 16:08:05 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_char(t_flags *flag, va_list ap)
{
	if (flag->minus == 0 && print_space(flag->width - 1) == -1)
		return (-1);
	if (flag->specifier == '%' && ft_putchar('%') == -1)
		return (-1);
	if (flag->specifier != '%' && ft_putchar(va_arg(ap, int)) == -1)
		return (-1);
	if (flag->minus == 1 && print_space(flag->width - 1) == -1)
		return (-1);
	return (ft_max(1, flag->width));
}

int	print_str(t_flags *flag, va_list ap)
{
	int		print_len;
	int		space_len;
	char	*str;

	str = va_arg(ap, char *);
	if (str == 0 && flag->precision >= 0)
		print_len = ft_min(flag->precision, ft_strlen("(null)"));
	else if (str == 0)
		print_len = ft_strlen("(null)");
	else if (flag->precision >= 0)
		print_len = ft_min(flag->precision, ft_strlen(str));
	else
		print_len = ft_strlen(str);
	space_len = flag->width - print_len;
	if (space_len < 0)
		space_len = 0;
	if (flag->minus == 0 && print_space(space_len) == -1)
		return (-1);
	if (str == 0 && ft_putnstr("(null)", print_len) == -1)
		return (-1);
	if (str != 0 && ft_putnstr(str, print_len) == -1)
		return (-1);
	if (flag->minus == 1 && print_space(space_len) == -1)
		return (-1);
	return (print_len + space_len);
}
