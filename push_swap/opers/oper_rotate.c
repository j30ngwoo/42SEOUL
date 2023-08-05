/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:13:43 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/16 17:51:31 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opers.h"

void	ra(t_stacks_info *stacks, int is_print)
{
	int	value;

	if (is_print)
		ft_putstr("ra\n");
	value = pop_front(stacks->n, &(stacks->a));
	push_back(value, stacks->n, &(stacks->a));
}

void	rb(t_stacks_info *stacks, int is_print)
{
	int	value;

	if (is_print)
		ft_putstr("rb\n");
	value = pop_front(stacks->n, &(stacks->b));
	push_back(value, stacks->n, &(stacks->b));
}

void	rr(t_stacks_info *stacks, int is_print)
{
	if (is_print)
		ft_putstr("rr\n");
	ra(stacks, NO_PRINT);
	rb(stacks, NO_PRINT);
}
