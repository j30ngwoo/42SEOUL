/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_min_opers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:42:01 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/26 17:24:11 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_opers(t_stacks_info *stacks, t_oper_counter *min_opers)
{
	t_oper_counter	temp_opers;
	int				b_index;

	b_index = stacks->b.head;
	while (1)
	{
		temp_opers.total = 0;
		find_current_rb_rrb(b_index, stacks, &temp_opers);
		find_current_ra_rra(stacks->b.arr[b_index], stacks, &temp_opers);
		if (temp_opers.total < min_opers->total)
			*min_opers = temp_opers;
		b_index = increase_idx(stacks->n, b_index);
		if (b_index == stacks->b.tail)
			break ;
	}
}

void	find_current_rb_rrb(int idx,
	t_stacks_info *stacks, t_oper_counter *temp_opers)
{
	temp_opers->rb = length_from_head(idx, stacks->n, stacks->b);
	temp_opers->rrb = stacks->b.size - temp_opers->rb;
	if (temp_opers->rb <= temp_opers->rrb)
		temp_opers->rrb = 0;
	else
		temp_opers->rb = 0;
	temp_opers->total += temp_opers->rb + temp_opers->rrb;
}

void	find_current_ra_rra(int val,
	t_stacks_info *stacks, t_oper_counter *temp_opers)
{
	int	max_index;

	max_index = max_value_index_in_stack(stacks->n, stacks->a);
	if (stacks->a.size > 0 && val > stacks->a.arr[max_index])
		temp_opers->ra = length_from_head(
				increase_idx(stacks->n, max_index), stacks->n, stacks->a);
	else
		find_current_ra(val, stacks, temp_opers);
	temp_opers->rra = stacks->a.size - temp_opers->ra;
	if (temp_opers->ra <= temp_opers->rra)
		temp_opers->rra = 0;
	else
		temp_opers->ra = 0;
	temp_opers->total += temp_opers->ra + temp_opers->rra;
}

void	find_current_ra(int val,
	t_stacks_info *stacks, t_oper_counter *temp_opers)
{
	int	search_idx;
	int	target_idx;

	target_idx = -1;
	search_idx = stacks->a.head;
	while (search_idx != stacks->a.tail)
	{
		if (val < stacks->a.arr[search_idx]
			&& (target_idx == -1
				|| stacks->a.arr[search_idx] < stacks->a.arr[target_idx]))
			target_idx = search_idx;
		search_idx = increase_idx(stacks->n, search_idx);
	}
	temp_opers->ra = length_from_head(target_idx, stacks->n, stacks->a);
}
