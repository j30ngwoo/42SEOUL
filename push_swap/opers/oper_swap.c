/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:13:33 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/16 17:51:26 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opers.h"

void	sa(t_stacks_info *stacks, int is_print)
{
	int	x;
	int	y;

	if (stacks->a.size <= 1)
		return ;
	if (is_print)
		ft_putstr("sa\n");
	x = pop_front(stacks->n, &(stacks->a));
	y = pop_front(stacks->n, &(stacks->a));
	push_front(x, stacks->n, &(stacks->a));
	push_front(y, stacks->n, &(stacks->a));
}

void	sb(t_stacks_info *stacks, int is_print)
{
	int	x;
	int	y;

	if (stacks->b.size <= 1)
		return ;
	if (is_print)
		ft_putstr("sb\n");
	x = pop_front(stacks->n, &(stacks->b));
	y = pop_front(stacks->n, &(stacks->b));
	push_front(x, stacks->n, &(stacks->b));
	push_front(y, stacks->n, &(stacks->b));
}

void	ss(t_stacks_info *stacks, int is_print)
{
	if (is_print)
		ft_putstr("ss\n");
	sa(stacks, NO_PRINT);
	sb(stacks, NO_PRINT);
}
