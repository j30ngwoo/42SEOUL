/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_over_six.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:51:39 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/26 08:49:30 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	over_six_process(t_stacks_info *stacks)
{
	t_oper_counter	min_opers;
	t_int_pair		pivots;

	pivots = find_two_pivots(stacks);
	divide_into_three(pivots, stacks);
	while (stacks->b.size > 0)
	{
		min_opers.total = INT_MAX;
		find_min_opers(stacks, &min_opers);
		exec_min_opers(min_opers, stacks);
	}
	last_rotate(stacks);
}

void	exec_min_opers(t_oper_counter min_opers, t_stacks_info *stacks)
{
	while (min_opers.rb-- > 0)
		rb(stacks, PRINT);
	while (min_opers.rrb-- > 0)
		rrb(stacks, PRINT);
	while (min_opers.ra-- > 0)
		ra(stacks, PRINT);
	while (min_opers.rra-- > 0)
		rra(stacks, PRINT);
	pa(stacks, PRINT);
}

void	last_rotate(t_stacks_info *stacks)
{
	int	ra_count;
	int	rra_count;
	int	min_value_index;

	min_value_index = min_value_index_in_stack(stacks->n, stacks->a);
	ra_count = length_from_head(min_value_index, stacks->n, stacks->a);
	rra_count = stacks->a.size - ra_count;
	if (ra_count <= rra_count)
		while (ra_count-- > 0)
			ra(stacks, PRINT);
	else
		while (rra_count-- > 0)
			rra(stacks, PRINT);
}
