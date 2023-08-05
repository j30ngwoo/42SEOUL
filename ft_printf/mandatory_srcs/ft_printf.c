/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 23:34:33 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/03/28 22:25:12 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		count_printed;
	int		print_len;
	va_list	ap;

	count_printed = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			print_len = print_using_format(format + 1, ap);
			if (print_len == -1)
				return (-1);
			format += 2;
		}
		else
		{
			if (ft_putchar(*format) == -1)
				return (-1);
			print_len = 1;
			format++;
		}
		count_printed += print_len;
	}
	return (count_printed);
}

int	print_using_format(const char *format, va_list ap)
{
	if (*format == 'c')
		return (print_char(ap));
	else if (*format == 's')
		return (print_str(ap));
	else if (*format == 'p')
		return (print_ptr(ap));
	else if (*format == 'd' || *format == 'i')
		return (print_int(ap));
	else if (*format == 'u')
		return (print_uint(ap));
	else if (*format == 'x' || *format == 'X')
		return (print_hex(ap, *format));
	else if (*format == '%')
		return (print_percent());
	else
		return (0);
}
