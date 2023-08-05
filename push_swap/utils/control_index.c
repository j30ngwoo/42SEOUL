/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:59:13 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/17 20:57:53 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	increase_idx(int arr_max, int prev_idx)
{
	if (prev_idx >= arr_max - 1)
		return (0);
	else
		return (++prev_idx);
}

int	decrease_idx(int arr_max, int prev_idx)
{
	if (prev_idx <= 0)
		return (arr_max - 1);
	else
		return (--prev_idx);
}

int	length_from_head(int index, int arr_size, t_stack stack)
{
	if (stack.head <= index)
		return (index - stack.head);
	else
		return (index + arr_size - stack.head);
}

int	max_value_index_in_stack(int arr_max, t_stack stack)
{
	int	search_index;
	int	max_index;

	max_index = stack.head;
	search_index = increase_idx(arr_max, stack.head);
	while (search_index != stack.tail)
	{
		if (stack.arr[max_index] < stack.arr[search_index])
			max_index = search_index;
		search_index = increase_idx(arr_max, search_index);
	}
	return (max_index);
}

int	min_value_index_in_stack(int arr_max, t_stack stack)
{
	int	search_index;
	int	min_index;

	min_index = stack.head;
	search_index = increase_idx(arr_max, stack.head);
	while (search_index != stack.tail)
	{
		if (stack.arr[search_index] < stack.arr[min_index])
			min_index = search_index;
		search_index = increase_idx(arr_max, search_index);
	}
	return (min_index);
}
