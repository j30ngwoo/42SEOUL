/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:40:41 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/26 16:12:03 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ascending_sort_three(t_stacks_info *stacks, int which_stack)
{
	void	(*sx)(t_stacks_info *, int);
	void	(*rrx)(t_stacks_info *, int);
	t_stack	*stack;

	sx = set_sx(which_stack);
	rrx = set_rrx(which_stack);
	stack = set_stack(which_stack, stacks);
	if (stack->arr[stack->head]
		> stack->arr[increase_idx(stacks->n, stack->head)])
		sx(stacks, PRINT);
	if (stack->arr[increase_idx(stacks->n, stack->head)]
		> stack->arr[decrease_idx(stacks->n, stack->tail)])
		rrx(stacks, PRINT);
	if (stack->arr[stack->head]
		> stack->arr[increase_idx(stacks->n, stack->head)])
		sx(stacks, PRINT);
}

void	descending_sort_three(t_stacks_info *stacks, int which_stack)
{
	void	(*sx)(t_stacks_info *, int);
	void	(*rrx)(t_stacks_info *, int);
	t_stack	*stack;

	sx = set_sx(which_stack);
	rrx = set_rrx(which_stack);
	stack = set_stack(which_stack, stacks);
	if (stack->arr[stack->head]
		< stack->arr[increase_idx(stacks->n, stack->head)])
		sx(stacks, PRINT);
	if (stack->arr[increase_idx(stacks->n, stack->head)]
		< stack->arr[decrease_idx(stacks->n, stack->tail)])
		rrx(stacks, PRINT);
	if (stack->arr[stack->head]
		< stack->arr[increase_idx(stacks->n, stack->head)])
		sx(stacks, PRINT);
}

void	ascending_sort_two(t_stacks_info *stacks, int which_stack)
{
	int		next_of_head;
	void	(*sx)(t_stacks_info *, int);
	t_stack	*stack;

	sx = set_sx(which_stack);
	stack = set_stack(which_stack, stacks);
	next_of_head = increase_idx(stacks->n, stack->head);
	if (stack->arr[stack->head] > stack->arr[next_of_head])
		sx(stacks, PRINT);
}

void	descending_sort_two(t_stacks_info *stacks, int which_stack)
{
	int		next_of_head;
	void	(*sx)(t_stacks_info *, int);
	t_stack	*stack;

	sx = set_sx(which_stack);
	stack = set_stack(which_stack, stacks);
	next_of_head = increase_idx(stacks->n, stack->head);
	if (stack->arr[stack->head] < stack->arr[next_of_head])
		sx(stacks, PRINT);
}
