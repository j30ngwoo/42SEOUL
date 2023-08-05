/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_oper_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:41:48 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/18 11:27:36 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	exec_oper(t_stacks_info *stacks)
{
	char	*oper;

	while (1)
	{
		oper = get_next_line(0);
		if (oper == NULL)
			return (1);
		if (!ft_strcmp(oper, "sa\n") || !ft_strcmp(oper, "sb\n")
			|| !ft_strcmp(oper, "ss\n"))
			exec_sx(oper, stacks);
		else if (!ft_strcmp(oper, "pa\n") || !ft_strcmp(oper, "pb\n"))
			exec_px(oper, stacks);
		else if (!ft_strcmp(oper, "ra\n") || !ft_strcmp(oper, "rb\n")
			|| !ft_strcmp(oper, "rr\n"))
			exec_rx(oper, stacks);
		else if (!ft_strcmp(oper, "rra\n") || !ft_strcmp(oper, "rrb\n")
			|| !ft_strcmp(oper, "rrr\n"))
			exec_rrx(oper, stacks);
		else
			return (0);
	}
	return (1);
}

void	exec_sx(char *oper, t_stacks_info *stacks)
{
	if (!ft_strcmp(oper, "sa\n"))
		sa(stacks, NO_PRINT);
	if (!ft_strcmp(oper, "sb\n"))
		sb(stacks, NO_PRINT);
	if (!ft_strcmp(oper, "ss\n"))
		ss(stacks, NO_PRINT);
}

void	exec_px(char *oper, t_stacks_info *stacks)
{
	if (!ft_strcmp(oper, "pa\n"))
		pa(stacks, NO_PRINT);
	if (!ft_strcmp(oper, "pb\n"))
		pb(stacks, NO_PRINT);
}

void	exec_rx(char *oper, t_stacks_info *stacks)
{
	if (!ft_strcmp(oper, "ra\n"))
		ra(stacks, NO_PRINT);
	if (!ft_strcmp(oper, "rb\n"))
		rb(stacks, NO_PRINT);
	if (!ft_strcmp(oper, "rr\n"))
		rr(stacks, NO_PRINT);
}

void	exec_rrx(char *oper, t_stacks_info *stacks)
{
	if (!ft_strcmp(oper, "rra\n"))
		rra(stacks, NO_PRINT);
	if (!ft_strcmp(oper, "rrb\n"))
		rrb(stacks, NO_PRINT);
	if (!ft_strcmp(oper, "rrr\n"))
		rrr(stacks, NO_PRINT);
}
