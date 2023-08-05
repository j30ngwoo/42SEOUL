/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_under_six.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:17:12 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/26 08:49:09 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	under_six_process(t_stacks_info *stacks)
{
	int	pivot;

	if (stacks->n == 2)
		ascending_sort_two(stacks, A);
	else if (stacks->n == 3)
		ascending_sort_three(stacks, A);
	else
	{
		pivot = stacks->temp[(stacks->n / 2 - 1)];
		divide_in_two(pivot, stacks);
		if (stacks->a.size == 2)
			ascending_sort_two(stacks, A);
		else if (stacks->a.size == 3)
			ascending_sort_three(stacks, A);
		if (stacks->a.size == 2)
			descending_sort_two(stacks, B);
		else if (stacks->a.size == 3)
			descending_sort_three(stacks, B);
		while (stacks->b.size > 0)
			pa(stacks, PRINT);
	}
}

void	divide_in_two(int pivot, t_stacks_info *stacks)
{
	int		i;
	t_stack	*a;

	a = &(stacks->a);
	i = 0;
	while (i < stacks->n)
	{
		if (a->arr[a->head] <= pivot)
			pb(stacks, PRINT);
		else
			ra(stacks, PRINT);
		i++;
	}
}

void	*set_sx(int which_stack)
{
	if (which_stack == A)
		return (sa);
	else
		return (sb);
}

void	*set_rrx(int which_stack)
{
	if (which_stack == A)
		return (rra);
	else
		return (rrb);
}

t_stack	*set_stack(int which_stack, t_stacks_info *stacks)
{
	if (which_stack == A)
		return (&(stacks->a));
	else
		return (&(stacks->b));
}
