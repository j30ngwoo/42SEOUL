/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:30:37 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/26 08:50:47 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_int_pair	find_two_pivots(t_stacks_info *stacks)
{
	t_int_pair	pivots;

	pivots.first = stacks->temp[stacks->n * 1 / 3];
	pivots.second = stacks->temp[stacks->n * 2 / 3];
	return (pivots);
}

void	quicksort(int arr_head, int arr_tail, int *arr, int arr_max)
{
	int	pivot;
	int	left;
	int	right;

	if (!(arr_head < arr_tail))
		return ;
	pivot = arr[arr_head];
	left = arr_head + 1;
	right = arr_tail;
	while (1)
	{
		while (left <= right && arr[left] <= pivot)
			left++;
		while (left <= right && pivot <= arr[right])
			right--;
		if (left > right)
			break ;
		ft_swap_int(&arr[left], &arr[right]);
	}
	ft_swap_int(&arr[arr_head], &arr[right]);
	quicksort(arr_head, right - 1, arr, arr_max);
	quicksort(right + 1, arr_tail, arr, arr_max);
}

void	divide_into_three(t_int_pair pivots, t_stacks_info *stacks)
{
	int	i;
	int	value;

	i = 0;
	while (i < stacks->n)
	{
		value = stacks->a.arr[stacks->a.head];
		if (value < pivots.first)
		{
			pb(stacks, PRINT);
			rb(stacks, PRINT);
		}
		else if (value < pivots.second)
			pb(stacks, PRINT);
		else
			ra(stacks, PRINT);
		i++;
	}
	while (stacks->a.size > 0)
		pb(stacks, PRINT);
}
