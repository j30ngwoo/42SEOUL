/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_space_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:17:10 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/04/08 17:15:41 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_space(int len)
{
	int	i;

	i = 0;
	while (i++ < len)
		if (ft_putchar(' ') == -1)
			return (-1);
	return (0);
}

int	print_zero(int len)
{
	int	i;

	i = 0;
	while (i++ < len)
		if (ft_putchar('0') == -1)
			return (-1);
	return (0);
}
