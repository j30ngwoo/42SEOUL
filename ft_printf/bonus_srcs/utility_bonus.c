/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 04:28:38 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/04/08 12:42:54 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	natural_atoi(const char *format)
{
	long long	count;

	count = 0;
	while (ft_isdigit(*format))
	{
		count = count * 10 + *format - '0';
		if (count >= 2147483647)
			return (-1);
		format++;
	}
	return ((int)count);
}

int	is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X')
		return (1);
	else
		return (0);
}

int	set_space_len(int print_len, t_flags *flag)
{
	int	space_len;

	space_len = flag->width - print_len;
	if (space_len < 0)
		space_len = 0;
	return (space_len);
}
