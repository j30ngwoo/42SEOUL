/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 23:34:33 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/04/08 16:04:57 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	int		count_printed;
	int		print_len;
	t_flags	flag;
	va_list	ap;

	count_printed = 0;
	va_start(ap, format);
	while (*format)
	{
		reset_flag(&flag);
		if (*format == '%')
			set_flag(format + 1, &flag);
		else if (ft_putchar(*format) == -1)
			return (-1);
		print_len = print_using_format(&flag, ap);
		if (print_len == -1)
			return (-1);
		count_printed += print_len;
		format += move_format_index(format);
	}
	return (count_printed);
}

int	print_using_format(t_flags *flag, va_list ap)
{
	if (flag->specifier == 'c')
		return (print_char(flag, ap));
	else if (flag->specifier == 's')
		return (print_str(flag, ap));
	else if (flag->specifier == '%')
		return (print_char(flag, ap));
	else if (flag->specifier == 'p')
		return (print_ptr(flag, ap));
	else if (flag->specifier == 'd' || flag->specifier == 'i')
		return (print_int(flag, ap));
	else if (flag->specifier == 'u')
		return (print_unsinged_int(flag, ap));
	else if (flag->specifier == 'x' || flag->specifier == 'X')
		return (print_hex(flag, ap));
	else
		return (1);
}

int	move_format_index(const char *format)
{
	int	count;

	count = 1;
	if (*format == '%')
	{
		format++;
		count++;
		while (!is_type(*format) && *format != '%' && *format != '\0')
		{
			count++;
			format++;
		}
	}
	return (count);
}

int	count_specifier(const char *format)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (*format)
	{
		if (*format == '%' && flag == 0)
			flag = 1;
		else if ((is_type(*format) == 1 || *format == '%') && flag == 1)
		{
			flag = 0;
			count++;
		}
		format++;
	}
	return (count);
}
