/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:19:15 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/16 17:51:32 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opers.h"

void	rra(t_stacks_info *stacks, int is_print)
{
	int	value;

	if (is_print)
		ft_putstr("rra\n");
	value = pop_back(stacks->n, &(stacks->a));
	push_front(value, stacks->n, &(stacks->a));
}

void	rrb(t_stacks_info *stacks, int is_print)
{
	int	value;

	if (is_print)
		ft_putstr("rrb\n");
	value = pop_back(stacks->n, &(stacks->b));
	push_front(value, stacks->n, &(stacks->b));
}

void	rrr(t_stacks_info *stacks, int is_print)
{
	if (is_print)
		ft_putstr("rrr\n");
	rra(stacks, NO_PRINT);
	rrb(stacks, NO_PRINT);
}
