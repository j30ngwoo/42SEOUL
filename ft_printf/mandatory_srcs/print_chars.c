/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:02:21 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/03/28 22:46:25 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list ap)
{
	if (ft_putchar(va_arg(ap, int)) == -1)
		return (-1);
	return (1);
}

int	print_str(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (str == 0)
	{
		if (ft_putstr("(null)") == -1)
			return (-1);
		return (6);
	}
	if (ft_putstr(str) == -1)
		return (-1);
	return (ft_strlen(str));
}

int	print_percent(void)
{
	if (ft_putchar('%') == -1)
		return (-1);
	return (1);
}
