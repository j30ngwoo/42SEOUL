/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:12:41 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/18 09:16:34 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	print_error(void)
{
	ft_putstr("Error\n");
	return (1);
}

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

int	free_stacks(t_stacks_info stacks)
{
	if (stacks.a.arr != NULL)
		free(stacks.a.arr);
	if (stacks.b.arr != NULL)
		free(stacks.b.arr);
	if (stacks.temp != NULL)
		free(stacks.temp);
	return (0);
}
