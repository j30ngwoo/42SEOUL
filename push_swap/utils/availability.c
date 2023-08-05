/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   availability.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:24:20 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/20 19:29:45 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	check_arg_avail(char **split_av)
{
	int	i;

	i = 0;
	while (split_av[i])
	{
		if (!ft_is_str_int(split_av[i++]))
		{
			print_error();
			exit(1);
		}
	}
}

int	is_there_duplicates(int *arr, int arr_size)
{
	int	left;
	int	right;

	left = 0;
	while (left < arr_size - 1)
	{
		right = left + 1;
		while (right < arr_size)
			if (arr[left] == arr[right++])
				return (1);
		left++;
	}
	return (0);
}

int	is_stack_sorted(t_stack stack, int arr_max)
{
	int	i;

	i = 0;
	while (i++ < stack.size - 1)
	{
		if (stack.arr[stack.head]
			> stack.arr[increase_idx(arr_max, stack.head)])
			return (0);
		stack.head = increase_idx(arr_max, stack.head);
	}
	return (1);
}
