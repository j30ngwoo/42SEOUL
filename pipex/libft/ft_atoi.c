/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:29:21 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/04/09 18:45:22 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	result = 0;
	while ('0' <= *str && *str <= '9')
		result = result * 10 + sign * ((*(str++)) - '0');
	return (result);
}
