/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:57:09 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/04/08 15:42:16 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	reset_flag(t_flags *flag)
{
	flag->minus = 0;
	flag->zero = 0;
	flag->precision = -1;
	flag->width = 0;
	flag->hash = 0;
	flag->space = 0;
	flag->plus = 0;
	flag->specifier = 0;
}

void	set_flag(const char *format, t_flags *flag)
{
	while (!is_type(*format) && *format != '%' && *format != '\0')
	{
		if (*format == '-')
			flag->minus = 1;
		else if (*format == '0')
			flag->zero = 1;
		else if (*format == '.')
			format += set_precision(format, flag);
		else if ('1' <= *format && *format <= '9')
			format += set_width(format, flag);
		else if (*format == '#')
			flag->hash = 1;
		else if (*format == ' ')
			flag->space = 1;
		else if (*format == '+')
			flag->plus = 1;
		format++;
	}
	if (flag->precision != -1 || flag->minus == 1)
		flag->zero = 0;
	if (flag->plus == 1)
		flag->space = 0;
	flag->specifier = *format;
}

int	set_precision(const char *format, t_flags *flag)
{
	int	precision;

	format++;
	precision = natural_atoi(format);
	flag->precision = precision;
	return (count_digits(format));
}

int	set_width(const char *format, t_flags *flag)
{
	int	width;

	width = natural_atoi(format);
	if (width == -1)
		return (-1);
	flag->width = width;
	return (count_digits(format) - 1);
}

int	count_digits(const char *format)
{
	int	count;

	count = 0;
	while (ft_isdigit(*format++))
		count++;
	return (count);
}
