/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 03:29:13 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/03/31 20:55:57 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnstr(char *str, int len)
{
	int	i;

	if (str == 0)
		return (0);
	i = 0;
	while (i < len && str[i])
		if (ft_putchar(str[i++]) == -1)
			return (-1);
	return (0);
}
