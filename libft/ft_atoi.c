/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:47:24 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/04/09 16:47:26 by jeongwoo         ###   ########.fr       */
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
