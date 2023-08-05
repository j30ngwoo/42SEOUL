/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:13:28 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/16 17:51:35 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opers.h"

void	pa(t_stacks_info *stacks, int is_print)
{
	int	value;

	if (stacks->b.size == 0)
		return ;
	if (is_print)
		ft_putstr("pa\n");
	value = pop_front(stacks->n, &(stacks->b));
	push_front(value, stacks->n, &(stacks->a));
}

void	pb(t_stacks_info *stacks, int is_print)
{
	int	value;

	if (stacks->a.size == 0)
		return ;
	if (is_print)
		ft_putstr("pb\n");
	value = pop_front(stacks->n, &(stacks->a));
	push_front(value, stacks->n, &(stacks->b));
}
